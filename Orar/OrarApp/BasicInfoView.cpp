#include "BasicInfoView.h"
#include"INavigator.h"
#include"Context.h"
#include"BasicInfo.h"


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
	BasicInfo newBasicInfo;
	newBasicInfo.setSchoolName(ui.SchoolName->text().toStdString());
	newBasicInfo.setAcademicYear(ui.AcademicYear->text().toInt());
	newBasicInfo.setHoursPerDay(ui.HoursPerDay->value());
	newBasicInfo.setDayPerWeek(ui.DaysPerWeek->value());

	mContext.AddBasicInfo(newBasicInfo);

	mNavigator->ChangeView(INavigator::viewId::subjectView);
}