#include "SecondView.h"
#include "INavigator.h"

SecondView::SecondView(INavigator* navigator,QWidget *parent)
	: QWidget(parent),mNavigator(navigator)
{
	ui.setupUi(this);
}

SecondView::~SecondView()
{
}

void SecondView::on_pushButtonBasicData_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::thirdpage);
}

void SecondView::on_backHome_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::homepage);
}