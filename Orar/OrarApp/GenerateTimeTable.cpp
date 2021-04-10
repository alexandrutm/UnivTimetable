#include "stdafx.h"
#include "GenerateTimeTable.h"
#include "Context.h"
#include "Group.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Room.h"
#include "Teacher.h"
#include "TimeConstraint.h"

GenerateTimeTable::GenerateTimeTable(Context & aContext)
  : mContext(aContext)
{
  const int nrOfDays  = mContext.GetInstituteData()->GetNumberOfDaysPerWeek();
  const int nrOfHours = mContext.GetInstituteData()->GetNumberOfHoursPerDay();

  timeSlotMatrix.resize(nrOfDays, vector<int>(nrOfHours));
}

bool GenerateTimeTable::GetNextAvailableTimeSlot(Lesson * aLesson)
{
  Teacher * teacher      = aLesson->GetTeacher();
  Group *   group        = aLesson->GetGroup();
  auto      rooms        = mContext.GetRooms();
  Room *    selectedRoom = nullptr;
  TimeSlot  timeSlot;

  for (int i = 0; i < timeSlotMatrix.size(); i++)
  {
    for (int j = 0; j < timeSlotMatrix[i].size(); j++)
    {
      // find a slot equal to duration of lesson
      // nu se poate incepe un curs la ora 19. nu se poate pune un curs pe 2 zile
      if (aLesson->GetDuration() == 2 && j < timeSlotMatrix[i].size() - 1)
      {
        // find a room available
        for (auto room : rooms)
        {
          if (room->GetCapacity() >= aLesson->GetGroup()->GetNumberOfStudents() &&
              room->IsAvailable(pair<int, int>(i, j)) &&
              room->IsAvailable(pair<int, int>(i, j + 1)))
          {
            selectedRoom = room.get();
          }
        }

        // find a teacher and a group available
        if (teacher->IsAvailable(pair<int, int>(i, j)) &&
            teacher->IsAvailable(pair<int, int>(i, j + 1)) &&
            group->IsAvailable(pair<int, int>(i, j)) &&
            group->IsAvailable(pair<int, int>(i, j + 1)))
        {
          timeSlot = TimeSlot(i, j, j + 1);

          if (selectedRoom && timeSlot.IsValid())
          {
            // make not available

            teacher->ChangeAvailability(pair<int, int>(i, j));
            teacher->ChangeAvailability(pair<int, int>(i, j + 1));

            group->ChangeAvailability(pair<int, int>(i, j));
            group->ChangeAvailability(pair<int, int>(i, j + 1));

            // make room not available
            selectedRoom->ChangeAvailability(pair<int, int>(i, j));
            selectedRoom->ChangeAvailability(pair<int, int>(i, j + 1));

            aLesson->SetTimeSlot(timeSlot);
            aLesson->SetRoom(selectedRoom);

            return true;
          }
        }
      }
    }
  }

  return false;
}

bool GenerateTimeTable::IsGenerated()
{
  auto     lessons = mContext.GetLessons();
  TimeSlot timeSlot;

  // we need to asign a room and a time slot to every lesson
  for (auto l : lessons)
  {
    if (!GetNextAvailableTimeSlot(l.get()))
    {
      // switch lessons to find a slot for each lesson
    }
    // if we find a time slot for this lesson we asign it and search for a room
  }

  // for a timetable generated with succes every lesson should have a room and a timeslot

  return true;
}
