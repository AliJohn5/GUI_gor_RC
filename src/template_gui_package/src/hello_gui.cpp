#include "hello_gui.h"
#include "ui_hello_gui.h"
#include "rrtstar.h"

static QString qstring_msg;
using namespace cv;
using namespace ali;


helloGui::helloGui(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::helloGui)
{
  ui->setupUi(this);
  lab = ui->label_2;
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
  image = k->image;
//  if (x_center && y_center)
//  circle(image, Point(x_center, y_center), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image);
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


void closeNodes()
{
  system("rosnode kill -a");
}



QPixmap Mat_to_pixmap(Mat src)
{
  QImage::Format format=QImage::Format_Grayscale8;
  int bpp = src.channels();
  if (bpp==3) format=QImage::Format_RGB888;
  QImage img(src.cols,src.rows,format);
  uchar *sptr,*dptr;
  size_t linesize = static_cast<size_t>(src.cols*bpp);
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

    return std::move(mask);
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
