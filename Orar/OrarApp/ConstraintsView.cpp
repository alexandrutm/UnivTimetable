#include "stdafx.h"
#include "ConstraintsView.h"
#include "AviabilityConstraintDialog.h"
#include "Context.h"
#include "InstituteData.h"
#include "TimeConstraint.h"

ConstraintsView::ConstraintsView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  addButtonMenu = new QMenu();

  addButtonMenu->addAction("Teacher Constraints", this, SLOT(AddTeacherConstraint()));
}

ConstraintsView::~ConstraintsView()
{
  delete addButtonMenu;
}

void ConstraintsView::on_mAdd_clicked()
{
  addButtonMenu->popup(QCursor::pos());
}

void ConstraintsView::on_mEdit_clicked()
{
}

void ConstraintsView::on_mDelete_clicked()
{
}

void ConstraintsView::AddTeacherConstraint()
{
  AviabilityConstraintDialog ConstraintDialog(mContext, this);

  if (ConstraintDialog.exec())
  {
    vector<pair<int, int>> dayAndHour;

    for (int day = 0; day < mContext.GetInstituteData()->GetNumberOfDayPerWeek(); day++)
      for (int hour = 0; hour < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); hour++)
        if (ConstraintDialog.mTeacherTableAviabileTime->item(hour, day)->text() == "X")
        {
          dayAndHour.push_back(make_pair(day, hour));
        }

    int currentSelectedRow = ui.mConstraintsList->selectionModel()->currentIndex().row();

    unique_ptr<TimeConstraint> constraint =
      make_unique<TimeConstraint>(dayAndHour, mContext.GetTeacherByIndex(currentSelectedRow));
    mContext.AddConstraint(std::move(constraint));
  }

  else
  {
    QMessageBox::information(this, "Select item", "You need to select one item",
                             QMessageBox::StandardButton::Close);
  }
}
