#include <ros/ros.h>
#include <stdlib.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>
#include <opencv2/core/version.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>


cv_bridge::CvImage out;
void imagecb(const sensor_msgs::Image& img){
    cv_bridge::CvImagePtr cv_ptr;
    cv::Mat img_rgb;
    cv_ptr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);
    img_rgb = cv_ptr->image;

    out.header = cv_ptr->header;
    out.encoding = "bgr8";
    out.header.stamp=ros::Time::now();
    out.image = img_rgb;
    cv::imshow("Image Window", out.image);
    cv::waitKey(10);
}




int main(int argc, char**argv)
{
    ros::init(argc, argv, "task5");

    ros::NodeHandle n;
    ros::Subscriber img_sub = n.subscribe("/image", 1, &imagecb);
    ros::Publisher img_pub = n.advertise<sensor_msgs::Image>("/imageOut", 2);
    
    ros::Rate r(2.0);
    while(ros::ok()){

        img_pub.publish(out.toImageMsg());

        ros::spinOnce();
        r.sleep();
    }






    return 0;
}
