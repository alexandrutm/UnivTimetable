#include "stdafx.h"
#include "ExportTimeTable.h"
#include "../src/containers/Context.h"
#include "../src/containers/Group.h"
#include "../src/containers/InstituteData.h"
#include "../src/containers/Lesson.h"
#include "../src/containers/Placement.h"
#include "../src/containers/Room.h"
#include "../src/containers/Subject.h"
#include "../src/containers/Teacher.h"

ExportTimetable::ExportTimetable(Context & aContext)
  : mContext(aContext)
{
}

void ExportTimetable::PrintTimetable(vector<string> groupsNames)
{
  auto                               lessons     = mContext.GetLessons();
  auto                               daysWeek    = mContext.GetInstituteData()->GetDaysWeek();
  auto                               tableHeader = mContext.GetInstituteData()->GetHoursDay();
  vector<vector<shared_ptr<Lesson>>> lessonsFiltered(
    mContext.GetInstituteData()->GetNumberOfDaysPerWeek(), vector<shared_ptr<Lesson>>());

  // sort lessons by start time
  sort(lessons.begin(), lessons.end(),
       [](auto const first, auto second)
       {
         return first->GetPlacement().GetTimeSlot().GetStartTime() <
                second->GetPlacement().GetTimeSlot().GetStartTime();
       });

  for (auto lesson : lessons)
  {
    for (auto groupName : groupsNames)
    {
      if (lesson->GetGroup()->GetName() == groupName)
      {
        lessonsFiltered[lesson->GetPlacement().GetTimeSlot().GetDayOfWeek()].push_back(lesson);
      }
    }
  }

  tableHeader.insert(tableHeader.begin(), " Days \\ Hours ");

  ofstream myfile;
  myfile.open(groupsNames.front() + "-ttable.html");

  myfile
    << " <!DOCTYPE html>\n <html>\n <head>\n<style>\n"
    << " table, th, td {\n border : 1px solid black;\nfont-size: 20px; face=\"Times New Roman\""
    << "\n}\n</style>\n</head>\n<body>\n"
    << "<H1><FONT  COLOR=\"DARKCYAN\"><CENTER>" << groupsNames.front() << "</FONT></H1>"
    << "<table style=\"width:100%\">\n"
    << "<tr>\n";

  for (auto head : tableHeader)
  {
    myfile << "<th>" << head << "</th>\n";
  }
  myfile << "</tr>\n";

  // sort lessons by day
  int dayNumber = 0;
  // print lessons
  for (auto day : lessonsFiltered)
  {
    myfile << "<tr>\n <td align=\"center\">" << daysWeek[dayNumber];
    int i    = 0;
    int size = 0;

    for (auto lesson : day)
    {
      size++;
      // int lessonStartTime = lesson->GetPlacement().GetTimeSlot().GetStartTime();
      // int lessonEndTime   = lesson->GetPlacement().GetTimeSlot().GetEndTime();
      // int dayOfWeek       = lesson->GetPlacement().GetTimeSlot().GetDayOfWeek();

      string lessonRoom = lesson->GetPlacement().GetRoom()->GetName();
      string lessonTeacher =
        lesson->GetTeacher()->GetFirstName() + " " + lesson->GetTeacher()->GetLastName();
      string lessonGroup   = lesson->GetGroup()->GetName();
      string lessonSubject = lesson->GetSubject()->GetName();

      for (i; i < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); i++)
      {
        if (i == lesson->GetPlacement().GetTimeSlot().GetStartTime())
        {
          myfile << "\n <td colspan=" << lesson->GetDuration() << "align=\"center\">"
                 << lessonSubject + " " + lessonGroup + " " + lessonTeacher + " " + lessonRoom;
          i += lesson->GetDuration();

          // complete row with "---"
          if (size == day.size())
          {
            for (i; i < mContext.GetInstituteData()->GetNumberOfHoursPerDay(); i++)
            {
              myfile << " <td align=\"center\">---";
            }
          }

          break;
        }
        else
          myfile << " <td align=\"center\">---";
      }

      // check if it is another lesson in this interval
    }

    myfile << "\n</tr>";

    dayNumber++;
  }

  myfile << "</table>\n</body>\n</html>";
}
