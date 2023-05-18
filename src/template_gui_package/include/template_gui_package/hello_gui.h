#ifndef HELLO_GUI_H
#define HELLO_GUI_H

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

#include "mainwindow2.h"
#include "mainwindow3.h"
#include "mainwindow4.h"

using std::vector;

using namespace cv;



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
  MainWindow3 *win3;
  MainWindow4 *win4;
  //helloGui* first;

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
  void openwin3();
  void openwin4();
public slots:
    void receiveData(int data) {
        // Use the data received here
      qDebug()<<"helloGui receive: "<<data;
    }

    void not_hide(bool f)
    {
      if(f)
      show();
    }


private slots:

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();


private:
  Ui::helloGui *ui;
  QTimer *ros_timer;

  ros::NodeHandlePtr nhPtr;
  ros::NodeHandlePtr nhPtr1;
  ros::Subscriber sub;
  ros::Subscriber sub1;
};


#endif // HELLO_GUI_H
