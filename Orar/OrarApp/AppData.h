#pragma once

class Context;

class AppData
{
public:
  void SaveData(Context & aContext, string aFileName);
  void LoadData(Context & aContext, string aFileName);
};
