#include "OrarApp.h"
#include "stdafx.h"


OrarApp::OrarApp(QWidget *parent)
    : QMainWindow(parent), mHomePage(this,this),stackWid(this),mSecondPage(this,this),mThirdPage(this,mContext,this)
{
    ui.setupUi(this);
    ui.statusBar->addWidget(ui.statusBarLabel);
    setCentralWidget(&stackWid);

    stackWid.addWidget(&mHomePage);
    stackWid.addWidget(&mSecondPage);
    stackWid.addWidget(&mThirdPage);

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
