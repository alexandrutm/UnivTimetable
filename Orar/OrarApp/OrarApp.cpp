#include "OrarApp.h"
#include "stdafx.h"


OrarApp::OrarApp(QWidget *parent)
    : QMainWindow(parent), mHomeView(this,this),stackWid(this),
    mSecondView(this,this),mBasicInfoView(this,mContext,this),mClassView(this,mContext,this),
    mSubjectView(this,mContext,this),mTeacher(this,mContext,this),mLesson(this,mContext,this)

{
    ui.setupUi(this);
    ui.statusBar->addWidget(ui.statusBarLabel);
    setCentralWidget(&stackWid);

    stackWid.addWidget(&mHomeView);
    stackWid.addWidget(&mSecondView);
    stackWid.addWidget(&mBasicInfoView);
    stackWid.addWidget(&mSubjectView);
    stackWid.addWidget(&mClassView);
    stackWid.addWidget(&mTeacher);
    stackWid.addWidget(&mLesson);

    stackWid.setCurrentIndex(0);
}

void OrarApp::ChangeView(INavigator::viewId theView)
{
    if (theView == INavigator::viewId::homepage)
    {
        stackWid.setCurrentIndex(0);
    }
    else if (theView == INavigator::viewId::secondpage)
    {
        stackWid.setCurrentIndex(1);
    }
    else if (theView == INavigator::viewId::basicInfoView)
    {
        stackWid.setCurrentIndex(2);
    }
    else if (theView == INavigator::viewId::subjectView)
    {
        stackWid.setCurrentIndex(3);
    }
    else if (theView == INavigator::viewId::classesView)
    {
        stackWid.setCurrentIndex(4);
    }
    else if (theView == INavigator::viewId::teacherView)
    {
        stackWid.setCurrentIndex(5);
    }
    else if (theView == INavigator::viewId::lessonView)
        stackWid.setCurrentIndex(6);

}

void OrarApp::ChangeStatus(QString status)
{
    ui.statusBar->showMessage(status, 5000);
}
