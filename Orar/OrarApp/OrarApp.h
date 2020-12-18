#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OrarApp.h"
#include"SecondView.h"
#include "HomePage.h"

class OrarApp : public QMainWindow
{
    Q_OBJECT

public:
    OrarApp(QWidget *parent = Q_NULLPTR);
    void ChangeViews(int viewid);


private:
    Ui::OrarAppClass ui;
    SecondView secondpage;
    HomePage homepage;
};
