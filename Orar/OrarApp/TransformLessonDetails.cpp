#include "stdafx.h"
#include "TransformLessonDetails.h"
#include "Group.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Room.h"
#include "Solution.h"
#include "Subject.h"
#include "Teacher.h"
#include "TimeSlot.h"

vector<string> TransformLessonDetails::GetLessonDetails(InstituteData * aInstituteData,
                                                        Solution *      aSolution)
{
  auto lessons = aSolution->GetAssignedLessons();

  vector<string> lessonsDetails(5);

  auto hoursDay = aInstituteData->GetHoursDay();

  for (auto lesson : lessons)
  {
    int lessonStartTime = lesson->GetPlacement().GetTimeSlot().GetStartTime();
    int lessonEndTime   = lesson->GetPlacement().GetTimeSlot().GetEndTime();

    string lessonRoom    = lesson->GetPlacement().GetRoom()->GetName();
    string lessonTeacher = lesson->GetTeacher()->GetLastName();
    string lessonGroup   = lesson->GetGroup()->GetName();
    string lessonSubject = lesson->GetSubject()->GetName();

    switch (lesson->GetPlacement().GetTimeSlot().GetDayOfWeek())
    {
    case 0:
      lessonsDetails[0].append(hoursDay[lessonStartTime] + " " + hoursDay[lessonEndTime] + " " +
                               lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                               lessonSubject + "\n");
      break;
    case 1:
      lessonsDetails[1].append(hoursDay[lessonStartTime] + " " + hoursDay[lessonEndTime] + " " +
                               lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                               lessonSubject + "\n");
      break;
    case 2:
      lessonsDetails[2].append(hoursDay[lessonStartTime] + " " + hoursDay[lessonEndTime] + " " +
                               lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                               lessonSubject + "\n");
      break;
    case 3:
      lessonsDetails[3].append(hoursDay[lessonStartTime] + " " + hoursDay[lessonEndTime] + " " +
                               lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                               lessonSubject + "\n");
      break;
    case 4:
      lessonsDetails[4].append(hoursDay[lessonStartTime] + " " + hoursDay[lessonEndTime] + " " +
                               lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                               lessonSubject + "\n");
      break;
    }
  }

  return lessonsDetails;
}
