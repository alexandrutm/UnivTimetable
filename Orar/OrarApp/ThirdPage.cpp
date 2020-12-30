#include "ThirdPage.h"
#include"INavigator.h"
#include"Context.h"


ThirdPage::ThirdPage(INavigator *navigator, Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(navigator),mContext(aContext)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
}

ThirdPage::~ThirdPage()
{
}

void ThirdPage::on_NextButtonBasicInfo_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::subjectView);
}