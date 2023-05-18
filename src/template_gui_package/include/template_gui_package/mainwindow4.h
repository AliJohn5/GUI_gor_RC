#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H



#ifndef all_lib
#define all_lib
#include <QMainWindow>
#include <QtGui>
#include <ros/ros.h>
#include <QTimer>
#include <std_msgs/String.h>
#include <opencv4/opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include<QMouseEvent>
#include<QPixmap>
#include<QImage>
#include<QDebug>
#include <QCloseEvent>
#include<event.h>
#include <vector>
#include<math.h>
#include<QLabel>
#include "namespaceali.h"
#endif


#include <stdio.h>
#include <stdlib.h>
#include <libfreenect.h>

#define FREENECT_FRAME_H 480
#define FREENECT_FRAME_W 640


using std::vector;

using namespace cv;
using namespace std;

/*
namespace  ali{

static int from_camera;
static Mat image;
static Mat image2;

static int num_of_cols = 640;
static int num_of_raws = 480;


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

}*/



namespace Ui {
class MainWindow4;
}

class MainWindow4 : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow4(QWidget *parent = nullptr);
  ~MainWindow4();

  void imageCallback(const sensor_msgs::Image::ConstPtr& msg);
  void imageCallback1(const sensor_msgs::Image::ConstPtr& msg);

  void RGBcallback(const sensor_msgs::Image::ConstPtr& msg);
  void DEPcallback(const sensor_msgs::Image::ConstPtr& msg);

  int cam1 = 2;
  int cam2 = 3;
  void closeEvent(QCloseEvent *event);

  class CustomLabel : public QLabel
  {
    //Q_OBJECT
  public:
      CustomLabel(QWidget *parent = nullptr);

      void mousePressEvent(QMouseEvent *event) override;
  };

signals:
    void dataToSend(int data);
    void dataopen(bool f);

public slots:
    void spinOnce();
    void spin();
    void sendData() {
        int data = 42;
        emit dataToSend(data);
    }
    void not_hide()
    {
      bool f =true;
      emit dataopen(f);
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);



private:
  Ui::MainWindow4 *ui;
  QTimer *ros_timer;

  ros::NodeHandlePtr nhPtr;
  ros::NodeHandlePtr nhPtr1;
  ros::NodeHandlePtr RGBptr;
  ros::NodeHandlePtr DEPptr;
  ros::NodeHandlePtr pub1ptr;
  ros::Subscriber sub;
  ros::Subscriber sub1;
  ros::Subscriber RGB;
  ros::Subscriber DEP;
  ros::Publisher pub1;
  freenect_context *context;
};

#endif // MAINWINDOW4_H
