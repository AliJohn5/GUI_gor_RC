#include "ros/ros.h"
#include "std_msgs/String.h"
#include <opencv4/opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include <sstream>
#include <iostream>



using namespace cv;
using namespace std;


int main(int argc, char **argv)
{
/********************************************************************
*                                                                   *
*  [[534.700827     0.         298.69428531]                        *
*  [  0.         538.68726057 241.95964821]                         *
*  [  0.           0.           1.        ]]                        *
*  Distortion coefficients:                                         *
*    [[ 0.26141142 -0.89287148 -0.01289938 -0.00444268  1.06370115]]*
*********************************************************************/

  ros::init(argc, argv, "talker");
  ros::NodeHandle n("~");
  ros::Publisher pub = n.advertise<sensor_msgs::Image>("frame", 1);

  VideoCapture cap(0);
  if (!cap.isOpened())
  {
      ROS_ERROR("Failed to open camera");
      return -1;
  }

  ros::Rate loop_rate(30);
  while (ros::ok())
  {
     cv::Mat intrinsic_matrix = (cv::Mat_<double>(3, 3) << 534.700827,0.,298.69428531,
                                                           0.,538.68726057,241.95964821,
                                                           0.,0.,1.);
      cv::Mat distortion_coeffs = (cv::Mat_<double>(1, 5) << 0.26141142,-0.89287148 ,-0.01289938,-0.00444268,1.06370115);
      Mat frame;
      cap >> frame;
      if (frame.empty())
      {
          ROS_WARN("Received an empty frame from camera");
          continue;
      }

      // Convert the OpenCV image to ROS message
      //Mat mirrored_image;
      flip(frame, frame, 1);

      cv::Mat undistorted_img;
      cv::undistort(frame, undistorted_img, intrinsic_matrix, distortion_coeffs);
      sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();

      // Publish the ROS message
      pub.publish(msg);

      ros::spinOnce();
      loop_rate.sleep();
  }

  return 0;
}
