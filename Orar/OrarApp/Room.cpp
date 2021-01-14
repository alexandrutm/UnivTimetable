#include"stdafx.h"
#include "Room.h"

bool Room::operator==(const Room& aRoom)
{
	if (this->mNume == aRoom.mNume)
		return true;

	return false;
}

Room& Room::operator=(const Room& aRoom)
{
	if (this != &aRoom)
	{
		this->mNume = aRoom.mNume;
	}
	return *this;
}

void Room::SetNume(string aNume)
{
	mNume = aNume;
}

string Room::GetNume()
{
	return mNume;
}
