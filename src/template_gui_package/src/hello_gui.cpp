#include "hello_gui.h"
#include "ui_hello_gui.h"
#include<QPixmap>
#include<QImage>
QString qstring_msg;
using namespace cv;

QPixmap Mat_to_pixmap(Mat src)
{
  QImage::Format format=QImage::Format_Grayscale8;
  int bpp = src.channels();
  if (bpp==3) format=QImage::Format_RGB888;
  QImage img(src.cols,src.rows,format);
  uchar *sptr,*dptr;
  int linesize = src.cols*bpp;
  for (int y=0;y<src.rows;y++) {
    sptr=src.ptr(y);
    dptr=img.scanLine(y);
    memcpy(dptr,sptr,linesize);
  }
  if (bpp==3)return  QPixmap::fromImage(img.rgbSwapped());
  return QPixmap::fromImage(img);
}

helloGui::helloGui(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::helloGui)
{
  ui->setupUi(this);
  pub_.reset(new ros::NodeHandle("~"));
  sub_.reset(new ros::NodeHandle("a"));
  john.reset(new ros::NodeHandle("~"));
  dd.reset(new ros::NodeHandle("a"));

  ros_timer = new QTimer(this);
  connect(ros_timer,SIGNAL(timeout()),this,SLOT(spinOnce()));
  ros_timer->start(100);

  /*
  ros_timer1 = new QTimer(this);
  connect(ros_timer1,SIGNAL(timeout()),this,SLOT(spin()));
  ros_timer->start(100);
*/
 /*sensor_msgs::ImagePtr img;
  Mat m;
  pub_->param <sensor_msgs::ImagePtr>("img",img,"/talker/frame");
  _sub = pub_->subscribe <sensor_msgs::Image>(img,1,&helloGui::callback,this);
  std::string s1;
  pub_->param<std::string>("s",s1,"/talker/chatter");
  _pub = pub_->advertise<std_msgs::String>(s1,1);*/

  //std::string s3;
  //sub_->param<std::string>("s",s3,"/listener/chatter");
  //ali = sub_->subscribe<std_msgs::String>(s3,1,&helloGui::callback1,this);

  //sensor_msgs::Image::ConstPtr img;
  Mat img;
//  int a;
  //sensor_msgs::ImagePtr img ;
  //john->

  ali = john->subscribe<sensor_msgs::Image>("/talker/frame",1,&helloGui::imageCallback,this);
  _pub = sub_->advertise<std_msgs::String>("/a/chatter",1);
  _sub = sub_->subscribe<std_msgs::String>("/a/chatter",1,&helloGui::callback1,this);
  DD = dd->advertise<std_msgs::String>("/talker/chatter",1);



}

helloGui::~helloGui()
{
  delete ui;
}

void helloGui::spinOnce()
{
  if (ros::ok())
  {
    ros::spinOnce();
  } else {
    QApplication::quit();
}
}


void helloGui::spin()
{
  if (ros::ok())
  {
    ros::spin();
  } else {
    QApplication::quit();
}
}


void helloGui::callback(const sensor_msgs::Image::ConstPtr& msg)
{
   /*qstring_msg = QString::fromStdString(msg->data.c_str());
   ui->sub->setText(qstring_msg);*/
 // sensor_msgs::ImagePtr img;
  //img = msg;
}

void helloGui::imageCallback(const sensor_msgs::Image::ConstPtr &msg)
{
  //std::cout<<msg->data[0];

  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  QPixmap m = Mat_to_pixmap(k->image);
  int w = ui->frame_label->width();
  int h = ui->frame_label->height();
  ui->frame_label->setPixmap( m.scaled(w,h) );
}

void helloGui::callback1(const std_msgs::String::ConstPtr& msg)
{
   qstring_msg = QString::fromStdString(msg->data.c_str());
   ui->pub->setText(qstring_msg);

}

void helloGui::on_sub_B_clicked()
{
  std_msgs::String msg;
  std::stringstream ss;
  ss << "Hello ali";
  msg.data = ss.str();
  _pub.publish(msg);
}

void helloGui::on_pub_B_clicked()
{/*
  std_msgs::String msg;
  std::stringstream ss;
  ss << "Hello ali";
  msg.data = ss.str();
  _pub.publish(msg);*/
}

