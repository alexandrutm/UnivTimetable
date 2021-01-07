#include "BasicInfoView.h"
#include"INavigator.h"
#include"Context.h"
#include"BasicInfo.h"


BasicInfoView::BasicInfoView(INavigator *navigator, Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(navigator),mContext(aContext)
{
	ui.setupUi(this);
}

BasicInfoView::~BasicInfoView()
{
}

void BasicInfoView::on_Next_clicked()
{
	shared_ptr<BasicInfo> newBasicInfo = make_shared<BasicInfo>(ui.SchoolName->text().toStdString(), ui.AcademicYear->text().toInt(), ui.HoursPerDay->value(), ui.DaysPerWeek->value());
	mContext.AddBasicInfo(newBasicInfo);

	mNavigator->ChangeView(INavigator::viewId::subjectView);
}

void BasicInfoView::on_Back_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::secondpage);
}