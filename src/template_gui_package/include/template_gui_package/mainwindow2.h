#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

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

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow2(QWidget *parent = nullptr);
  ~MainWindow2();

signals:
    void dataToSend(int data);

public slots:
    void sendData() {
        int data = 42;
        emit dataToSend(data);
    }

private slots:
    void on_pushButton_clicked();

private:
  Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
