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

using std::vector;

QString qstring_msg;
using namespace cv;

bool camera_is_on = false;

Mat image;


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


Mat detect_center_of_object(Mat img, int x ,int y)
{
     Mat gray;
     cvtColor(img, gray, COLOR_BGR2GRAY);
     qDebug()<< img.at<int>(220,230);

      // Threshold the image
      Mat thresh;
      //threshold(gray, thresh, 127, 255, THRESH_BINARY);
      //threshold(gray, thresh, 127, 255, THRESH_BINARY);
      int g = img.at<int>(x,y,0);
      qDebug()<< g;
      threshold(gray, thresh, 0 ,255, THRESH_BINARY);

      // Find the contours
      vector<vector<Point>> contours;
      vector<Vec4i> hierarchy;
      findContours(thresh, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
      imshow("ali",thresh);
      waitKey(1);

      // Find the contour that contains the point
      Point point(x, y); // Change this to the point you have
      int contourIdx = -1;
      for (size_t i = 0; i < contours.size(); i++)
      {
          double dist = pointPolygonTest(contours[i], point, true);
          if (dist >= 0)
          {
              contourIdx = i;
              break;
          }
      }

      // Find the center of the contour
      if (contourIdx >= 0) {
      Moments moment = moments(contours[contourIdx]);
      // Calculate the center of the contour
      int cx = moment.m10 / moment.m00;
      int cy = moment.m01 / moment.m00;
      // Draw a circle at the center of the object
      circle(img, Point(cx, cy), 5, Scalar(0, 0, 255), -1);
      }
      return img;
}


Mat ali (Mat img, int x,int y)
{
  Mat hsv;
  cvtColor(img,hsv,COLOR_BGR2HSV);
  Vec3b color = hsv.at<Vec3b>(Point(x, y));

      // Define the color range based on the color of the point
  Scalar lower, upper;
  Mat mask;
      if (color.val[0] >= 170 || color.val[0] <= 10) {
          // If the hue value is close to 0 or 180 degrees, use a wider range for red
        Mat mask1,mask2;
               Scalar lower1 = Scalar(0, 100, 100);
                Scalar upper1 = Scalar(10, 255, 255);
                Scalar lower2 = Scalar(170, 100, 100);
                Scalar upper2 = Scalar(180, 255, 255);
                inRange(hsv, lower1, upper1, mask1);
                inRange(hsv, lower2, upper2, mask2);
                bitwise_or(mask1, mask2, mask);
      } else {
          lower = Scalar(color.val[0] - 10, 100, 100);
          upper = Scalar(color.val[0] + 10, 255, 255);
          inRange(hsv, lower, upper, mask);
      }
  //inRange(hsv, lower, upper, mask);

  Mat result;
  bitwise_and(img, img, result, mask);
  circle(mask, Point(x, y), 5, Scalar(255, 255, 255), -1);
  //drawContours(img, mask,0, Scalar(255, 0, 0), 2);

      // Calculate the centroid of the mask
  Moments M = moments(mask, true);
  Point centroid(M.m10 / M.m00, M.m01 / M.m00);

      // Display the mask and the centroid
  imshow("Mask", mask);
  circle(img, centroid, 5, Scalar(0, 255, 0), -1);
  //imshow("Result", img);
  //waitKey(0);

  return  img;

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
/*Mat detect_center(Mat img,int x,int y)
{
  int min_x = 0;
  int max_x = num_of_cols;
  int min_y = 0;
  int max_y = num_of_raws;
  int dist = 5;
  int i=1;


  return img;
}
*/


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
  image = k->image;
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
      Mat img = ali(image,x,y);
      QPixmap m = Mat_to_pixmap(img);
      int w = ui->label_2->width();
      int h = ui->label_2->height();
      ui->label_2->setPixmap( m.scaled(w,h) );
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
