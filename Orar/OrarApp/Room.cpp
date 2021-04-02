#include "stdafx.h"
#include "Room.h"

Room::Room(string aName, int aCapacity, int aId)
  : mName(aName)
  , mCapacity(aCapacity)
  , mId(aId)
{
}

bool Room::operator==(const Room & aRoom)
{
  return mId == aRoom.mId;
}

Room & Room::operator=(const Room & aRoom)
{
  if (this != &aRoom)
  {
    this->mName = aRoom.mName;
    this->mId   = aRoom.mId;
  }
  return *this;
}

void Room::SetName(string aNume)
{
  mName = aNume;
}

string Room::GetNume()
{
  return mName;
}

void Room::SetCapacity(int aCapacity)
{
  mCapacity = aCapacity;
}

int Room::GetCapacity()
{
  return mCapacity;
}

int Room::GetId()
{
  return mId;
}

void Room::ChangeAvailability(pair<int, int> availability)
{
  mAvailability.push_back(availability);
}

bool Room::IsAvailable(pair<int, int> availability)
{
  auto it = find_if(mAvailability.begin(), mAvailability.end(), [&](const auto & aTimeslot) {
    return aTimeslot == availability;
  });

  if (it != mAvailability.end())
    return false;

  return true;
}
