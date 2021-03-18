#pragma once

class Room
{
public:
  Room(string aName, int aCapacity, int aId);
  bool   operator==(const Room & aRoom);
  Room & operator=(const Room & aRoom);

  void   SetName(string);
  string GetNume();
  void   SetCapacity(int aCapacity);
  int    GetCapacity();
  int    GetId();

private:
  string mName;
  int    mCapacity;
  int    mId;
};
