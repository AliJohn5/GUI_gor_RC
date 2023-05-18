#include "ros/ros.h"
#include "std_msgs/String.h"
#include <opencv4/opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include <sstream>
#include <iostream>



using namespace cv;
using namespace std;
/****
 *
 *
 * upove camera
 *
 *
 * */

int main(int argc, char **argv)
{

  int indix = 3;
  if (argc==2) indix = atoi(argv[1]);
  ros::init(argc, argv, "frame2");
  ros::NodeHandle n("~");
  ros::Publisher pub = n.advertise<sensor_msgs::Image>("frame2", 1);

  VideoCapture cap(indix);
  if (!cap.isOpened())
  {
      ROS_ERROR("Failed to open camera");
      return -1;
  }

  ros::Rate loop_rate(100);
  while (ros::ok())
  {
     cv::Mat intrinsic_matrix = (cv::Mat_<double>(3, 3) << 541.17268172,0.,328.035879,
                                                           0.,538.2898383,247.09274515,
                                                           0.,0.,1.);
      cv::Mat distortion_coeffs = (cv::Mat_<double>(1, 5) << 0.20860047,-0.63745467,-0.00964124,0.00206615,0.6594531);

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
