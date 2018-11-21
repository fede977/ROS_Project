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
std::vector<Node*> path;
std::vector<geometry_msgs::Point> points;
nav_msgs::Odometry actualPos;
int xVel = 0, zVel = 0;

double euclid(geometry_msgs::Point goal, nav_msgs::Odometry actualPos){

        double distX = goal.x - actualPos.pose.pose.position.x;
        double distY = goal.y - actualPos.pose.pose.position.y;

        double distance = distX*distX + distY*distY;
        distance = sqrt(distance);

    return distance;

}

double toEulerAngle(float x, float y, float z, float w){
    double roll;

    double sin_cosp = 2.0 * (w * x + y * z);
    double cos_cosp = 1.0 - 2.0 * (x * x + y * y);
    roll = atan2(sin_cosp, cos_cosp);

    

}

void MoveRobot(double distTollerance){
    geometry_msgs::Twist mv;
    tf::Pose pose;
    tf::poseMsgToTF(actualPos.pose.pose, pose);
    double yaw_angle = tf::getYaw(pose.getRotation());
    for(int i = points.size()-2; i>0; i--){
        geometry_msgs::Point goal = points[i];
        std::cout << goal.x << " , " << goal.y<<std::endl;
        ros::Rate loop(2.0);
        do{
            //velocity x-axis
            mv.linear.x = 1.5 * euclid(goal, actualPos);

            //velocity angular
            mv.angular.z = 0.5 * (atan2(goal.y-actualPos.pose.pose.position.y, goal.x-actualPos.pose.pose.position.x))-toEulerAngle(actualPos.pose.pose.orientation.x,actualPos.pose.pose.orientation.y,actualPos.pose.pose.orientation.z,actualPos.pose.pose.orientation.w);
            rviz.publish(mv);

            ros::spinOnce();
            loop.sleep();
        }while(euclid(goal,actualPos)>distTollerance);
        std::cout << "end move" << std::endl;
        mv.linear.x = 0;
        mv.angular.z = 0;
        rviz.publish(mv);
    }
}

void getPath(visualization_msgs::Marker msg){
    
    points = msg.points;
    
}

void getPos(nav_msgs::Odometry Pos){
    actualPos = Pos;
}

int main(int argc, char**argv){
    ros::init(argc, argv, "task3");
    ros::NodeHandle n;
    
    ros::Subscriber p = n.subscribe("/visPath", 10, &getPath);
    ros::spinOnce();
    rviz = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Rate r(1.0);
    while(ros::ok()){
        ros::Subscriber pose = n.subscribe("/base_pose_ground_truth", 10, &getPos);
        MoveRobot(0.1);
        ros::spinOnce();
        r.sleep();
    }
    return 0;
}