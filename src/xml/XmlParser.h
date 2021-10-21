#pragma once

class Context;
class TiXmlHandle;

class XmlParser
{
public:
  // save data
  auto SaveInstituteData(Context & aContext);
  auto SaveSubjects(Context & aContext);
  auto SaveTeachers(Context & aContext);
  auto SaveRooms(Context & aContext);
  auto SaveGroups(Context & aContext);
  auto SaveLessons(Context & aContext);

  void SaveData(Context & aContext, string aFileName);

  // load data

  void LoadInstituteData(Context & aContext, TiXmlHandle & hRoot);
  void LoadSubjects(Context & aContext, TiXmlHandle & hRoot);
  void LoadTeachers(Context & aContext, TiXmlHandle & hRoot);
  void LoadRooms(Context & aContext, TiXmlHandle & hRoot);
  void LoadGroups(Context & aContext, TiXmlHandle & hRoot);
  void LoadLessons(Context & aContext, TiXmlHandle & hRoot);

  void LoadData(Context & aContext, string aFileName);
};
