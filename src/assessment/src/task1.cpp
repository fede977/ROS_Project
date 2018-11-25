#include<ros/ros.h>
#include<tf/transform_broadcaster.h>
#include<nav_msgs/Odometry.h>
#include<visualization_msgs/Marker.h>
#include<nav_msgs/Path.h>


ros::Publisher rviz;
double defaultX = -4.8;
double defaultY = -3.6;


void actualPos(nav_msgs::Odometry odom){
    visualization_msgs::Marker mark;
    nav_msgs::Path path;

    mark.header.frame_id = "/map";
    mark.id = 0;
    mark.ns = "actualPosition";
    mark.type = visualization_msgs::Marker::ARROW;
    mark.action = visualization_msgs::Marker::ADD;
    mark.pose.position.x = odom.pose.pose.position.x;
    mark.pose.position.y = odom.pose.pose.position.y;
    mark.pose.orientation = odom.pose.pose.orientation;
    mark.scale.x = 0.5;
    mark.scale.y = 0.2;
    mark.scale.z = 0.1;
    mark.color.r = 255.0;
    mark.color.a = 1.0;

    rviz.publish(mark);
}

void robotOdom(nav_msgs::Odometry odom){

    visualization_msgs::Marker mark2;

    mark2.header.frame_id = "/map";
    mark2.id = 1;
    mark2.ns = "Odometry";
    mark2.type = visualization_msgs::Marker::ARROW;
    mark2.action = visualization_msgs::Marker::ADD;
    mark2.pose.position.x = odom.pose.pose.position.x + defaultX;
    mark2.pose.position.y = odom.pose.pose.position.y + defaultY;
    mark2.pose.orientation = odom.pose.pose.orientation;
    mark2.scale.x = 0.5;
    mark2.scale.y = 0.2;
    mark2.scale.z = 0.1;
    mark2.color.g = 255.0;
    mark2.color.a = 1.0;

    
    rviz.publish(mark2);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "task1");

    ros::NodeHandle n;
    rviz = n.advertise<visualization_msgs::Marker>("/real_robot_pose", 10);
    ros::Subscriber sub = n.subscribe("/base_pose_ground_truth", 10, &actualPos);
    ros::Subscriber sub2 = n.subscribe("/odom", 10, &robotOdom);

    ros::spin();


    return 0;
}
