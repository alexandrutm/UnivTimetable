#include "OrarApp.h"
#include "stdafx.h"


OrarApp::OrarApp(QWidget *parent)
    : QMainWindow(parent), homepage(this,this),stackWid(this),secondpage(this,this),thirdpage(this,this)
{
    ui.setupUi(this);
    ui.statusBar->addWidget(ui.statusBarLabel);
    setCentralWidget(&stackWid);

    stackWid.addWidget(&homepage);
    stackWid.addWidget(&secondpage);
    stackWid.addWidget(&thirdpage);

    stackWid.setCurrentIndex(0);
}

void OrarApp::ChangeView(INavigator::viewId theView)
{
    if(theView==INavigator::viewId::homepage)
    { 
        stackWid.setCurrentIndex(0);
    }
    else if (theView == INavigator::viewId::secondpage)
    {
        stackWid.setCurrentIndex(1);
    }
    else if (theView == INavigator::viewId::thirdpage)
    {
        stackWid.setCurrentIndex(2);
    }

}

void OrarApp::ChangeStatus(QString status)
{
    ui.statusBar->showMessage(status, 5000);
}
