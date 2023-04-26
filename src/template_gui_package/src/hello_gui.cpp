#include "hello_gui.h"
#include "ui_hello_gui.h"
#include<QPixmap>
#include<QImage>
#include<QDebug>
#include <iostream>
#include <QCloseEvent>
#include<event.h>
#include<QLabel>
#include <opencv4/opencv2/highgui/highgui.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <vector>
#include<math.h>

using std::vector;

static QString qstring_msg;
using namespace cv;

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

double_t dist_betwen_point_and_center_from_uper_camera(int x,int y)
{
  double_t arc_spuare = pow(abs(x - main_x1),2) + pow(abs(y - main_y1),2) ;
  return sqrt(arc_spuare)*1.400;
}


double_t dist_betwen_point_and_center_from_uper_camera2(int x,int y)
{
  double_t arc_spuare = pow(abs(x - main_x2),2) + pow(abs(y - main_y2),2) ;
  return sqrt(arc_spuare)* factor2;
}

double_t cordinate_y_betwen_camera1_and_main(int y)
{
  double_t dist = (y-main_y1)*1.4000;
  return dist;
}


double_t cordinate_y_betwen_camera2_and_main(int y)
{
  double_t dist = (y-main_y2)*factor2;
  return dist;
}


static Mat image;
static Mat image2;


static int num_of_cols = 640;
static int num_of_raws = 480;


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


Mat detect_center_of_object(Mat img, int x ,int y)
{
      vector<vector<Point>> contours;
      vector<Vec4i> hierarchy;
      findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
      // Find the contour that contains the point
      Point point(x, y); // Change this to the point you have
      int contourIdx = -1;
      for (size_t i = 0; i < contours.size(); i++)
      {
          double dist = pointPolygonTest(contours[i], point, true);
          if (dist >= 0)
          {
              contourIdx = static_cast<int>(i);
              break;
          }
      }

      // Find the center of the contour
      if (contourIdx >= 0) {
      Moments moment = moments(contours[static_cast<unsigned int>(contourIdx)]);
      // Calculate the center of the contour
      int cx = static_cast<int>(moment.m10 / moment.m00) ;
      int cy = static_cast<int>(moment.m01 / moment.m00) ;
      // Draw a circle at the center of the object
      circle(img, Point(cx, cy), 5, Scalar(0, 0, 255), -1);
      x_center = cx;
      y_center = cy;
      qDebug()<<"Center is: ("<<cx <<cy<<" )";
      double_t dist = dist_betwen_point_and_center_from_uper_camera2(cx,cy);
      qDebug()<< "dist_betwen_point_and_center_from_uper_camera = " << dist;
      return img;
      }
      x_center = 0;
      y_center = 0;
      return img;
}






void getHSVRange(Vec3b gbr, int& minH, int& maxH, int& minS, int& maxS, int& minV, int& maxV) {
    Mat3b color(1,1,Vec3b(gbr[0], gbr[1], gbr[2])); // convert RGB to BGR for OpenCV
    Mat3b hsv;
    cvtColor(color, hsv, COLOR_BGR2HSV);
    Vec3b hsvColor = hsv(0,0);
    int hue = hsvColor[0];
    int saturation = hsvColor[1];
    int value = hsvColor[2];

    // Set range for hue, saturation, and value to create a mask for the color
    int hueRange = 10;
    int saturationRange = 50;
    int valueRange = 50;
    qDebug() << "7" ;

    minH = (hue - hueRange < 0) ? 0 : hue - hueRange;
    maxH = (hue + hueRange > 179) ? 179 : hue + hueRange;
    minS = (saturation - saturationRange < 0) ? 0 : saturation - saturationRange;
    maxS = (saturation + saturationRange > 255) ? 255 : saturation + saturationRange;
    minV = (value - valueRange < 0) ? 0 : value - valueRange;
    maxV = (value + valueRange > 255) ? 255 : value + valueRange;
}


Mat createMask(Mat3b img, int minH, int maxH, int minS, int maxS, int minV, int maxV) {
    Mat3b hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    Mat1b mask;
    inRange(hsv, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), mask);

    return mask;
}

