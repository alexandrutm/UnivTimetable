#include"stdafx.h"
#include "Room.h"

Room::Room(string aName)
	:mName(aName)
{
}

bool Room::operator==(const Room& aRoom)
{
	if (this->mName == aRoom.mName)
		return true;

	return false;
}

Room& Room::operator=(const Room& aRoom)
{
	if (this != &aRoom)
	{
		this->mName = aRoom.mName;
	}
	return *this;
}

void Room::SetNume(string aNume)
{
	mName = aNume;
}

string Room::GetNume()
{
	return mName;
}
