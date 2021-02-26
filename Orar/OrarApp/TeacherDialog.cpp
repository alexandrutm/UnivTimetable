#include "TeacherDialog.h"

TeacherDialog::TeacherDialog(QWidget * parent)
  : QDialog(parent)
{
  setupUi(this);
}

TeacherDialog::~TeacherDialog()
{
}

void TeacherDialog::EditEntry(QString fName, QString lName)
{
  this->mFirstName->setText(fName);
  this->mLastName->setText(lName);
}
