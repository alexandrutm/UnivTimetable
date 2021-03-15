#include "stdafx.h"
#include "TeacherConstraintDialog.h"
#include "Context.h"
#include "InstituteData.h"

TeacherConstraintDialog::TeacherConstraintDialog(Context & aContext, QWidget * parent)
  : QDialog(parent)
  , mContext(aContext)
{
  setupUi(this);

  mTeacherTableAviabileTime->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  mTeacherTableAviabileTime->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  mTeacherTableAviabileTime->setRowCount(mContext.GetInstituteData()->GetNumberOfHoursPerDay());
  mTeacherTableAviabileTime->setColumnCount(mContext.GetInstituteData()->GetNumberOfDayPerWeek());

  auto daysWeek = mContext.GetInstituteData()->GetDaysWeek();
  auto hoursDay = mContext.GetInstituteData()->GetHoursDay();

  for (int j = 0; j < mContext.GetInstituteData()->GetNumberOfDayPerWeek(); j++)
  {
    QTableWidgetItem * item = new QTableWidgetItem(QString::fromStdString(daysWeek[j]));
    mTeacherTableAviabileTime->setHorizontalHeaderItem(j, item);
  }

  for (int i = 0; i < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); i++)
  {
    QTableWidgetItem * item = new QTableWidgetItem(QString::fromStdString(hoursDay[i]));
    mTeacherTableAviabileTime->setVerticalHeaderItem(i, item);
  }

  for (int hourDay = 0; hourDay < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); hourDay++)
  {
    for (int dayWeek = 0; dayWeek < mContext.GetInstituteData()->GetNumberOfDayPerWeek(); dayWeek++)
    {
      QTableWidgetItem * item = new QTableWidgetItem(" ");
      item->setTextAlignment(Qt::AlignCenter);
      item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

      mTeacherTableAviabileTime->setItem(hourDay, dayWeek, item);
    }
  }

  mTeacherTableAviabileTime->setSelectionMode(QAbstractItemView::NoSelection);

  connect(mTeacherTableAviabileTime, SIGNAL(itemClicked(QTableWidgetItem *)), this,
          SLOT(ItemClicked(QTableWidgetItem *)));
  connect(mTeacherTableAviabileTime->horizontalHeader(), SIGNAL(sectionClicked(int)), this,
          SLOT(ColumnClicked(int)));
  connect(mTeacherTableAviabileTime->verticalHeader(), SIGNAL(sectionClicked(int)), this,
          SLOT(RowClicked(int)));
}

TeacherConstraintDialog::~TeacherConstraintDialog()
{
}

void TeacherConstraintDialog::ColumnClicked(int col)
{
  if (col >= 0 && col < mContext.GetInstituteData()->GetNumberOfDayPerWeek())
  {
    QString itemText = mTeacherTableAviabileTime->item(0, col)->text();

    itemText == "X" ? itemText = " " : itemText = "X";

    for (int row = 0; row < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); row++)
    {
      mTeacherTableAviabileTime->item(row, col)->setText(itemText);
    }
  }
}

void TeacherConstraintDialog::RowClicked(int row)
{
  if (row >= 0 && row < mContext.GetInstituteData()->GetNumberOfHoursPerDay())
  {
    QString itemText = mTeacherTableAviabileTime->item(row, 0)->text();

    itemText == "X" ? itemText = " " : itemText = "X";

    for (int col = 0; col < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); col++)
    {
      mTeacherTableAviabileTime->item(row, col)->setText(itemText);
    }
  }
}

void TeacherConstraintDialog::ItemClicked(QTableWidgetItem * item)
{
  QString itemText = item->text();
  itemText == "X" ? itemText = " " : itemText = "X";
  item->setText(itemText);
}
