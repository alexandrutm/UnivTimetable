#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OrarApp.h"
#include "SecondView.h"
#include "HomePage.h"
#include "SecondView.h"
#include "INavigator.h"
#include "ThirdPage.h"
#include "Context.h"


class OrarApp : public QMainWindow, public INavigator
{
    Q_OBJECT

public:
    OrarApp(QWidget *parent = Q_NULLPTR);
    void ChangeView(INavigator::viewId theView);
    void ChangeStatus(QString status);

private:
    Ui::OrarAppClass ui;
    QStackedWidget stackWid;

    Context mContext;
    HomePage mHomePage;
    SecondView mSecondPage;
    ThirdPage mThirdPage;
};
