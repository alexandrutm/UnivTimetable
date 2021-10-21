#include "stdafx.h"
#include "SelectPlacement.h"
#include "src/containers/Context.h"
#include "src/containers/Group.h"
#include "src/containers/InstituteData.h"
#include "src/containers/Lesson.h"
#include "src/containers/Room.h"
#include "src/containers/Teacher.h"

SelectPlacement::SelectPlacement(Context & aContext)
  : mContext(aContext)
{
  const int nrOfDays  = mContext.GetInstituteData()->GetNumberOfDaysPerWeek();
  const int nrOfHours = mContext.GetInstituteData()->GetNumberOfHoursPerDay();

  mTimeSlotMatrix.resize(nrOfDays, vector<int>(nrOfHours));
}

Placement SelectPlacement::GetPlacement(Lesson * aLesson)
{
  auto roomsWithEnoughCapacity = GetRoomsSortedByCapacity(aLesson);

  // no room available  for this lesson
  if (roomsWithEnoughCapacity.size() == 0)
    return Placement();

  // we assing the rooms in ascending order by capacity
  for (auto room : roomsWithEnoughCapacity)
  {
    auto availableTimeSlots = GetAvailableTimeslots(aLesson, room);

    // while we find a valid placement
    while (availableTimeSlots.size() > 0)
    {
      auto timeslot = availableTimeSlots.back();
      availableTimeSlots.pop_back();

      if (!aLesson->IsVisited(Placement(room, timeslot)))
      {
        if (aLesson->GetPlacement().IsValid())
        {
          MakePlacementAvailable(aLesson);
        }

        // mark current found placement as unavailable
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

vector<TimeSlot> SelectPlacement::GetAvailableTimeslots(Lesson * aLesson, Room * aRoom)
{
  vector<TimeSlot> availableTimeSlots;
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
      bool roomUnavailable    = false;

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
        // check for all sub-nodes an parent nodes
        if (!aLesson->GetGroup()->CheckChildAvailability(pair<int, int>(day, hourCheck)) ||
            !aLesson->GetGroup()->CheckParentAvailability(pair<int, int>(day, hourCheck)))
        {
          groupUnavailable = true;
          break;
        }

        if (!aRoom->IsAvailable(pair<int, int>(day, hourCheck)))
        {
          roomUnavailable = true;
          break;
        }
      }

      if (!teacherUnavailable && !groupUnavailable && !roomUnavailable)
      {
        // we find a slot available for teacher and group
        // save slot into vector
        availableTimeSlots.emplace_back(TimeSlot(day, currentHour, currentHour + lessonDuration));
      }
    }
  }

  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(availableTimeSlots.begin(), availableTimeSlots.end(),
          std::default_random_engine(static_cast<unsigned>(seed)));

  return availableTimeSlots;
}

vector<Room *> SelectPlacement::GetRoomsSortedByCapacity(Lesson * aLesson)
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

  // sort rooms by capacity
  sort(roomsWithEnoughCapacity.begin(), roomsWithEnoughCapacity.end(),
       [](Room * first, Room * second)
       {
         return first->GetCapacity() < second->GetCapacity();
       });
  //
  return roomsWithEnoughCapacity;
}

void SelectPlacement::MakePlacementAvailable(Lesson * aLesson)
{
  // if we found another placement for this lesson we make available previous placement and
  // mark last placement as visited

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
