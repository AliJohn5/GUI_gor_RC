#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow3)
{
  ui->setupUi(this);
}

MainWindow3::~MainWindow3()
{
  delete ui;
}


void MainWindow3::closeEvent(QCloseEvent *event)
{
  not_hide();
}
