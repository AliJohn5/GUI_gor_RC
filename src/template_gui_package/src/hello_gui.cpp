#include "hello_gui.h"
#include "ui_hello_gui.h"
#include "rrtstar.h"
#include "mainwindow2.h"
#include "mainwindow3.h"
#include "mainwindow4.h"

static QString qstring_msg;
using namespace cv;



using namespace ali;


helloGui::helloGui(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::helloGui)
{
  ui->setupUi(this);
  //lab = ui->label_2;
  //first = this;
  second = new MainWindow2(this);
  win3 = new MainWindow3(this);
  win4 = new MainWindow4(this);
  QObject::connect(second, &MainWindow2::dataToSend, this, &helloGui::receiveData);
  QObject::connect(second, &MainWindow2::dataopen, this, &helloGui::not_hide);
  QObject::connect(win3, &MainWindow3::dataopen, this, &helloGui::not_hide);
  QObject::connect(win4, &MainWindow4::dataopen, this, &helloGui::not_hide);
  nhPtr.reset(new ros::NodeHandle("~"));
  nhPtr1.reset(new ros::NodeHandle("~"));

  ros_timer = new QTimer(this);
  connect(ros_timer,SIGNAL(timeout()),this,SLOT(spinOnce()));
  ros_timer->start(100);


  sub = nhPtr->subscribe<sensor_msgs::Image>("/talker/frame",1,&helloGui::imageCallback,this);
  sub1 = nhPtr1->subscribe<sensor_msgs::Image>("/frame2/frame2",1,&helloGui::imageCallback1,this);
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

void helloGui::openSecondWindow() {
  hide();
  second->show();
}

void helloGui::openwin3()
{
  hide();
  win3->show();
}
void helloGui::openwin4()
{
  hide();
  win4->show();
}






void helloGui::imageCallback(const sensor_msgs::Image::ConstPtr &msg)
{
  /*if (!camera_is_on) {ui->label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  image = k->image;
  if (x_center && y_center)
  circle(image, Point(x_center, y_center), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image);
  int w = ui->label->width();
  int h = ui->label->height();
  ui->label ->setPixmap( m.scaled(w,h) );*/
}

void helloGui::imageCallback1(const sensor_msgs::Image::ConstPtr &msg)
{
  /*if (!camera_is_on_1) {ui->frame_2_label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  image = k->image;
//  if (x_center && y_center)
//  circle(image, Point(x_center, y_center), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image);
  int w = ui->frame_2_label->width();
  int h = ui->frame_2_label->height();
  ui->frame_2_label ->setPixmap( m.scaled(w,h) );*/
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
    //QPoint pos = event->pos();
    //double x = pos.x() ;
    //double y = pos.y() ;
}
/*
void helloGui::mousePressEvent(QMouseEvent *event)
{
      QWidget* childWidget = childAt(event->pos());
      // Check if the child widget is a QLabel
      QLabel* label = qobject_cast<QLabel*>(childWidget);
      if (!label->pixmap()) return;
          // Convert the global mouse position to the local position of the QLabel
      QPoint position = label->mapFromGlobal(event->globalPos());
      int x = position.x()*num_of_cols /ui->label->width();
      int y = position.y()*num_of_raws /ui->label->height();
      //Mat img = ali(image,x,y);
      int minh,maxh,mins,maxs,minv,maxv;

      Vec3b pixel = image.at<Vec3b>(y, x);
      // Extract the B, G, R values of the pixel
      unsigned char blueValue = pixel[0];
      unsigned char greenValue = pixel[1];
      unsigned char redValue = pixel[2];
      Vec3b color(blueValue, greenValue, redValue);
      getHSVRange(color,minh,maxh,mins,maxs,minv,maxv);
      Mat mask = createMask(image,minh,maxh,mins,maxs,minv,maxv);
      mask = detect_center_of_object(mask,x,y);
      QPixmap m = Mat_to_pixmap(mask);
      int w = ui->label_2->width();
      int h = ui->label_2->height();
      ui->label_2->setPixmap( m.scaled(w,h) );

}*/
/*
void helloGui::on_pushButtonCamera_clicked()
{
  if (!camera_is_on)
  {
    system("rosrun template_gui_package talker &");
    ui->pushButtonCamera->setText("IS ON");
    camera_is_on = true;
  } else {
    system("rosnode kill /talker &");
    ui->pushButtonCamera->setText("IS OFF");
    ui->label->clear();
    camera_is_on = false;
  }
}

void helloGui::on_pushButton_4_clicked()
{
  if (!camera_is_on_1)
  {
    system("rosrun template_gui_package frame2 &");
    ui->pushButton_4->setText("IS ON");
    camera_is_on_1 = true;
  } else {
    system("rosnode kill /frame2 &");
    ui->pushButton_4->setText("IS OFF");
    ui->frame_2_label->clear();
    camera_is_on_1 = false;
  }
}

void helloGui::on_pushButton_clicked()
{
  factor2 =QString( ui->lineEdit->text()).toDouble();
  ui->lineEdit->clear();
}

void helloGui::on_lineEdit_editingFinished()
{
  factor2 =QString( ui->lineEdit->text()).toDouble();
  ui->lineEdit->clear();
}

void helloGui::on_actionopen_camera_triggered()
{
  if (!camera_is_on)
  {
    system("rosrun template_gui_package talker &");
    ui->pushButtonCamera->setText("IS ON");
    camera_is_on = true;
  } else {
    system("rosnode kill /talker &");
    ui->pushButtonCamera->setText("IS OFF");
    ui->label->clear();
    camera_is_on = false;
  }
}

void helloGui::on_actioncamera_2_ON_OFF_triggered()
{
  if (!camera_is_on_1)
  {
    system("rosrun template_gui_package frame2 &");
    ui->pushButton_4->setText("IS ON");
    camera_is_on_1 = true;
  } else {
    system("rosnode kill /frame2 &");
    ui->pushButton_4->setText("IS OFF");
    ui->frame_2_label->clear();
    camera_is_on_1 = false;
  }
}
*/


void closeNodes()
{
  system("rosnode kill -a");
}


helloGui::CustomLabel::CustomLabel(QWidget *parent) : QLabel(parent)
{
  this->setAlignment(Qt::AlignCenter);
}

void helloGui::CustomLabel::mousePressEvent(QMouseEvent *event)
{
  if (!this->pixmap()) return;
  if(image.empty()) return;
  QPoint position = event->pos();
  int x = position.x()*num_of_cols /this->width();
  int y = position.y()*num_of_raws /this->height();
  int minh,maxh,mins,maxs,minv,maxv;
  Vec3b pixel = image.at<Vec3b>(y, x);
  unsigned char blueValue = pixel[0];
  unsigned char greenValue = pixel[1];
  unsigned char redValue = pixel[2];
  Vec3b color(blueValue, greenValue, redValue);
  getHSVRange(color,minh,maxh,mins,maxs,minv,maxv);
  Mat mask = createMask(image,minh,maxh,mins,maxs,minv,maxv);
  mask = detect_center_of_object(mask,x,y);
  QPixmap m = Mat_to_pixmap(mask);
  int w = lab->width();
  int h = lab->height();
  lab->setPixmap( m.scaled(w,h) );
}

void helloGui::on_pushButton_7_clicked()
{
  openSecondWindow();
}

void helloGui::on_pushButton_8_clicked()
{
    openwin3();
}

void helloGui::on_pushButton_9_clicked()
{
    openwin4();
}
