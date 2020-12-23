#include "HomePage.h"
#include"INavigator.h"


HomePage::HomePage(INavigator *navigator,QWidget *parent)
	: QWidget(parent),mNavigator(navigator)
{
	ui.setupUi(this);
}

HomePage::~HomePage()
{
}


void HomePage::on_pushButtonSecondView_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::secondpage);
}



