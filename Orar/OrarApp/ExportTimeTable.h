#pragma once

class Context;

class ExportTimetable
{
public:
  ExportTimetable(Context & aContext);

  vector<vector<string>> FilterData(vector<string> pattern);
  void                   PrintTimetable(vector<string> groupsNames);

private:
  Context & mContext;
};
