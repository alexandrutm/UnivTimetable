#include"stdafx.h"
#include "BasicInfoView.h"
#include"INavigator.h"
#include"Context.h"
#include"BasicInfo.h"


BasicInfoView::BasicInfoView( Context& aContext,QWidget *parent)
	: QWidget(parent),mContext(aContext)
{
	ui.setupUi(this);
}

BasicInfoView::~BasicInfoView()
{
}

void BasicInfoView::ClearData()
{
	ui.AcademicYear->clear();
	ui.SchoolName->clear();
	ui.HoursPerDay->clear();
	ui.DaysPerWeek->clear();
}

void BasicInfoView::on_Save_clicked()
{
	shared_ptr<BasicInfo> newBasicInfo = make_shared<BasicInfo>(ui.SchoolName->text().toStdString(), ui.AcademicYear->text().toInt(), ui.HoursPerDay->value(), ui.DaysPerWeek->value());
	mContext.AddBasicInfo(newBasicInfo);
}

