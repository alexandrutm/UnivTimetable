#pragma once

class Room
{
  public:
  Room(string aName, int aId);
  bool operator==(const Room& aRoom);
  Room& operator=(const Room& aRoom);

  void SetNume(string);
  string GetNume();
  int GetId();

  private:
  string mName;
  int mId;
};
