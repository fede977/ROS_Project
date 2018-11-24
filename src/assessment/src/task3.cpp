#include <ros/ros.h>
#include <stdlib.h>
#include <geometry_msgs/Twist.h>
#include <visualization_msgs/Marker.h>
#include <tf/transform_listener.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Point.h>
#include <cmath>
#include "t2.h"

ros::Publisher rviz;
std::vector<geometry_msgs::Point> points;
nav_msgs::Odometry actualPos;
geometry_msgs::Point goal;
int i;

double euclid(geometry_msgs::Point goal, nav_msgs::Odometry actualPos){

        double distX = goal.x - actualPos.pose.pose.position.x;
        double distY = goal.y - actualPos.pose.pose.position.y;

        double distance = distX*distX + distY*distY;
        distance = sqrt(distance);

    return distance;
}

double toEulerAngle(double x, double y, double z, double w){
    double yaw;

    double sin_cosp = 2.0 * (w * z + y * x);
    double cos_cosp = 1.0 - 2.0 * (z * z + y * y);
    yaw = atan2(sin_cosp, cos_cosp);
    return yaw;
}


void MoveRobot(double distTollerance){
    geometry_msgs::Twist mv;
    std::cout << goal.x << " , " << goal.y<<std::endl;

    if(euclid(goal,actualPos)>=distTollerance){
        double theta, angx, angy, goal_angle;
        angx = goal.x - actualPos.pose.pose.position.x;
        angy = goal.y - actualPos.pose.pose.position.y;
        theta = toEulerAngle(actualPos.pose.pose.orientation.x,actualPos.pose.pose.orientation.y,actualPos.pose.pose.orientation.z,actualPos.pose.pose.orientation.w);
        goal_angle = atan2(angy,angx);
        if(abs(theta-goal_angle)>0.05){
            //velocity angular
            mv.angular.x = 0.0;
            mv.angular.y = 0.0;
            mv.angular.z = 4 * (goal_angle-theta);
        }else{
            //velocity x-axis
            mv.linear.x = 3 * euclid(goal,actualPos);
            mv.linear.y = 0.0;
            mv.linear.z = 0.0;
        }   
        rviz.publish(mv);
        
    }else{
        std::cout << "end move" << std::endl;
        mv.linear.x = 0.0;
        mv.angular.z = 0.0;
        rviz.publish(mv);
    }
}

void getPath(visualization_msgs::Marker msg){
    if(points.empty()){
        points = msg.points;
        i = points.size()-1;
    }else{
        goal = points[i];
        std::cout << points[i].x <<std::endl;
        i-=1;
    }
    
}

void getPos(nav_msgs::Odometry Pos){
    actualPos = Pos;
}

int main(int argc, char**argv){
    ros::init(argc, argv, "task3");
    ros::NodeHandle n;
    ros::Subscriber p = n.subscribe("/visPath", 10, &getPath);
    ros::spinOnce();
    ros::Subscriber pose = n.subscribe("/base_pose_ground_truth", 10, &getPos);
    rviz = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Rate r(100.0);

    while(ros::ok()){
        std::cout<<goal.x <<std::endl;
        MoveRobot(0.01);
        if(!points.empty()){
            if(goal.x==points[0].x && goal.y == points[0].y){
                break;
            }
        }
        ros::spinOnce();
        r.sleep();
    }

    return 0;
}