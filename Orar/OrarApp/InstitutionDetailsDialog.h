#pragma once

#include "ui_InstitutionDetailsDialog.h"

class InstitutionDetailsDialog
  : public QDialog
  , public Ui::InstitutionDetailsDialog
{
  Q_OBJECT

public:
  InstitutionDetailsDialog(QWidget * parent = Q_NULLPTR);
  ~InstitutionDetailsDialog();
};
