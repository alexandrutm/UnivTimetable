#include "stdafx.h"
#include "InstituteDataView.h"
#include "Context.h"
#include "INavigator.h"
#include "InstituteData.h"

InstituteDataView::InstituteDataView(Context & aContext, INavigator * aNavigator, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
  , mNavigator(aNavigator)
{
  ui.setupUi(this);
}

InstituteDataView::~InstituteDataView()
{
}

void InstituteDataView::ClearData()
{
  ui.mStartHour->clear();
  ui.SchoolName->clear();
  ui.HoursPerDay->clear();
  ui.mFinishHour->clear();
}

void InstituteDataView::on_mSave_clicked()
{
  shared_ptr<InstituteData> newInstituteData = make_shared<InstituteData>(
    ui.SchoolName->text().toStdString(), ui.HoursPerDay->value(), ui.mStartHour->value(),
    ui.mFinishHour->value(), mContext.GenerateInstituteDataId());
  mContext.AddInstituteData(newInstituteData);
  mNavigator->ChangeView(INavigator::viewId::mainPage);
}
