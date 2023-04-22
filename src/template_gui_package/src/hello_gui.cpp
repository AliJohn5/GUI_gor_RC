#include "hello_gui.h"
#include "ui_hello_gui.h"
#include<QPixmap>
#include<QImage>
#include<QDebug>
#include <iostream>
#include <QCloseEvent>
#include<event.h>
#include<QLabel>

QString qstring_msg;
using namespace cv;

bool camera_is_on = false;


int num_of_cols = 640;
int num_of_raws = 480;


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


void closeNodes()
{
  system("rosnode kill /talker &");
}

helloGui::helloGui(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::helloGui)
{
  ui->setupUi(this);

  nhPtr.reset(new ros::NodeHandle("~"));
  nhPtr1.reset(new ros::NodeHandle("a"));

  ros_timer = new QTimer(this);
  connect(ros_timer,SIGNAL(timeout()),this,SLOT(spinOnce()));
  ros_timer->start(100);


  sub = nhPtr->subscribe<sensor_msgs::Image>("/talker/frame",1,&helloGui::imageCallback,this);
  pub = nhPtr1->advertise<std_msgs::String>("/a/chatter",1);
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





void helloGui::imageCallback(const sensor_msgs::Image::ConstPtr &msg)
{
  if (!camera_is_on) {ui->label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  QPixmap m = Mat_to_pixmap(k->image);
  int w = ui->label->width();
  int h = ui->label->height();
  ui->label ->setPixmap( m.scaled(w,h) );
}



/* callback1
void helloGui::callback1(const std_msgs::String::ConstPtr& msg)
{
   qstring_msg = QString::fromStdString(msg->data.c_str());
   ui->pub->setText(qstring_msg);

}*/

/* helloGui::on_pub_B_clicked()
void helloGui::on_pub_B_clicked()
{
  std_msgs::String msg;
  std::stringstream ss;
  ss << "Hello ali";
  msg.data = ss.str();
  _pub.publish(msg);
}*/


void helloGui::closeEvent(QCloseEvent *event)
{
  closeNodes();
  QApplication::quit();
}

void helloGui::mouseMoveEvent(QMouseEvent *event)
{
 // if (!pixmap()) return;

      QPoint pos = event->pos();
      //QRect labelRect = contentsRect();
      //QSize pixmapSize = pixmap()->size();
     // QRect pixmapRect = QRect(QPoint(0, 0), pixmapSize).scaled(labelRect.size(), Qt::KeepAspectRatio);

      /*if (pixmapRect.contains(pos)) {
        double x = pos.x() * pixmapSize.width() / (double)pixmapRect.width();
        double y = pos.y() * pixmapSize.height() / (double)pixmapRect.height();}*/
      double x = pos.x() ;//* pixmapSize.width() / (double)pixmapRect.width();
      double y = pos.y() ;//* pixmapSize.height() / (double)pixmapRect.height();
        //qDebug() << "Mouse position on image:" << x << y;

     // ui->label->setNum((int)x);
      //ui->label_2->setNum((int)y);
}

void helloGui::mousePressEvent(QMouseEvent *event)
{

  QWidget* childWidget = childAt(event->pos());
      // Check if the child widget is a QLabel
  //QWidget* childWidget = ui->label;
  QLabel* label = qobject_cast<QLabel*>(childWidget);
  if ( label == ui->label) {
          // Convert the global mouse position to the local position of the QLabel
      QPoint position = label->mapFromGlobal(event->globalPos());
      int x = position.x()*num_of_cols /ui->label->width();
      int y = position.y()*num_of_raws /ui->label->height();
      qDebug() << "Mouse clicked on QLabel at position:" << x << " " << y;
      }
}

void helloGui::on_pushButtonCamera_clicked()
{
  if (!camera_is_on)
  {
    system("rosrun template_gui_package talker &");
    camera_is_on = true;
  } else {
    system("rosnode kill /talker &");
    ui->label->setNum(0);
    camera_is_on = false;
  }
}
