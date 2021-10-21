#include "stdafx.h"
#include "TransformLessonDetails.h"
#include "src/containers/Group.h"
#include "src/containers/InstituteData.h"
#include "src/containers/Lesson.h"
#include "src/containers/Placement.h"
#include "src/containers/Room.h"
#include "src/containers/Subject.h"
#include "src/containers/Teacher.h"
#include "src/containers/TimeSlot.h"

vector<vector<string>> TransformLessonDetails::LessonsDataToString(InstituteData * aInstituteData,
                                                                   Solution        aSolution)
{
  auto lessons = aSolution.GetAssignedLessons();

  // sort lessons by start time
  sort(lessons.begin(), lessons.end(),
       [](Lesson * first, Lesson * second)
       {
         return first->GetPlacement().GetTimeSlot().GetStartTime() <
                second->GetPlacement().GetTimeSlot().GetStartTime();
       });

  vector<vector<string>> lessonsDetails(5);

  auto hoursDay = aInstituteData->GetHoursDay();

  for (auto lesson : lessons)
  {
    int lessonStartTime = lesson->GetPlacement().GetTimeSlot().GetStartTime();
    int lessonEndTime   = lesson->GetPlacement().GetTimeSlot().GetEndTime();

    string lessonRoom = lesson->GetPlacement().GetRoom()->GetName();
    string lessonTeacher =
      lesson->GetTeacher()->GetFirstName() + " " + lesson->GetTeacher()->GetLastName();
    string lessonGroup   = lesson->GetGroup()->GetName();
    string lessonSubject = lesson->GetSubject()->GetName();

    switch (lesson->GetPlacement().GetTimeSlot().GetDayOfWeek())
    {
    case 0:
      lessonsDetails[0].push_back(hoursDay[lessonStartTime] + "-" + hoursDay[lessonEndTime] + " " +
                                  lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                                  lessonSubject + "\n");
      break;
    case 1:
      lessonsDetails[1].push_back(hoursDay[lessonStartTime] + "-" + hoursDay[lessonEndTime] + " " +
                                  lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                                  lessonSubject + "\n");
      break;
    case 2:
      lessonsDetails[2].push_back(hoursDay[lessonStartTime] + "-" + hoursDay[lessonEndTime] + " " +
                                  lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                                  lessonSubject + "\n");
      break;
    case 3:
      lessonsDetails[3].push_back(hoursDay[lessonStartTime] + "-" + hoursDay[lessonEndTime] + " " +
                                  lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                                  lessonSubject + "\n");
      break;
    case 4:
      lessonsDetails[4].push_back(hoursDay[lessonStartTime] + "-" + hoursDay[lessonEndTime] + " " +
                                  lessonRoom + " " + lessonTeacher + " " + lessonGroup + " " +
                                  lessonSubject + "\n");
      break;
    }
  }

  return lessonsDetails;
}
