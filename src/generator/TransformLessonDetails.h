#pragma once

#include "Solution.h"

class InstituteData;

class TransformLessonDetails
{
public:
  vector<vector<string>> LessonsDataToString(InstituteData * aInstituteData, Solution aSolution);

private:
  vector<string> mLessonDetails;
};
