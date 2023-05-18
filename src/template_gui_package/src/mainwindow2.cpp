#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow2)
{
  ui->setupUi(this);

}

MainWindow2::~MainWindow2()
{
  delete ui;
}


void MainWindow2::on_pushButton_clicked()
{
    sendData();
    qDebug()<<"mainwindow2 send :";
}

void MainWindow2::closeEvent(QCloseEvent *event)
{
  not_hide();
}
