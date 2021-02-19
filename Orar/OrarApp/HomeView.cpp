#include "stdafx.h"
#include "HomeView.h"
#include "Context.h"
#include "INavigator.h"
#include "InstituteData.h"
#include "InstitutionDetailsDialog.h"

HomeView::HomeView(Context & aContext, INavigator * navigator, QWidget * parent)
  : QWidget(parent)
  , mNavigator(navigator)
  , mContext(aContext)
{
  ui.setupUi(this);
}

HomeView::~HomeView()
{
}

void HomeView::on_mCreateNewTimetable_clicked()
{
  InstitutionDetailsDialog institutionDialog = new InstitutionDetailsDialog(this);

  if (institutionDialog.exec())
  {
    QString name        = institutionDialog.SchoolName->text();
    QTime   startHour   = institutionDialog.mStartHour->time();
    int     hoursPerDay = institutionDialog.mHoursPerDay->value();

    if (!name.isEmpty())
    {
      shared_ptr<InstituteData> InstitutionData = make_shared<InstituteData>(
        name.toStdString(), (startHour.toString()).toStdString(), hoursPerDay);
      mContext.AddInstituteData(InstitutionData);

      mNavigator->ChangeView(INavigator::viewId::mainPage);
    }
    else
    {
      QMessageBox::about(&institutionDialog, "Error", "You need to give a name to timetable");
    }
  }
}
