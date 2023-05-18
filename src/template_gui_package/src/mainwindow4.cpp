#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include "hello_gui.h"
#include<string.h>
#include <geometry_msgs/Twist.h>
using namespace ali;
using std::string;

static int x_center2=0 , y_center2=0;

Mat image3;

int _x1=0;
int _y1=0;
int _z1=0;

uint16_t * depth_data;

MainWindow4::MainWindow4(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow4)
{
  ui->setupUi(this);

  nhPtr.reset(new ros::NodeHandle("~"));
  nhPtr1.reset(new ros::NodeHandle("~"));
  pub1ptr.reset(new ros::NodeHandle("~"));

  RGBptr.reset(new ros::NodeHandle("~"));
  DEPptr.reset(new ros::NodeHandle("~"));
  lab = ui->label_2;
  lab2 = ui->label_3;
  ros_timer = new QTimer(this);
  connect(ros_timer,SIGNAL(timeout()),this,SLOT(spinOnce()));
  ros_timer->start(100);


  sub = nhPtr->subscribe<sensor_msgs::Image>("/talker/frame",1,&MainWindow4::imageCallback,this);
  sub1 = nhPtr1->subscribe<sensor_msgs::Image>("/frame2/frame2",1,&MainWindow4::imageCallback1,this);

  pub1 = pub1ptr->advertise<geometry_msgs::Twist>("/point",10);
  RGB = RGBptr->subscribe<sensor_msgs::Image>("/rgb_image",1,&MainWindow4::RGBcallback,this);
  DEP = DEPptr->subscribe<sensor_msgs::Image>("/depth_image",1,&MainWindow4::DEPcallback,this);

}

MainWindow4::~MainWindow4()
{
  delete ui;
}


void MainWindow4::spinOnce()
{
  if (ros::ok())
  {
    ros::spinOnce();
  } else {
    QApplication::quit();
}
}


