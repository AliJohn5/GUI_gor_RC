#ifndef HELLO_GUI_H
#define HELLO_GUI_H

#include <QMainWindow>
#include <ros/ros.h>
#include <QTimer>
#include <std_msgs/String.h>
#include <opencv4/opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>



namespace Ui {
class helloGui;
}

class helloGui : public QMainWindow
{
  Q_OBJECT

public:
  explicit helloGui(QWidget *parent = nullptr);
  ~helloGui();

  void callback(const sensor_msgs::Image::ConstPtr& msg);
  void callback1(const std_msgs::String::ConstPtr& msg);
  void imageCallback(const sensor_msgs::Image::ConstPtr& msg);

public slots:
  void spinOnce();
  void spin();

private slots:
  void on_sub_B_clicked();

  void on_pub_B_clicked();

private:
  Ui::helloGui *ui;
  QTimer *ros_timer;
  QTimer *ros_timer1;
  ros::NodeHandlePtr sub_;
  ros::NodeHandlePtr pub_;
  ros::NodeHandlePtr john;
  ros::NodeHandlePtr dd;
  ros::Subscriber _sub;
  ros::Publisher _pub;
  ros::Publisher DD;
  ros::Subscriber ali;
};

#endif // HELLO_GUI_H
