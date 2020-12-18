#include "OrarApp.h"
#include "stdafx.h"

OrarApp::OrarApp(QWidget *parent)
    : QMainWindow(parent), secondpage(this),homepage(this,this)
{
    ui.setupUi(this);
    secondpage.hide();
    //homepage.hide();
    // layout()->
    //layout()->addWidget(&secondpage);
}

void OrarApp::ChangeViews(int viewid)
{
    if (viewid == 1)
       // layout()->addWidget(&homepage);
    if (viewid == 2) 
    {
        homepage.hide();
        secondpage.show();
       // layout()->removeWidget(&homepage);
        //layout()->addWidget(&secondpage);
    }
   
        
}
