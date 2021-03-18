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
