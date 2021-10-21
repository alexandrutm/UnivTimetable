#include "stdafx.h"
#include "Solution.h"
#include "src/containers/Context.h"
#include "src/containers/Lesson.h"

Solution::Solution(Context & aContext)
  : mContext(aContext)
{
  FillUnassignedLessons();
  SortLessons();
}

Solution & Solution::operator=(const Solution & aSolution)
{
  if (this != &aSolution)
  {
    mUnassignedLessons = aSolution.mUnassignedLessons;
    mAssignedLessons   = aSolution.mAssignedLessons;
  }
  return *this;
}

void Solution::FillUnassignedLessons()
{
  auto lessons = mContext.GetLessons();
  for (auto lesson : lessons)
    mUnassignedLessons.push_back(lesson.get());
}

// sort lessons by weight. the main constraint at this point
// the most dificult to asign is the last one
void Solution::SortLessons()
{
  sort(mUnassignedLessons.begin(), mUnassignedLessons.end(),
       [](Lesson * first, Lesson * second)
       {
         return first->GetWeight() < second->GetWeight();
       });
}

bool Solution::IsUnassignedLesson()
{
  return mUnassignedLessons.size() == 0 ? false : true;
}

void Solution::SetAssignedLesson(Lesson * aLesson)
{  // move lesson from unassigned to assigned
  auto it = find(mUnassignedLessons.begin(), mUnassignedLessons.end(), aLesson);

  if (it != mUnassignedLessons.end())
    mUnassignedLessons.erase(it);

  mAssignedLessons.push_back(aLesson);
}

Lesson * Solution::GetNextUnassignedLesson()
{
  return mUnassignedLessons.back();
}

void Solution::UnassignLastAssignedLesson()
{
  // remove placement for this lesson
  if (mAssignedLessons.size() > 0)
  {
    mUnassignedLessons.push_back(mAssignedLessons.back());
    mAssignedLessons.pop_back();
  }
}

vector<Lesson *> Solution::GetAssignedLessons()
{
  return mAssignedLessons;
}

bool Solution::IsComplete()
{
  if (mUnassignedLessons.size() == 0)
    return true;

  return false;
}