void MainWindow4::spin()
{
  if (ros::ok())
  {
    ros::spin();
  } else {
    QApplication::quit();
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


void MainWindow4::imageCallback(const sensor_msgs::Image::ConstPtr &msg)
{
 /* if (!camera_is_on) {ui->label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  image = k->image;
  if (x_center && y_center)
  circle(image, Point(x_center, y_center), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image);
  int w = ui->label->width();
  int h = ui->label->height();
  ui->label ->setPixmap( m.scaled(w,h) );*/
}

void MainWindow4::imageCallback1(const sensor_msgs::Image::ConstPtr &msg)
{
  /*if (!camera_is_on_1) {ui->frame_2_label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  image2 = k->image;
  if (x_center2 && y_center2)
  circle(image2, Point(x_center2, y_center2), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image2);
  int w = ui->frame_2_label->width();
  int h = ui->frame_2_label->height();
  ui->frame_2_label ->setPixmap( m.scaled(w,h) );*/
}

void MainWindow4::RGBcallback(const sensor_msgs::Image::ConstPtr &msg)
{
 // if (!camera_is_on_1) {ui->frame_2_label->clear(); return;}
  cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  image = k->image;
  if (x_center && y_center)
  circle(image2, Point(x_center, y_center), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image);
  int w = ui->label->width();
  int h = ui->label->height();
  ui->label ->setPixmap( m.scaled(w,h) );
}

void MainWindow4::DEPcallback(const sensor_msgs::Image::ConstPtr &msg)
{
  //if (!camera_is_on_1) {ui->label_3->clear(); return;}
 // cv_bridge::CvImagePtr k = cv_bridge::toCvCopy(msg,"bgr8");
  //image2 = k->image;
  /*if (x_center2 && y_center2)
  circle(image2, Point(x_center2, y_center2), 5, Scalar(0, 0, 255), -1);
  QPixmap m = Mat_to_pixmap(image2);
  int w = ui->frame_2_label->width();
  int h = ui->frame_2_label->height();
  ui->frame_2_label ->setPixmap( m.scaled(w,h) );*/
  depth_data = (uint16_t*)&msg->data[0];
  _z1 = 745-depth_data[(_y1+160) * num_of_cols + (_x1+320)];
}


void MainWindow4::closeEvent(QCloseEvent *event)
{
  not_hide();
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

      // Find the center of the contwidthour
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


Point detect_depth(Mat mask,int x)
{
  // Define the region of interest (ROI) based on the x coordinate and mask size
      int roiWidth = 100;  // Width of the ROI
      int roiX = x - roiWidth / 2;  // X coordinate of the ROI
      int roiY = 0;  // Y coordinate of the ROI
      int roiHeight = mask.rows;  // Height of the ROI

      if (roiX<0) roiX=0;
      if (roiX+roiWidth>640) roiWidth=640-roiX;
      // Extract the ROI from the mask
      Rect roi(roiX, roiY, roiWidth, roiHeight);
      Mat maskRoi = mask(roi);

      // Convert the ROI to grayscale for contour detection
      Mat grayMask;
      cvtColor(maskRoi, maskRoi, COLOR_GRAY2BGR);
      cvtColor(maskRoi, grayMask, COLOR_BGR2GRAY);


      Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));

      for (int var = 0; var < 5; var++)
      {
      Mat dilated_mask;
      dilate(maskRoi, dilated_mask, kernel);
      maskRoi = dilated_mask;
      }

      for (int var = 0; var < 5; var++) {
        Mat eroded_mask;
        erode(maskRoi, eroded_mask, kernel);
        maskRoi = eroded_mask;
      }


      // Find the contours in the ROI
      std::vector<std::vector<Point>> contours;
      findContours(grayMask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

      // Find the center of the bounding box around the largest contour
      int centerY = -1;
      int centerx = -1;
      if (contours.size() > 0) {
          Rect boundingBox = boundingRect(contours[0]);
          centerY = boundingBox.y + boundingBox.height / 2;
          centerx = boundingBox.x + boundingBox.width / 2;
      }


      // Adjust the y coordinate to account for the ROI offset
      centerY += roiY;
      centerx += roiX;

      // Return the y coordinate of the center of the object in the ROI
      return Point(centerx,centerY);
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


void getHSVRange1(Vec3b gbr, int& minH, int& maxH, int& minS, int& maxS, int& minV, int& maxV) {
    Mat3b color(1,1,Vec3b(gbr[0], gbr[1], gbr[2])); // convert RGB to BGR for OpenCV
    Mat3b hsv;
    cvtColor(color, hsv, COLOR_BGR2HSV);
    Vec3b hsvColor = hsv(0,0);
    int hue = hsvColor[0];
    int saturation = hsvColor[1];
    int value = hsvColor[2];

    // Set range for hue, saturation, and value to create a mask for the color
    int hueRange = 20;
    int saturationRange = 75;
    int valueRange = 75;

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


void MainWindow4::on_pushButton_clicked()
{
  ui->label_6->setNum(_x1);
  ui->label_7->setNum(_y1);
  ui->label_8->setNum(_z1);
}

MainWindow4::CustomLabel::CustomLabel(QWidget *parent) : QLabel(parent)
{
  this->setAlignment(Qt::AlignCenter);
}

void MainWindow4::CustomLabel::mousePressEvent(QMouseEvent *event)
{
  if (!this->pixmap()) return;
  if(image.empty()) return;
  QPoint position = event->pos();
  int x = position.x()*num_of_raws /this->width();
  int y = position.y()*num_of_cols /this->height();
  /*QString s = QString::number(x) + " "+ QString::number(y);
  lab->setText(s);*/

  int minh,maxh,mins,maxs,minv,maxv;
  Vec3b pixel = image.at<Vec3b>(y, x);
  unsigned char blueValue = pixel[0];
  unsigned char greenValue = pixel[1];
  unsigned char redValue = pixel[2];
  Vec3b color(blueValue, greenValue, redValue);
  getHSVRange(color,minh,maxh,mins,maxs,minv,maxv);
  Mat mask = createMask(image,minh,maxh,mins,maxs,minv,maxv);

  Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));

 /* for (int var = 0; var < 2; var++) {
    Mat eroded_mask;
    erode(mask, eroded_mask, kernel);
    mask = eroded_mask;
  }

  for (int var = 0; var < 2; var++)
  {
  Mat dilated_mask;
  dilate(mask, dilated_mask, kernel);
  mask = dilated_mask;
  }*/

  mask = detect_center_of_object(mask,x,y);

  QPixmap m = Mat_to_pixmap(mask);

  int w = lab->width();
  int h = lab->height();
  lab->setPixmap( m.scaled(w,h) );


  _x1 = x-320;
  _y1 = y-160;
  //uint16_t depth_value = depth_data[y * num_of_cols + x];
  //qDebug()<<x<<y<<depth_value;
}



void MainWindow4::on_pushButton_2_clicked()
{
 /* string s = "rosrun template_gui_package frame2 3 &";
  s[35] = cameraIndix2 + '0';
  const char * s1 = s.c_str();
  qDebug()<<s1;
  if(!camera_is_on_1){
    system(s1);
    camera_is_on_1 = !camera_is_on_1;
  } else {
    system("rosnode kill /frame2 &");
    camera_is_on_1 = !camera_is_on_1;
  }*/
  geometry_msgs::Twist twist_msg;
  twist_msg.linear.x = _x1;
  twist_msg.linear.y = _y1;
  twist_msg.linear.z = _z1;
  pub1.publish(twist_msg);
}

void MainWindow4::on_spinBox_valueChanged(int arg1)
{
    cameraIndix1 = arg1;
}

void MainWindow4::on_spinBox_2_valueChanged(int arg1)
{
    cameraIndix2 = arg1;
}
