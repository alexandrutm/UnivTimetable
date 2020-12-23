#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OrarApp.h"
#include "SecondView.h"
#include "HomePage.h"
#include "SecondView.h"
#include "INavigator.h"
#include "ThirdPage.h"


class OrarApp : public QMainWindow, public INavigator
{
    Q_OBJECT

public:
    OrarApp(QWidget *parent = Q_NULLPTR);
    virtual void ChangeView(INavigator::viewId theView);
    virtual void ChangeStatus(QString status);

private:
    Ui::OrarAppClass ui;
    QStackedWidget stackWid;

    HomePage homepage;
    SecondView secondpage;
    ThirdPage thirdpage;
};
