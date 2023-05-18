
#include<ros/ros.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <libfreenect.h>
#include <pthread.h>
#define CV_NO_BACKWARD_COMPATIBILITY
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <libfreenect.h>
#include <image_transport/image_transport.h>
#include<cv_bridge/cv_bridge.h>
#include "sensor_msgs/Image.h"
#define FREENECT_FRAME_H 480
#define FREENECT_FRAME_W 640

using namespace std;
using namespace cv;

//freenect_device *device;
freenect_device *device;
image_transport::Publisher pub_rgb;
ros::Publisher pub_depth;

void rgb_callback(freenect_device *dev, void *rgb, uint32_t timestamp)
{
    // Convert the RGB data to an OpenCV image
   uint8_t *rgb_data = (uint8_t *)rgb;
    Mat rgb_image(FREENECT_FRAME_H, FREENECT_FRAME_W, CV_8UC3, rgb_data);
    cvtColor(rgb_image, rgb_image, COLOR_RGB2BGR);

    // Create an image message and publish it to the RGB topic
    sensor_msgs::ImagePtr rgb_msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", rgb_image).toImageMsg();
    pub_rgb.publish(rgb_msg);
}

void depth_callback(freenect_device *dev, void *depth, uint32_t timestamp)
{
    // Convert the depth data to an OpenCV image
  // uint16_t *depth_data = (uint16_t *)depth;
   //printf("%d\n",depth_data[200*200]);
  // Mat depth_image(FREENECT_FRAME_H, FREENECT_FRAME_W, CV_16UC1, depth_data);

    //ROS_INFO("%f\n",depth_image.at<float>(200,100));

    // Normalize the depth values for display
   // depth_image.convertTo(depth_image, CV_8UC1,  255.0 / 2048.0);

    // Create an image message and publish it to the depth topic


   sensor_msgs::Image depth_msg;
     depth_msg.header.frame_id = "depth_camera";
     depth_msg.encoding = sensor_msgs::image_encodings::TYPE_16UC1;
     depth_msg.height = 480;
     depth_msg.width = 640;
     depth_msg.step = depth_msg.width * sizeof(uint16_t);
     depth_msg.data.resize(depth_msg.height * depth_msg.step);

     // Populate the depth message with the depth data
     uint16_t *depth_data = (uint16_t *)depth;
     memcpy(&depth_msg.data[0], depth_data, depth_msg.height * depth_msg.step);

  //  sensor_msgs::ImagePtr depth_msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", depth_image).toImageMsg();
    pub_depth.publish(depth_msg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "kinect_publisher");
    ros::NodeHandle nh;

    // Create image transport objects for the two topics
    image_transport::ImageTransport it(nh);
    pub_rgb = it.advertise("rgb_image", 1);
    pub_depth = nh.advertise<sensor_msgs::Image>("depth_image", 1000);


    // Initialize the libfreenect library

    freenect_context *context;
    if (freenect_init(&context, NULL) < 0) {
        printf("Failed to initialize libfreenect\n");
        exit(1);
    }

    // Find the first connected Kinect device
    if (freenect_open_device(context, &device, 0) < 0) {
        printf("Failed to open Kinect device\n");
        exit(1);
    }

    // Set the RGB and depth modes to medium resolution
   /* freenect_frame_mode rgb_mode = freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB);
    freenect_set_video_mode(device, rgb_mode);
    freenect_frame_mode depth_mode = freenect_find_depth_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_DEPTH_MM);
    freenect_set_depth_mode(device, depth_mode);
*/
    // Start streaming RGB and depth data from the sensor
    freenect_set_video_callback(device, rgb_callback);
    freenect_set_depth_callback(device, depth_callback);

    freenect_set_depth_mode(device, freenect_find_depth_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_DEPTH_MM));
    freenect_set_video_mode(device, freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB));

    freenect_start_video(device);
    freenect_start_depth(device);

    // Run the ROS main loop
    ros::Rate loop_rate(100);
    while (ros::ok())
    {
        freenect_process_events(context);

        ros::spinOnce();
        loop_rate.sleep();
    }

    // Stop streaming RGB and depth data and close the device
    freenect_stop_video(device);
    freenect_stop_depth(device);
    freenect_close_device(device);

    // Shutdown the libfreenect library
    freenect_shutdown(context);

    return 0;
}
