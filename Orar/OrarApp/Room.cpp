#include "stdafx.h"
#include "Room.h"

Room::Room(string aName, int aId): mName(aName), mId(aId) { }

bool Room::operator==(const Room& aRoom) { return mId == aRoom.mId; }

Room& Room::operator=(const Room& aRoom)
{
  if (this != &aRoom) {
    this->mName = aRoom.mName;
    this->mId = aRoom.mId;
  }
  return *this;
}

void Room::SetNume(string aNume) { mName = aNume; }

string Room::GetNume() { return mName; }

int Room::GetId() { return mId; }
