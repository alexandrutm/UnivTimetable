#include "stdafx.h"
#include "OrarApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char * argv[])
{
  QApplication a(argc, argv);
  OrarApp      w;
  w.show();
  return a.exec();
}
