#include "HomeView.h"
#include"INavigator.h"


HomeView::HomeView(INavigator *navigator,QWidget *parent)
	: QWidget(parent),mNavigator(navigator)
{
	ui.setupUi(this);
}

HomeView::~HomeView()
{
}


void HomeView::on_pushButtonSecondView_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::secondpage);
}



