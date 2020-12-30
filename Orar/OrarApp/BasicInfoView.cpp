#include "BasicInfoView.h"
#include"INavigator.h"
#include"Context.h"


BasicInfoView::BasicInfoView(INavigator *navigator, Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(navigator),mContext(aContext)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
}

BasicInfoView::~BasicInfoView()
{
}

void BasicInfoView::on_NextButtonBasicInfo_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::subjectView);
}