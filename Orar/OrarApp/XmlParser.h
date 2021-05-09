#pragma once

class Context;

class XmlParser
{
public:
  void SaveData(Context & aContext, string aFileName);
  void LoadData(Context & aContext, string aFileName);
};
