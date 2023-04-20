#include<QApplication>
#include<QPushButton>
#include "hello_gui.h"

void runNodes()
{
  system("rosrun template_gui_package talker &");
}



int main(int argc, char **argv)
{
  ros::init(argc,argv,"hello_gui_node");
  QApplication a(argc,argv);
  helloGui w;
  runNodes();
  w.show();
  return a.exec();
}
