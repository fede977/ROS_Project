#include <ros/ros.h>
#include <stdlib.h>
#include <nav_msgs/MapMetaData.h>
#include <nav_msgs/OccupancyGrid.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Path.h>
#include <std_msgs/String.h>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <iostream>
#include "t2.h"

std_msgs::Header header;
nav_msgs::MapMetaData info;
std::vector<signed char> data;
ros::Publisher rviz;

int rob = 4;
int** grid;
std::vector<Node*> path;
std::vector<double> goal;
std::vector<double> start;


bool checkNode(Node *node){
/*     int index = node->x + info.width * node->y;

    if(index > data.size() || index < 0){
        std::cerr << "Index out of bounds!\n";
    }

    if(data[index] == 100 || data[index] == -1){
        return false;
    }else if(data[index] == 0){
        return true;
    } */
    
    if((node->x - rob)<0 || (node->x + rob)>=info.width || (node->y - rob) < 0 || (node->y + rob) >= info.height){
        return false;
    }

    for(int x = node->x-rob; x<= node->x+rob; x++){
        for(int y = node->y-rob; y<= node->y+rob; y++){
            if(grid[x][y] != 0){
                return false;
            }
        }
    }
    return true;
}

double euclideanDist(Node *a, Node *b){
    int distX = a->x - b->x;
    int distY = a->y - b->y;
    double distance;

    distance = distX*distX + distY*distY;
    distance = sqrt(distance);

    return distance;
}

visualization_msgs::Marker p;
nav_msgs::Path pt;
void visualization(){

    pt.header.frame_id = p.header.frame_id = "/map";
    p.header.stamp = ros::Time::now();
    p.id = 0;
    p.ns = "PathVis";
    p.type = visualization_msgs::Marker::LINE_STRIP;
    p.action = visualization_msgs::Marker::ADD;
    p.pose.orientation.w = 1.0;
    p.scale.x = 0.1;
    p.color.b = 1.0;
    p.color.a = 1.0;

    geometry_msgs::Point po;
    geometry_msgs::PoseStamped pose;
    for(int i = 0; i< path.size(); i++){
        pose.pose.position.x = po.x = (path[i]->x * 0.012) + info.origin.position.x;
        pose.pose.position.y = po.y = (path[i]->y * 0.012) + info.origin.position.y;
        pose.pose.position.z = po.z = 0.0;
        pose.pose.orientation.w = 1.0;
        p.points.push_back(po);
        pt.poses.push_back(pose);
    }

}


void Astar(std::vector<double> start, std::vector<double> goal){
    Node start_, goal_;

    start_.x = (start[0] - info.origin.position.x)/0.012;
    start_.y = (start[1] - info.origin.position.y)/0.012;
    start_.costSoFar = 0.0;
    start_.distance = euclideanDist(&start_, &goal_);
    
    goal_.x = (goal[0] - info.origin.position.x)/0.012;
    goal_.y = (goal[1] - info.origin.position.y)/0.012;
    goal_.costSoFar= 0.0;
    goal_.distance = 0.0;


    auto cmp = [](Node *a, Node *b){
        double aCost = a->costSoFar*5 + a->distance;
        double bCost = b->costSoFar*5 + b->distance;
        return aCost > bCost;
    };

    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> open_nodes(cmp);
    std::unordered_map<int, Node*> closed_nodes;

    open_nodes.push(&start_);
    Node *current;

    while(!open_nodes.empty()){
        current = open_nodes.top();
        open_nodes.pop();

        if(current->x == goal_.x && current->y == goal_.y){
            std::cout << "Done! " << std::endl;
            path.push_back(current);
            break;
        }

        for(int y = -1; y <= 1; y++){
            for(int x = -1; x <= 1 ; x++){
                Node *neighbour = (new Node);
                neighbour->x = current->x - x;
                neighbour->y = current->y - y;

                if(neighbour->x > info.width || neighbour->y > info.height){
                    continue;
                }else if(neighbour->x < 0 || neighbour->y < 0){
                    continue;
                }else if(neighbour->x == current->x && neighbour->y == current->y){
                    continue;
                }

                if(checkNode(neighbour)){
                    neighbour->distance = euclideanDist(neighbour, &goal_);
                    neighbour->costSoFar = current->costSoFar + euclideanDist(neighbour, current); 
                    int index = neighbour->x + info.width * neighbour->y;
                    
                    //if you can't find index in closed nodes;
                    if(closed_nodes.find(index) == closed_nodes.end()){
                        neighbour->previous = current;
                        closed_nodes.emplace(index, current);
                        open_nodes.push(neighbour);
                    }
                }else{
                    continue;
                }
            }
        }
    }
    
    while(true){
        if(path.back()->previous == NULL){
            break;
        }
        path.push_back(path.back()->previous);
    }
    visualization();
}

void mapCallback(nav_msgs::OccupancyGrid msg){
    header = msg.header;
    info = msg.info;
    data = msg.data;

    grid = new int*[info.width];
    for(int i = 0; i<info.width; i++){
        grid[i] = new int[info.height];
    }

    for(int x = 0; x<info.width-1; x++){
        for(int y = 0; y<info.height-1; y++){
            grid[x][y] = data[x+info.width*y];
        }
    }
    Astar(start, goal);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "t2");
    ros::NodeHandle n;
    n.getParam("robot_start", start);
    n.getParam("goal4", goal);
    ros::Subscriber Map = n.subscribe("/map", 10, &mapCallback);
    ros::spinOnce();
    ros::Publisher rviz = n.advertise<visualization_msgs::Marker>("/visPath", 20);
    ros::Publisher rvizPath = n.advertise<nav_msgs::Path>("/Path", 20);
    ros::Rate r(2.0);

    while(ros::ok()){
        rviz.publish(p);
        rvizPath.publish(pt);
        ros::spinOnce();
        r.sleep();
    }

    return 0;
}