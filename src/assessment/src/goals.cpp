#include <ros/ros.h>
#include <stdlib.h>
#include <visualization_msgs/Marker.h>



int main(int argc, char **argv){
    ros::init(argc, argv, "goals");
    
    ros::NodeHandle n;
    ros::Publisher rviz = n.advertise<visualization_msgs::Marker>("/Goals", 20);
    
    ros::Rate r(2.0);
    visualization_msgs::Marker g0,g1,g2,g3,g4;
    g0.header.frame_id = g1.header.frame_id = g2.header.frame_id = g3.header.frame_id = g4.header.frame_id = "/map";
    g0.header.stamp = g1.header.stamp = g2.header.stamp = g3.header.stamp = g4.header.stamp = ros::Time::now();
    g0.id = 0;
    g1.id = 1;
    g2.id = 2;
    g3.id = 3;
    g4.id = 4;
    g0.ns = "goal0";
    g1.ns = "goal1";
    g2.ns = "goal2";
    g3.ns = "goal3";
    g4.ns = "goal4";
    g0.type = g1.type = g2.type = g3.type = g4.type = visualization_msgs::Marker::SPHERE;
    g0.action = g1.action = g2.action = g3.action = g4.action = visualization_msgs::Marker::ADD;
    g0.pose.orientation.w = g1.pose.orientation.w = g2.pose.orientation.w = g3.pose.orientation.w = g4.pose.orientation.w = 1.0;
    g0.scale.x = g1.scale.x = g2.scale.x = g3.scale.x = g4.scale.x = 0.3;
    g0.scale.y = g1.scale.y = g2.scale.y = g3.scale.y = g4.scale.y = 0.3;
    g0.scale.z = g1.scale.z = g2.scale.z = g3.scale.z = g4.scale.z = 0.2;
    g0.color.b= g1.color.b = g2.color.b = g3.color.b = g4.color.b = 1.0;
    g0.color.a = g1.color.a = g2.color.a = g3.color.a = g4.color.a = 1.0;
    g0.pose.position.x = -2;
    g1.pose.position.x = 2.5;
    g2.pose.position.x = -2.55;
    g3.pose.position.x = 4.5;
    g4.pose.position.x = 5.15;

    g0.pose.position.y = -2;
    g1.pose.position.y = -4.15;
    g2.pose.position.y = 3.13;
    g3.pose.position.y = -3.5;
    g4.pose.position.y = 2;

    g0.pose.position.z = g1.pose.position.z = g2.pose.position.z = g3.pose.position.z = g4.pose.position.z = 0.0;
    
    while(ros::ok()){
        rviz.publish(g0);
        rviz.publish(g1);
        rviz.publish(g2);
        rviz.publish(g3);
        rviz.publish(g4);
        
        ros::spinOnce();
        r.sleep();
    }
    
    
    return 0;
}