#pragma once

class Solution;
class InstituteData;

class TransformLessonDetails
{
public:
  vector<string> GetLessonDetails(InstituteData * aInstituteData, Solution * aSolution);

private:
  vector<string> mLessonDetails;
};
