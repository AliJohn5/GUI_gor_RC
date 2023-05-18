#ifndef NAMESPACEALI_H
#define NAMESPACEALI_H


#include <opencv4/opencv2/opencv.hpp>
#include <QLabel>

namespace  ali{

static int from_camera;
static cv::Mat image;
static cv::Mat image2;

static int num_of_cols = 480;
static int num_of_raws = 640;


static int x_center = 0;
static int y_center = 0;

static int main_x1 = 340;
static int main_y1 = 315;


static int main_x2 = 307;
static int main_y2 = 432;

static bool camera_is_on = false;
static bool camera_is_on_1 = false;

static double_t dist1 = 0;
static double_t dist2 = 0;

static double_t factor2 = 0.8;


static QLabel* lab;
static QLabel* lab2;

// thetas after linear regression
//theta = [[9.35712464 0.16450064 1.71972981]]

static double theta0 = 9.35712464;
static double theta1 = 0.16450064;
static double theta2 = 1.71972981;

static int cameraIndix1 = 2;
static int cameraIndix2 = 3;

}

#endif // NAMESPACEALI_H
