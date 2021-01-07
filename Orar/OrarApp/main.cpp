#include <QtWidgets/QApplication>
#include "stdafx.h"
#include "OrarApp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OrarApp w;
    w.show();
    return a.exec();
}