Mat detect_all(Mat img)
{
  Mat gray;
      cvtColor(img, gray, COLOR_BGR2GRAY);

      // Apply thresholding to the image
      Mat thresh;
      threshold(gray, thresh, 100, 255, THRESH_BINARY);

      // Find contours in the thresholded image
      vector<vector<Point>> contours;
      vector<Vec4i> hierarchy;
      findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

      // Draw contours and classify shapes
      for (size_t i = 0; i < contours.size(); i++) {
          // Approximate each contour with a polygon
          vector<Point> approx;
          approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);

          // Classify the shape based on the number of vertices
          if (approx.size() == 3) {
              drawContours(img, contours, i, Scalar(0, 0, 255), 2);
              putText(img, "", approx[0], FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
          } else if (approx.size() == 4) {
              Rect rect = boundingRect(contours[i]);
              float aspectRatio = (float)rect.width / (float)rect.height;
              if (aspectRatio >= 0.95 && aspectRatio <= 1.05) {
                  drawContours(img, contours, i, Scalar(0, 255, 0), 2);
                  putText(img, "", approx[0], FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0));
              } else {
                  drawContours(img, contours, i, Scalar(255, 0, 0), 2);
                  putText(img, "", approx[0], FONT_HERSHEY_PLAIN, 1, Scalar(255, 0, 0));
              }
          } else if (approx.size() == 5) {
              drawContours(img, contours, i, Scalar(255, 255, 0), 2);
              putText(img, "", approx[0], FONT_HERSHEY_PLAIN, 1, Scalar(255, 255, 0));
          } else {
              drawContours(img, contours, i, Scalar(0, 255, 255), 2);
              putText(img, "", approx[0], FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 255));
          }
      }

      return img;
}




Mat qPixmapToMat(const QPixmap& pixmap)
{
    // Convert the QPixmap to a QImage
    QImage qImage = pixmap.toImage();

    // Convert the QImage to a cv::Mat
    cv::Mat mat(qImage.height(), qImage.width(), CV_8UC4, (void*)qImage.bits(), qImage.bytesPerLine());

    // Convert the BGRA image to BGR
    cv::cvtColor(mat, mat, cv::COLOR_BGRA2BGR);

    return mat;
}

void closeNodes()
{
  system("rosnode kill -a");
}

helloGui::helloGui(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::helloGui)
{
  ui->setupUi(this);

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




void helloGui::imageCallback(const sensor_msgs::Image::ConstPtr &msg)
{
  if (!camera_is_on) {ui->label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  image = k->image;
  if (x_center && y_center)
  circle(image, Point(x_center, y_center), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image);
  int w = ui->label->width();
  int h = ui->label->height();
  ui->label ->setPixmap( m.scaled(w,h) );
}

void helloGui::imageCallback1(const sensor_msgs::Image::ConstPtr &msg)
{
  if (!camera_is_on_1) {ui->frame_2_label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  image2 = k->image;
//  if (x_center && y_center)
//  circle(image, Point(x_center, y_center), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image2);
  int w = ui->frame_2_label->width();
  int h = ui->frame_2_label->height();
  ui->frame_2_label ->setPixmap( m.scaled(w,h) );
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
      //Mat img = ali(image,x,y);
      int minh,maxh,mins,maxs,minv,maxv;

      Vec3b pixel = image.at<Vec3b>(y, x);
      // Extract the B, G, R values of the pixel
      int blueValue = pixel[0];
      int greenValue = pixel[1];
      int redValue = pixel[2];
      Vec3b color(blueValue, greenValue, redValue);
      getHSVRange(color,minh,maxh,mins,maxs,minv,maxv);
      Mat mask = createMask(image,minh,maxh,mins,maxs,minv,maxv);
      mask = detect_center_of_object(mask,x,y);
      QPixmap m = Mat_to_pixmap(mask);
      int w = ui->label_2->width();
      int h = ui->label_2->height();
      ui->label_2->setPixmap( m.scaled(w,h) );
      }


  else if ( label == ui->frame_2_label) {
          // Convert the global mouse position to the local position of the QLabel
      QPoint position = label->mapFromGlobal(event->globalPos());
      int x = position.x()*num_of_cols /ui->frame_2_label->width();
      int y = position.y()*num_of_raws /ui->frame_2_label->height();
      //Mat img = ali(image,x,y);
      /*int minh,maxh,mins,maxs,minv,maxv;

      Vec3b pixel = image.at<Vec3b>(y, x);
      // Extract the B, G, R values of the pixel
      int blueValue = pixel[0];
      int greenValue = pixel[1];
      int redValue = pixel[2];
      Vec3b color(blueValue, greenValue, redValue);
      getHSVRange(color,minh,maxh,mins,maxs,minv,maxv);
      Mat mask = createMask(image,minh,maxh,mins,maxs,minv,maxv);
      mask = detect_center_of_object(mask,x,y);*/
      QPixmap m = Mat_to_pixmap(image2);
      int w = ui->frame_2_label->width();
      int h = ui->frame_2_label->height();
      ui->frame_2_label->setPixmap( m.scaled(w,h) );
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
    ui->label->clear();
    camera_is_on = false;
  }
}

void helloGui::on_pushButton_4_clicked()
{
  if (!camera_is_on_1)
  {
    system("rosrun template_gui_package frame2 &");
    camera_is_on_1 = true;
  } else {
    system("rosnode kill /frame2 &");
    ui->frame_2_label->clear();
    camera_is_on_1 = false;
  }
}

void helloGui::on_pushButton_clicked()
{
  factor2 =QString( ui->lineEdit->text()).toDouble();
}
