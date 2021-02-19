#include "InstitutionDetailsDialog.h"
#include <QDateTimeEdit>

InstitutionDetailsDialog::InstitutionDetailsDialog(QWidget * parent)
  : QDialog(parent)
{
  setupUi(this);

  mStartHour->setTimeRange(QTime(8, 0, 0, 0), QTime(20, 0, 0, 0));
}

InstitutionDetailsDialog::~InstitutionDetailsDialog()
{
}
