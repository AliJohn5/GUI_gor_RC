#ifndef HELLO_GUI_H
#define HELLO_GUI_H

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
#include "mainwindow2.h"

using std::vector;

using namespace cv;


namespace  ali{


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

}

using namespace ali;

double_t dist_betwen_point_and_center_from_uper_camera(int x,int y);
double_t dist_betwen_point_and_center_from_uper_camera2(int x,int y);
double_t cordinate_y_betwen_camera1_and_main(int y);
double_t cordinate_y_betwen_camera2_and_main(int y);
void closeNodes();
QPixmap Mat_to_pixmap(Mat src);
Mat detect_center_of_object(Mat img, int x ,int y);
void getHSVRange(Vec3b gbr, int& minH, int& maxH, int& minS, int& maxS, int& minV, int& maxV);
Mat createMask(Mat3b img, int minH, int maxH, int minS, int maxS, int minV, int maxV);
Mat qPixmapToMat(const QPixmap& pixmap);





namespace Ui {
class helloGui;
class CustomLabel;
}

class helloGui : public QMainWindow
{
  Q_OBJECT

public:
  explicit helloGui(QWidget *parent = nullptr);
  ~helloGui();


  //void callback(const sensor_msgs::Image::ConstPtr& msg);
  void imageCallback(const sensor_msgs::Image::ConstPtr& msg);
  void imageCallback1(const sensor_msgs::Image::ConstPtr& msg);
  void closeEvent(QCloseEvent *event);
  void mouseMoveEvent(QMouseEvent* event);
  MainWindow2 *second;

  QPixmap  qim;


  class CustomLabel : public QLabel
  {
    //Q_OBJECT
  public:
      CustomLabel(QWidget *parent = nullptr);

      void mousePressEvent(QMouseEvent *event) override;
  };



public slots:
  void spinOnce();
  void spin();
  void openSecondWindow();
public slots:
    void receiveData(int data) {
        // Use the data received here
      qDebug()<<"helloGui receive: "<<data;
    }


private slots:


  void on_pushButtonCamera_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_clicked();

  void on_lineEdit_editingFinished();

  void on_actionopen_camera_triggered();

  void on_actioncamera_2_ON_OFF_triggered();

  void on_pushButton_7_clicked();

private:
  Ui::helloGui *ui;
  QTimer *ros_timer;

  ros::NodeHandlePtr nhPtr;
  ros::NodeHandlePtr nhPtr1;
  ros::Subscriber sub;
  ros::Subscriber sub1;
};


/*
class CustomLabel : public QLabel
{
  //Q_OBJECT
public:
    CustomLabel(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event) override;
};*/

#endif // HELLO_GUI_H
