#include "stdafx.h"
#include "OrarApp.h"



OrarApp::OrarApp(QWidget *parent)
    : QMainWindow(parent), mHomeView(this,this),mBasicInfoView(this,mContext,this),
    mClassView(this,mContext,this),mSubjectView(this,mContext,this),mRoomView(this,mContext,this),
    mTeacher(this,mContext,this),mLesson(this,mContext,this)

{
    ui.setupUi(this);
    setCentralWidget(ui.centralStackWidget);
    
    ui.centralStackWidget->addWidget(&mHomeView);
    ui.centralStackWidget->setCurrentIndex(1);

    //////////// VIEW 
    ui.viewStackedWidget->addWidget(&mBasicInfoView);
    ui.viewStackedWidget->addWidget(&mSubjectView);
    ui.viewStackedWidget->addWidget(&mClassView);
    ui.viewStackedWidget->addWidget(&mRoomView);
    ui.viewStackedWidget->addWidget(&mTeacher);
    ui.viewStackedWidget->addWidget(&mLesson);
    ui.viewStackedWidget->setCurrentIndex(0);
}

void OrarApp::ChangeView(INavigator::viewId theView)
{
    if (theView == INavigator::viewId::homepage)
    {
        ui.centralStackWidget->setCurrentIndex(1);
    }
    else if (theView == INavigator::viewId::basicInfoView)
    {
        ui.centralStackWidget->setCurrentIndex(0);
    }
    else if (theView == INavigator::viewId::subjectView)
    {
        ui.viewStackedWidget->setCurrentIndex(1);
    }
    else if (theView == INavigator::viewId::classesView)
    {
        ui.viewStackedWidget->setCurrentIndex(2);
    }
    else if (theView == INavigator::viewId::roomView)
    {
        ui.viewStackedWidget->setCurrentIndex(3);
    }
    else if (theView == INavigator::viewId::teacherView)
    {
        ui.viewStackedWidget->setCurrentIndex(4);
    }
    else if (theView == INavigator::viewId::lessonView)
    {
        ui.viewStackedWidget->setCurrentIndex(5);
    }

}

void OrarApp::ChangeStatus(string aStatus)
{
    ui.statusBar->showMessage(QString::fromStdString(aStatus),5000);
}


void OrarApp::on_btnBasicInfo_clicked()
{
    ui.viewStackedWidget->setCurrentIndex(0);
}

void OrarApp::on_btnSubject_clicked()
{
    ui.viewStackedWidget->setCurrentIndex(1);
}

void OrarApp::on_btnClass_clicked()
{
    ui.viewStackedWidget->setCurrentIndex(2);
}

void OrarApp::on_btnRoom_clicked()
{
    ui.viewStackedWidget->setCurrentIndex(3);
}

void OrarApp::on_btnTeacher_clicked()
{
    ui.viewStackedWidget->setCurrentIndex(4);
}

void OrarApp::on_btnLesson_clicked()
{
    ui.viewStackedWidget->setCurrentIndex(5);
}



void OrarApp::on_mToggle_clicked()
{
    auto width = ui.mLeftMenu->width();
    int maxWidth = 150;
    int minWidth = 10;
    int widthExtended = 0;

    if (width == minWidth)
    {
        widthExtended = maxWidth;
    }
    else
        widthExtended = minWidth;

    QPropertyAnimation* animation = new QPropertyAnimation(ui.mLeftMenu, "minimumWidth");
    animation->setDuration(200);
    animation->setStartValue(width);
    animation->setEndValue(widthExtended);
    animation->start();

}

void OrarApp::on_mNew_triggered()
{
    QMessageBox::StandardButton replay = QMessageBox::question(this, "New Timetable", "You lose all data", QMessageBox::Yes | QMessageBox::No);

    if (replay == QMessageBox::Yes)
    {
        //delete data from context and from all forms
        mContext.DeleteData();
        ui.centralStackWidget->setCurrentIndex(1);
        ui.viewStackedWidget->setCurrentIndex(0);
        mBasicInfoView.ClearData();
        mSubjectView.ClearData();
        mClassView.ClearData();
        mTeacher.ClearData();
        mLesson.ClearData();
    }
    else
    {

    }
}
