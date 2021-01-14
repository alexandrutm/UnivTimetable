#pragma once

class Room
{
public:
	bool operator==(const Room& aRoom);
	Room& operator=(const Room& aRoom);

	void SetNume(string);
	string GetNume();

private:
	string mNume;
};