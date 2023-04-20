#include<QApplication>
#include "hello_gui.h"

int main(int argc, char **argv)
{
  ros::init(argc,argv,"hello_gui_node");
  QApplication a(argc,argv);
  helloGui w;


  w.show();
  return a.exec();
}
