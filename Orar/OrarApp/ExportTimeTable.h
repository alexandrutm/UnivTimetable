#pragma once

class Context;

class ExportTimetable
{
public:
  ExportTimetable(Context & aContext);

  void PrintTimetable(vector<string> groupsNames);

private:
  Context & mContext;
};
