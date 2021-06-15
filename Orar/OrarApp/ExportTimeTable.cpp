#include "stdafx.h"
#include "ExportTimeTable.h"
#include "Context.h"
#include "Group.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Placement.h"
#include "Room.h"
#include "Subject.h"
#include "Teacher.h"

ExportTimetable::ExportTimetable(Context & aContext)
  : mContext(aContext)
{
}

vector<vector<string>> ExportTimetable::FilterData(vector<string> pattern)
{
  vector<vector<string>> mLessonsDetails(
    mContext.GetInstituteData()->GetNumberOfDaysPerWeek(),
    vector<string>(mContext.GetInstituteData()->GetNumberOfHoursPerDay()));

  /* if (!pattern.empty())
   {
     int i = 0;

     for (auto day : )
     {
       int j = 0;

       for (auto lesson : day)
       {
         for (auto groupName : pattern)
         {
           auto pos = lesson.find(groupName);
           if (pos != std::string::npos)
           {
             mLessonsDetails[i][j] = lesson;
             j++;
           }
         }
       }
       i++;
     }
   }*/

  return mLessonsDetails;
}

void ExportTimetable::PrintTimetable(vector<string> groupsNames)
{
  auto lessons = mContext.GetLessons();

  // sort lessons by start time
  sort(lessons.begin(), lessons.end(),
       [](auto const first, auto second)
       {
         return first->GetPlacement().GetTimeSlot().GetStartTime() <
                second->GetPlacement().GetTimeSlot().GetStartTime();
       });

  vector<shared_ptr<Lesson>> lessonsFiltered;

  for (auto lesson : lessons)
  {
    bool found = false;
    for (auto groupName : groupsNames)
    {
      if (lesson->GetGroup()->GetName() == groupName)
      {
        lessonsFiltered.push_back(lesson);
      }
    }
  }

  auto header = mContext.GetInstituteData()->GetDaysWeek();

  header.insert(header.begin(), "Hours \\ Days");

  ofstream myfile;
  myfile.open("timetable.html");

  myfile << " <!DOCTYPE html>\n <html>\n <head>\n<style>\n"
         << " table, th, td {\n border : 1px solid black;\n}\n</style>\n</head>\n<body>\n"
         << "<table style=\"width:100%\">\n"
         << "<tr>\n";

  for (auto head : header)
  {
    myfile << "    <th>" << head << "</th>\n";
  }
  myfile << "  </tr>\n";

  // print lessons
  for (auto lesson : lessons)
  {
    for (auto groupName : groupsNames)
    {
      if (lesson->GetGroup()->GetName() == groupName)
      {
        int lessonStartTime = lesson->GetPlacement().GetTimeSlot().GetStartTime();
        int lessonEndTime   = lesson->GetPlacement().GetTimeSlot().GetEndTime();
        int day             = lesson->GetPlacement().GetTimeSlot().GetDayOfWeek();

        string lessonRoom = lesson->GetPlacement().GetRoom()->GetName();
        string lessonTeacher =
          lesson->GetTeacher()->GetFirstName() + " " + lesson->GetTeacher()->GetLastName();
        string lessonGroup   = lesson->GetGroup()->GetName();
        string lessonSubject = lesson->GetSubject()->GetName();

        break;
      }
    }
  }

  myfile << "</table >\n</body>\n</html>";
}
