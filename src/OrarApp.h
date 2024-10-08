#pragma once

#include "src/containers/Context.h"
#include "src/interface/INavigator.h"
#include "ui/dialogs/AddDataDialog.h"
#include "ui/views/HomeView.h"
#include "ui_OrarApp.h"

class SortFilterProxyModel;
class TimeTableViewModel;
class TreeModel;

class OrarApp
  : public QMainWindow
  , public INavigator
{
  Q_OBJECT

public:
  OrarApp(QWidget * parent = Q_NULLPTR);
  void CreateModels();
  ~OrarApp();
  void ChangeView(INavigator::viewId theView);
  void ChangeStatus(string);
  void ClassChanged();

private slots:
  // toolbar actions
  void on_mNew_triggered();
  void on_mSave_triggered();
  void on_mOpen_triggered();
  void on_mData_triggered();
  void on_mGenerate_triggered();
  void on_mExport_triggered();
  void on_mInstitutionData_triggered();

private:
  Ui::OrarAppClass ui;

  Context mContext;

  unique_ptr<TimeTableViewModel> mTableModel;
  shared_ptr<TreeModel>          mGroupModel;

  AddDataDialog mDataDialog;

  HomeView mHomeView;
};
