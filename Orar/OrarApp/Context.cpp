#include "stdafx.h"
#include "Context.h"
#include "Classes.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Room.h"
#include "Subject.h"
#include "Teacher.h"

Context::Context()
{
}

void Context::AddTeacher(shared_ptr<Teacher> aTeacher)
{
  mTeachers.push_back(aTeacher);
}

void Context::RemoveTeacher(shared_ptr<Teacher> aTeacher)
{
  mTeachers.erase(remove_if(mTeachers.begin(), mTeachers.end(),
                            [&](auto const & teacher) {
                              return teacher->GetId() == aTeacher->GetId();
                            }),
                  mTeachers.end());

  // erase_if(mTeachers, [&](auto const& teacher) {return *teacher == *aTeacher; });
}

vector<shared_ptr<Teacher>> & Context::GetTeachers()
{
  return mTeachers;
}

int Context::GetTeacherSize()
{
  return mTeachers.size();
}

shared_ptr<Teacher> Context::GetTeacherByIndex(int i)
{
  return mTeachers[i];
}

void Context::DeleteTeachers()
{
  mTeachers.clear();
}

int Context::GenerateTeacherId()
{
  auto maxIdIt = max_element(mTeachers.begin(), mTeachers.end(), [](auto & first, auto & second) {
    return first->GetId() < second->GetId();
  });

  if (maxIdIt == mTeachers.end())
    return 1;

  return (*maxIdIt)->GetId() + 1;
}

void Context::AddSubject(shared_ptr<Subject> aSubject)
{
  mSubjects.push_back(aSubject);
}

void Context::RemoveSubject(shared_ptr<Subject> aSubject)
{
  mSubjects.erase(remove_if(mSubjects.begin(), mSubjects.end(),
                            [&](auto const & subject) {
                              return subject->GetId() == aSubject->GetId();
                            }),
                  mSubjects.end());
}

vector<shared_ptr<Subject>> & Context::GetSubjects()
{
  return mSubjects;
}

int Context::GetSubjectSize()
{
  return mSubjects.size();
}

shared_ptr<Subject> Context::GetSubjectByIndex(int i)
{
  return mSubjects[i];
}

void Context::DeleteSubjects()
{
  mClasses.clear();
}

int Context::GenerateSubjectId()
{
  auto maxIdIt = max_element(mSubjects.begin(), mSubjects.end(), [](auto & first, auto & second) {
    return first->GetId() < second->GetId();
  });

  if (maxIdIt == mSubjects.end())
    return 1;
  return (*maxIdIt)->GetId() + 1;
}

void Context::AddClass(shared_ptr<Classes> aClass)
{
  mClasses.push_back(aClass);
}

void Context::RemoveClass(shared_ptr<Classes> aClass)
{
  mClasses.erase(remove_if(mClasses.begin(), mClasses.end(),
                           [&](auto const & classes) {
                             return aClass->GetId() == classes->GetId();
                           }),
                 mClasses.end());
}

vector<shared_ptr<Classes>> & Context::GetClasses()
{
  return mClasses;
}

int Context::GetClassSize()
{
  return mClasses.size();
}

shared_ptr<Classes> Context::GetClassByIndex(int i)
{
  return mClasses[i];
}

void Context::DeleteClasses()
{
  mClasses.clear();
}

int Context::GenerateClassId()
{
  auto maxIdIt = max_element(mClasses.begin(), mClasses.end(), [](auto & first, auto & second) {
    return first->GetId() < second->GetId();
  });

  if (maxIdIt == mClasses.end())
    return 1;
  return (*maxIdIt)->GetId() + 1;
}

void Context::AddLesson(shared_ptr<Lesson> aLesson)
{
  mLessons.push_back(aLesson);
}

void Context::RemoveLesson(shared_ptr<Lesson> aLesson)
{
  mLessons.erase(remove_if(mLessons.begin(), mLessons.end(),
                           [&](auto const & lesson) {
                             return aLesson->GetId() == lesson->GetId();
                           }),
                 mLessons.end());
}

vector<shared_ptr<Lesson>> & Context::GetLessons()
{
  return mLessons;
}

int Context::GetLessonSize()
{
  return mLessons.size();
}

shared_ptr<Lesson> Context::GetLessonByIndex(int i)
{
  return mLessons[i];
}

void Context::DeleteLessons()
{
  mLessons.clear();
}

int Context::GenerateLessonId()
{
  auto maxIdIt = max_element(mLessons.begin(), mLessons.end(), [](auto & first, auto & second) {
    return first->GetId() < second->GetId();
  });

  if (maxIdIt == mLessons.end())
    return 1;

  return (*maxIdIt)->GetId() + 1;
}

void Context::AddRoom(shared_ptr<Room> aRoom)
{
  mRooms.push_back(aRoom);
}

void Context::RemoveRoom(shared_ptr<Room> aRoom)
{
  mRooms.erase(remove_if(mRooms.begin(), mRooms.end(),
                         [&](auto const & room) {
                           return aRoom->GetId() == room->GetId();
                         }),
               mRooms.end());
}

vector<shared_ptr<Room>> & Context::GetRooms()
{
  return mRooms;
}

int Context::GetRoomSize()
{
  return mRooms.size();
}

shared_ptr<Room> Context::GetRoomByIndex(int i)
{
  return mRooms[i];
}

void Context::DeleteRooms()
{
  mRooms.clear();
}

int Context::GenerateRoomId()
{
  auto maxIdIt = max_element(mRooms.begin(), mRooms.end(), [](auto & first, auto & second) {
    return first->GetId() < second->GetId();
  });

  if (maxIdIt == mRooms.end())
    return 1;

  return (*maxIdIt)->GetId() + 1;
}

void Context::AddInstituteData(shared_ptr<InstituteData> aInstituteData)
{
  mInstituteData.push_back(aInstituteData);
}

int Context::GenerateInstituteDataId()
{
  auto maxIdIt =
    max_element(mInstituteData.begin(), mInstituteData.end(), [](auto & first, auto & second) {
      return first->GetId() < second->GetId();
    });

  if (maxIdIt == mInstituteData.end())
    return 1;

  return (*maxIdIt)->GetId() + 1;
}
