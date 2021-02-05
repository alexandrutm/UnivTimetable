#include "ClassesDialog.h"

ClassesDialog::ClassesDialog(QWidget * parent)
  : QDialog(parent)
{
  setupUi(this);
}

void ClassesDialog::on_Name_textChanged()
{
  Abbreviation->setText(Name->text().left(2));
}

ClassesDialog::~ClassesDialog()
{
}
