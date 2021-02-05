#include "SubjectDialog.h"

SubjectDialog::SubjectDialog(QWidget * parent)
  : QDialog(parent)
{
  setupUi(this);
}

SubjectDialog::~SubjectDialog()
{
}

void SubjectDialog::on_Name_textChanged()
{
  Abbreviation->setText(Name->text().left(2));
}
