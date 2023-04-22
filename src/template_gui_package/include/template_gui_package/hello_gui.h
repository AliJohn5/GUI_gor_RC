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
#include<QCloseEvent>
#include<QLabel>
#include<QPixmap>
#include<QMouseEvent>
#include<QDebug>

namespace Ui {
class helloGui;
}

class helloGui : public QMainWindow
{
  Q_OBJECT

public:
  explicit helloGui(QWidget *parent = nullptr);
  ~helloGui();

  //void callback(const sensor_msgs::Image::ConstPtr& msg);
  void imageCallback(const sensor_msgs::Image::ConstPtr& msg);
  void closeEvent(QCloseEvent *event);
  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);



public slots:
  void spinOnce();
  void spin();

private slots:


  void on_pushButtonCamera_clicked();

private:
  Ui::helloGui *ui;
  QTimer *ros_timer;

  ros::NodeHandlePtr nhPtr;
  ros::NodeHandlePtr nhPtr1;
  ros::Subscriber sub;
  ros::Publisher pub;
};

#endif // HELLO_GUI_H
