#include "stdafx.h"
#include "Context.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Room.h"
#include "Students.h"
#include "Subject.h"
#include "Teacher.h"

Context::Context()
{
  mRootNodeStudents = make_unique<Students>("Root Class", 0, 0);
}

Context::~Context()
{
}

void Context::AddTeacher(shared_ptr<Teacher> aTeacher)
{
  mTeachers.push_back(aTeacher);
}

void Context::RemoveTeacher(int i)
{
  mTeachers.erase(remove_if(mTeachers.begin(), mTeachers.end(),
                            [&](auto const & teacher) {
                              return mTeachers[i]->GetId() == teacher->GetId();
                            }),
                  mTeachers.end());
}

vector<shared_ptr<Teacher>> & Context::GetTeachers()
{
  return mTeachers;
}

size_t Context::GetTeacherSize()
{
  return mTeachers.size();
}

shared_ptr<Teacher> & Context::GetTeacherByIndex(int i)
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

void Context::RemoveSubject(int i)
{
  mSubjects.erase(remove_if(mSubjects.begin(), mSubjects.end(),
                            [&](auto const & subject) {
                              return mSubjects[i]->GetId() == subject->GetId();
                            }),
                  mSubjects.end());
}

vector<shared_ptr<Subject>> & Context::GetSubjects()
{
  return mSubjects;
}

size_t Context::GetSubjectSize()
{
  return mSubjects.size();
}

shared_ptr<Subject> & Context::GetSubjectByIndex(int i)
{
  return mSubjects[i];
}

void Context::DeleteSubjects()
{
  mSubjects.clear();
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

int Context::GenerateClassId()
{
  queue<Students *> treeNodes;
  int               max = 0;

  treeNodes.push(mRootNodeStudents.get());

  while (!treeNodes.empty())
  {
    int queueSize = static_cast<int>(treeNodes.size());
    while (queueSize > 0)
    {
      Students * frontNode = treeNodes.front();
      treeNodes.pop();

      if (max < frontNode->GetId())
        max = frontNode->GetId();

      for (int i = 0; i < frontNode->GetChildrenSize(); i++)
        treeNodes.push(frontNode->GetChild(i));
      queueSize--;
    }
  }
  return max + 1;
}

Students * Context::GetRootClass()
{
  return mRootNodeStudents.get();
}

void Context::AddLesson(shared_ptr<Lesson> aLesson)
{
  mLessons.push_back(aLesson);
}

void Context::RemoveLesson(int i)
{
  mLessons.erase(remove_if(mLessons.begin(), mLessons.end(),
                           [&](auto const & lesson) {
                             return mLessons[i]->GetId() == lesson->GetId();
                           }),
                 mLessons.end());
}

vector<shared_ptr<Lesson>> & Context::GetLessons()
{
  return mLessons;
}

size_t Context::GetLessonSize()
{
  return mLessons.size();
}

shared_ptr<Lesson> & Context::GetLessonByIndex(int i)
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

void Context::RemoveRoom(int i)
{
  auto aRoom = mRooms[i];

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

size_t Context::GetRoomSize()
{
  return mRooms.size();
}

shared_ptr<Room> & Context::GetRoomByIndex(int i)
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
  mInstituteData = aInstituteData;
}

shared_ptr<InstituteData> Context::GetInstituteData()
{
  return mInstituteData;
}
