#include "ros/ros.h"
#include "std_msgs/String.h"
#include<opencv4/opencv2/opencv.hpp>

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("hi");
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  ROS_INFO("hi");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");


  ros::NodeHandle n("a");

  ros::Subscriber sub = n.subscribe("/talker/chatter", 1000, chatterCallback);


  ros::spin();

  return 0;
}
