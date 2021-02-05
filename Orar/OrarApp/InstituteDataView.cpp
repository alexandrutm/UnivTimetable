#include "stdafx.h"
#include "InstituteDataView.h"
#include "Context.h"
#include "INavigator.h"
#include "InstituteData.h"

InstituteDataView::InstituteDataView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);
}

InstituteDataView::~InstituteDataView()
{
}

void InstituteDataView::ClearData()
{
  ui.AcademicYear->clear();
  ui.SchoolName->clear();
  ui.HoursPerDay->clear();
  ui.DaysPerWeek->clear();
}

void InstituteDataView::on_Save_clicked()
{
  shared_ptr<InstituteData> newInstituteData = make_shared<InstituteData>(
    ui.SchoolName->text().toStdString(), ui.AcademicYear->text().toInt(), ui.HoursPerDay->value(),
    ui.DaysPerWeek->value(), mContext.GenerateInstituteDataId());
  mContext.AddInstituteData(newInstituteData);
}
