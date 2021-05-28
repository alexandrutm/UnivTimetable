#include "stdafx.h"
#include "SelectPlacement.h"
#include "Context.h"
#include "Group.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Room.h"
#include "Teacher.h"

SelectPlacement::SelectPlacement(Context & aContext)
  : mContext(aContext)
{
  const int nrOfDays  = mContext.GetInstituteData()->GetNumberOfDaysPerWeek();
  const int nrOfHours = mContext.GetInstituteData()->GetNumberOfHoursPerDay();

  mTimeSlotMatrix.resize(nrOfDays, vector<int>(nrOfHours));
}

Placement SelectPlacement::GetPlacement(Lesson * aLesson)
{
  auto           rooms = mContext.GetRooms();
  vector<Room *> roomsWithEnoughCapacity;

  // find room with enough capacity to hold this lesson
  for (auto room : rooms)
  {
    if (room->GetCapacity() >= aLesson->GetGroup()->GetNumberOfStudents())
    {
      roomsWithEnoughCapacity.push_back(room.get());
    }
  }

  auto availableTimeSlotsTeacherGroup = GetAvailableTimeslotForTeacherAndGroup(aLesson);

  // no time slot or room available  for this lesson
  if (availableTimeSlotsTeacherGroup.size() == 0 || roomsWithEnoughCapacity.size() == 0)
    return Placement();

  // pick a pseudo-random timeslot and check for a pseudo-random room with enough capacity available
  // otherwise pick another timeslot and check again
  srand(time(NULL));
  while (true)
  {
    bool roomUnavailable = false;

    int randomTimeSlot = rand() % availableTimeSlotsTeacherGroup.size();
    int randomRoom     = rand() % roomsWithEnoughCapacity.size();

    auto timeslot = availableTimeSlotsTeacherGroup[randomTimeSlot];
    auto room     = roomsWithEnoughCapacity[randomRoom];

    if (!aLesson->IsVisited(Placement(room, timeslot)))
    {
      // room check
      for (int startTime = timeslot.GetStartTime(); startTime < timeslot.GetEndTime(); startTime++)
      {  // sometimes lesson lasts 4 hour(lab) check hour between start hour and end hour to be
         // available
        if (!room->IsAvailable(pair<int, int>(timeslot.GetDayOfWeek(), startTime)))
        {
          roomUnavailable = true;
        }
      }

      // return an available placement for this lesson and make teacher,group and room unavailable
      // int this time slot
      if (!roomUnavailable)
      {
        // if we found another placement for this lesson we make available previous placement and
        // we make unavailable current placement we make last placement visited
        if (aLesson->GetPlacement().IsValid())
        {
          for (auto duration = aLesson->GetPlacement().GetTimeSlot().GetStartTime();
               duration < aLesson->GetPlacement().GetTimeSlot().GetEndTime(); duration++)
          {
            aLesson->AddVisitedPlacement(aLesson->GetPlacement());

            aLesson->GetTeacher()->MakeAvailableTimeSlot(
              pair<int, int>(aLesson->GetPlacement().GetTimeSlot().GetDayOfWeek(), duration));

            aLesson->GetPlacement().GetRoom()->MakeAvailableTimeSlot(
              pair<int, int>(aLesson->GetPlacement().GetTimeSlot().GetDayOfWeek(), duration));

            aLesson->GetGroup()->MakeAvailableTimeSlot(
              pair<int, int>(aLesson->GetPlacement().GetTimeSlot().GetDayOfWeek(), duration));
          }
        }

        for (int startTime = timeslot.GetStartTime(); startTime < timeslot.GetEndTime();
             startTime++)
        {
          room->MakeUnavailableTimeSlot(pair<int, int>(timeslot.GetDayOfWeek(), startTime));

          aLesson->GetTeacher()->MakeUnavailableTimeSlot(
            pair<int, int>(timeslot.GetDayOfWeek(), startTime));

          aLesson->GetGroup()->MakeUnavailableTimeSlot(
            pair<int, int>(timeslot.GetDayOfWeek(), startTime));
        }
        // return valid placement
        return Placement(room, timeslot);
      }
    }
  }
  return Placement();
}

vector<TimeSlot> SelectPlacement::GetAvailableTimeslotForTeacherAndGroup(Lesson * aLesson)
{
  vector<TimeSlot> availableTimeSlotsTeacherGroup;
  int              lessonDuration = aLesson->GetDuration();
  // search for a time slot equal to lesson duration available for teacher and group lesson
  for (int day = 0; day < mTimeSlotMatrix.size(); day++)
  {
    // to place a lesson from 18 to 20 evening if duration is 2 hours we can't check from 19 oclock
    for (int currentHour = 0; currentHour < mTimeSlotMatrix[day].size() - lessonDuration;
         currentHour++)
    {
      bool teacherUnavailable = false;
      bool groupUnavailable   = false;

      // iterate ahead to check available hours
      for (int hourCheck = currentHour; hourCheck < currentHour + lessonDuration; hourCheck++)
      {
        // check teacher availability
        if (!aLesson->GetTeacher()->IsAvailable(pair<int, int>(day, hourCheck)))
        {
          teacherUnavailable = true;
          break;
        }
        // check group availability
        if (!aLesson->GetGroup()->IsAvailable(pair<int, int>(day, hourCheck)))
        {
          groupUnavailable = true;
          break;
        }
      }

      if (!teacherUnavailable && !groupUnavailable)
      {
        // we find a slot available for teacher and group
        // save slot into vector
        availableTimeSlotsTeacherGroup.emplace_back(
          TimeSlot(day, currentHour, currentHour + lessonDuration));
      }
    }
  }
  return availableTimeSlotsTeacherGroup;
}
