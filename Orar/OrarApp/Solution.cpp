#include "stdafx.h"
#include "Solution.h"
#include "Context.h"
#include "Lesson.h"
#include "Teacher.h"

Solution::Solution(Context & aContext)
  : mContext(aContext)
{
  FillUnassignedLessons();
  SortUnassignedLessons();
}

void Solution::FillUnassignedLessons()
{
  auto lessons = mContext.GetLessons();
  for (auto lesson : lessons)
    mUnassignedLessons.push_back(lesson.get());
}

// sort lessons by teacher unavailability time slot. the main constraint at this point
// the most dificult to asign is the last one
void Solution::SortUnassignedLessons()
{
  sort(mUnassignedLessons.begin(), mUnassignedLessons.end(), [](Lesson * first, Lesson * second) {
    return first->GetTeacher()->GetTeacherWeight() > second->GetTeacher()->GetTeacherWeight();
  });
}

vector<Lesson *> Solution::GetUnassignedLessons()
{
  return mUnassignedLessons;
}

void Solution::SetAssignedLesson(Lesson * aLesson)
{
  mAssignedLessons.push_back(aLesson);
}

Lesson * Solution::GetNextUnassignedLesson()
{
  auto lesson = mUnassignedLessons.back();
  mUnassignedLessons.pop_back();
  return lesson;
}

void Solution::SetLessonAsUnassigned()
{
}
