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
/*
 *
 * down camera
 *
 * */

  ros::init(argc, argv, "talker");
  ros::NodeHandle n("~");
  ros::Publisher pub = n.advertise<sensor_msgs::Image>("frame", 1);

  VideoCapture cap(0);
  if (!cap.isOpened())
  {
      ROS_ERROR("Failed to open camera");
      return -1;
  }

  ros::Rate loop_rate(100);
  while (ros::ok())
  {
     cv::Mat intrinsic_matrix = (cv::Mat_<double>(3, 3) << 526.36242209  , 0.       ,  301.72803301,
                                                           0.,525.22844252 ,255.19490125,
                                                           0.,0.,1.);
      cv::Mat distortion_coeffs = (cv::Mat_<double>(1, 5) << 0.2645315 , -1.02914488 ,-0.0024316 , -0.00373515 , 1.4652433);
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
