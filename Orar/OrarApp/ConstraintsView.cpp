#include "stdafx.h"
#include "ConstraintsView.h"
#include "ConstraintListModel.h"
#include "Context.h"
#include "InstituteData.h"
#include "Teacher.h"
#include "TeacherConstraintDialog.h"
#include "TeacherTableModel.h"
#include "TimeConstraint.h"

ConstraintsView::ConstraintsView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  mListModel    = new ConstraintListModel(mContext);
  mTeacherModel = new TeacherTableModel(mContext);
  addButtonMenu = new QMenu();

  addButtonMenu->addAction("Teacher Constraints", this, SLOT(AddTeacherConstraint()));

  connect(ui.mConstraintsList, SIGNAL(clicked(QModelIndex)), this,
          SLOT(ListItemChanged(QModelIndex)));

  ui.mConstraintsList->setModel(mListModel);
}

ConstraintsView::~ConstraintsView()
{
  delete addButtonMenu;
  delete mTeacherModel;
  delete mListModel;
}

void ConstraintsView::on_mAdd_clicked()
{
  addButtonMenu->popup(QCursor::pos());
}

void ConstraintsView::on_mDelete_clicked()
{
  int selectedRow = ui.mConstraintsList->currentIndex().row();

  mListModel->removeRows(selectedRow, selectedRow);
}

void ConstraintsView::ListItemChanged(QModelIndex index)
{
  if (!index.isValid())
    ui.mConstraintDetails->setPlainText("");
  else
  {
    QString detailsConstraint("Not aviable hours: ");
    auto    daysConstraint =
      mContext.GetConstraintByIndex(index.row())->GetConstraintDetailsDayAndHour();
    auto instituteDaysWeek = mContext.GetInstituteData()->GetDaysWeek();
    auto instituteHoursDay = mContext.GetInstituteData()->GetHoursDay();

    for (int i = 0; i < daysConstraint.size(); i++)
    {
      detailsConstraint.append(QString::fromStdString(instituteDaysWeek[daysConstraint[i].first]));
      detailsConstraint.append(
        QString::fromStdString(": " + instituteHoursDay[daysConstraint[i].second] + "; "));
    }

    ui.mConstraintDetails->setPlainText(detailsConstraint);
  }
}

void ConstraintsView::AddTeacherConstraint()
{
  TeacherConstraintDialog ConstraintDialog(mContext, this);

  ConstraintDialog.mTeacher->setModel(mTeacherModel);
  int teacherSize = static_cast<int>(mContext.GetTeacherSize());

  if (teacherSize == 0)
  {
    QMessageBox::information(this, "Insert Teacher",
                             "You need to insert a teacher first and then add constraint",
                             QMessageBox::StandardButton::Close);
    return;
  }

  if (ConstraintDialog.exec())
  {
    vector<pair<int, int>> dayAndHour;

    int currentSelectedRow = ConstraintDialog.mTeacher->currentIndex();

    for (int day = 0; day < mContext.GetInstituteData()->GetNumberOfDaysPerWeek(); day++)
      for (int hour = 0; hour < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); hour++)
        if (ConstraintDialog.mTeacherTableAviabileTime->item(hour, day)->text() == "X")
        {
          dayAndHour.push_back(make_pair(day, hour));
          mContext.GetTeacherByIndex(currentSelectedRow)->ChangeAvailability(make_pair(day, hour));
        }

    unique_ptr<TimeConstraint> constraint =
      make_unique<TimeConstraint>(dayAndHour, mContext.GetTeacherByIndex(currentSelectedRow));
    mContext.AddConstraint(std::move(constraint));

    int constraintSize = static_cast<int>(mContext.GetConstraintSize());

    mListModel->insertRows(constraintSize, constraintSize);
  }
}
