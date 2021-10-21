#pragma once

class TimeTableViewModel : public QAbstractTableModel
{
  Q_OBJECT

public:
  TimeTableViewModel(QObject * parent = nullptr);
  int      rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int      columnCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  QVariant headerData(int             section,
                      Qt::Orientation orientation,
                      int             role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

  void ClearData();
  void AddData(vector<vector<string>> aLessonsDetails);
  void FilterData(vector<string> pattern);

  vector<vector<string>> GetTiemtableData();

private:
  vector<vector<string>> mTimetable;
  vector<string>         mLessonsDetails;
};
