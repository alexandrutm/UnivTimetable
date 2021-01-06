#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OrarApp.h"

#include "SecondView.h"
#include "HomeView.h"
#include "SecondView.h"
#include "BasicInfoView.h"
#include "SubjectView.h"
#include "ClassesView.h"
#include "TeacherView.h"
#include "LessonView.h"


#include "INavigator.h"
#include "Context.h"


class OrarApp : public QMainWindow, public INavigator
{
    Q_OBJECT

public:
    OrarApp(QWidget *parent = Q_NULLPTR);
    void ChangeView(INavigator::viewId theView);
    void ChangeStatus(QString status);

private slots:

    void on_btnSubject_clicked();
    void on_btnClass_clicked();
    void on_btnRoom_clicked();
    void on_btnTeacher_clicked();
    void on_btnLesson_clicked();

private:
    Ui::OrarAppClass ui;

    Context mContext;
    
    HomeView mHomeView;
    SecondView mSecondView;
    BasicInfoView mBasicInfoView;
    SubjectView mSubjectView;
    ClassesView mClassView;
    TeacherView mTeacher;
    LessonView mLesson;
};
