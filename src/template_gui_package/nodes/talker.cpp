#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
  // Initialize the ROS node
  ros::init(argc, argv, "twist_publisher");

  // Create a ROS node handle
  ros::NodeHandle nh;

  // Create a publisher for the twist message on the "/cmd_vel" topic
  ros::Publisher twist_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

  // Create a twist message
  geometry_msgs::Twist twist_msg;
  twist_msg.linear.x = 1.0; // Set the linear velocity in the x direction to 1.0 m/s
  twist_msg.angular.z = 0.5; // Set the angular velocity around the z axis to 0.5 rad/s

  // Publish the twist message at 10 Hz
  ros::Rate rate(10);
  while (ros::ok())
  {
    twist_pub.publish(twist_msg);
    rate.sleep();
  }

  return 0;
}
