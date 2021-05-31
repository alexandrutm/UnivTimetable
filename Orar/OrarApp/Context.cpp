#include "stdafx.h"
#include "Context.h"
#include "Group.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Observer.h"
#include "Room.h"
#include "Solution.h"
#include "Solver.h"
#include "Subject.h"
#include "Teacher.h"
#include "TimeConstraint.h"
#include "TransformLessonDetails.h"

Context::Context()
{
  mRootNodeStudents = make_unique<Group>("Root Class", 0, 0);

  // create institution with default data member
  mInstituteData = make_shared<InstituteData>("Institution name", 12, 8, 20, 5);
}

void Context::RegisterObserver(shared_ptr<Observer> aObserver)
{
  mObservers.push_back(aObserver);
}

void Context::RemoveObserver(shared_ptr<Observer> aObserver)
{
  auto it = find(mObservers.begin(), mObservers.end(), aObserver);

  if (it != mObservers.end())
    mObservers.erase(it);
}

void Context::NotifyObserver(string aModelName, string instuction)
{
  for (auto obs : mObservers)
    if (obs->GetModelName() == aModelName)
      obs->Update(instuction);
}

Context::~Context()
{
}

void Context::AddTeacher(shared_ptr<Teacher> aTeacher)
{
  mTeachers.push_back(aTeacher);
}

void Context::RemoveTeacher(int pos)
{
  mTeachers.erase(mTeachers.begin() + pos);
}

size_t Context::GetTeacherSize()
{
  return mTeachers.size();
}

Teacher * Context::GetTeacherByIndex(int i)
{
  return mTeachers[i].get();
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

string Context::SearchTeacher(Teacher * aTeacher)
{
  // If we find a reference of this teacher in constraint or in lesson we return a string with
  // location
  auto it = find_if(mConstraints.begin(), mConstraints.end(), [&](auto const & constr) {
    return constr->GetTeacher() == aTeacher;
  });

  auto it2 = find_if(mLessons.begin(), mLessons.end(), [&](auto const & lesson) {
    return lesson->GetTeacher() == aTeacher;
  });

  if (it2 != mLessons.end() && it != mConstraints.end())
    return "This teacher is referred in Lesson and Constraint view";
  else if (it2 != mLessons.end())
    return "This teacher is referred in Lesson view";
  else if (it != mConstraints.end())
    return "This teacher is referred in Constraint view";
  return "";
}

vector<shared_ptr<Teacher>> Context::GetTeachers()
{
  return mTeachers;
}

void Context::AddSubject(shared_ptr<Subject> aSubject)
{
  mSubjects.push_back(aSubject);
}

void Context::RemoveSubject(int pos)
{
  mSubjects.erase(mSubjects.begin() + pos);
}

size_t Context::GetSubjectSize()
{
  return mSubjects.size();
}

Subject * Context::GetSubjectByIndex(int i)
{
  return mSubjects[i].get();
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

string Context::SearchSubject(Subject * aSubject)
{
  auto it = find_if(mLessons.begin(), mLessons.end(), [&](auto const & lesson) {
    return lesson->GetSubject() == aSubject;
  });

  if (it != mLessons.end())
    return "This subject is refered in lesson view\n";
  return "";
}

vector<shared_ptr<Subject>> Context::GetSubjects()
{
  return mSubjects;
}

int Context::GenerateGroupId()
{
  queue<Group *> treeNodes;
  int            max = 0;

  treeNodes.push(mRootNodeStudents.get());

  while (!treeNodes.empty())
  {
    Group * frontNode = treeNodes.front();
    treeNodes.pop();

    if (max < frontNode->GetId())
      max = frontNode->GetId();

    for (int i = 0; i < frontNode->GetChildrenSize(); i++)
      treeNodes.push(frontNode->GetChild(i));
  }

  return max + 1;
}

Group * Context::GetRootGroup()
{
  return mRootNodeStudents.get();
}

Group * Context::GetGroupById(int id)
{
  queue<Group *> treeNodes;

  treeNodes.push(mRootNodeStudents.get());

  while (!treeNodes.empty())
  {
    auto frontNode = treeNodes.front();
    treeNodes.pop();

    if (id == frontNode->GetId())
      return frontNode;

    for (int i = 0; i < frontNode->GetChildrenSize(); i++)
      treeNodes.push(frontNode->GetChild(i));
  }

  return nullptr;
}

vector<string> Context::GetGroupsNameToFilter(Group * aGroup)
{
  vector<string> groupsNames;
  queue<Group *> treeNodes;

  treeNodes.push(aGroup);

  while (!treeNodes.empty())
  {
    auto frontNode = treeNodes.front();
    treeNodes.pop();
    groupsNames.push_back(frontNode->GetName());

    for (int i = 0; i < frontNode->GetChildrenSize(); i++)
      treeNodes.push(frontNode->GetChild(i));
  }

  return groupsNames;
}

string Context::SearchGroup(Group * aGroup)
{
  // search for every child of the aGroup to don't be refered
  queue<Group *> treeNodes;

  treeNodes.push(aGroup);

  while (!treeNodes.empty())
  {
    auto frontNode = treeNodes.front();
    treeNodes.pop();

    auto it = find_if(mLessons.begin(), mLessons.end(), [&](auto const & lesson) {
      return lesson->GetGroup() == frontNode;
    });

    if (it != mLessons.end())
      return "This group or his children are refered in lesson view\n";

    for (int i = 0; i < frontNode->GetChildrenSize(); i++)
      treeNodes.push(frontNode->GetChild(i));
  }

  return "";
}

void Context::LoadGroupFromXml(string aName, int aNumberOfStudents, int aId, int aParentId)
{
  queue<Group *> treeNodes;

  treeNodes.push(mRootNodeStudents.get());

  while (!treeNodes.empty())
  {
    auto frontNode = treeNodes.front();
    treeNodes.pop();

    if (aParentId == frontNode->GetId())
    {
      frontNode->LoadChildFromXml(aName, aNumberOfStudents, aId);
      break;
    }

    for (int i = 0; i < frontNode->GetChildrenSize(); i++)
      treeNodes.push(frontNode->GetChild(i));
  }
}

void Context::AddLesson(shared_ptr<Lesson> aLesson)
{
  mLessons.push_back(aLesson);
}

void Context::RemoveLesson(int pos)
{
  mLessons.erase(mLessons.begin() + pos);
}

size_t Context::GetLessonSize()
{
  return mLessons.size();
}

Lesson * Context::GetLessonByIndex(int i)
{
  return mLessons[i].get();
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

vector<shared_ptr<Lesson>> Context::GetLessons()
{
  return mLessons;
}

void Context::AddLessonFromXml(
  int aTeacherId, int aSubjectId, int aGroupId, int aNumberOfHours, int aLessonId)
{
  // search teacher, subject and group in context and assign them to a lesson
  auto teacherIt = find_if(mTeachers.begin(), mTeachers.end(), [&](auto const & teacher) {
    return teacher->GetId() == aTeacherId;
  });

  auto subjectIt = find_if(mSubjects.begin(), mSubjects.end(), [&](auto const & subject) {
    return subject->GetId() == aSubjectId;
  });

  queue<Group *> treeNodes;
  Group *        lessonGroup;

  treeNodes.push(mRootNodeStudents.get());

  while (!treeNodes.empty())
  {
    auto frontNode = treeNodes.front();
    treeNodes.pop();

    if (aGroupId == frontNode->GetId())
    {
      lessonGroup = frontNode;
      break;
    }

    for (int i = 0; i < frontNode->GetChildrenSize(); i++)
      treeNodes.push(frontNode->GetChild(i));
  }

  mLessons.push_back(make_shared<Lesson>((*teacherIt).get(), (*subjectIt).get(), lessonGroup,
                                         aNumberOfHours, aLessonId));
}

void Context::DeleteLessonsPlacements()
{
  for (auto lesson : mLessons)
  {
    lesson->ClearAssingnedData();
  }
}

void Context::AddRoom(shared_ptr<Room> aRoom)
{
  mRooms.push_back(aRoom);
}

void Context::RemoveRoom(int pos)
{
  mRooms.erase(mRooms.begin() + pos);
}

size_t Context::GetRoomSize()
{
  return mRooms.size();
}

Room * Context::GetRoomByIndex(int i)
{
  return mRooms[i].get();
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

vector<shared_ptr<Room>> Context::GetRooms()
{
  return mRooms;
}

void Context::ChangeInstituteData(shared_ptr<InstituteData> aInstituteData)
{
  mInstituteData = aInstituteData;
}

InstituteData * Context::GetInstituteData()
{
  return mInstituteData.get();
}

void Context::AddConstraint(unique_ptr<TimeConstraint> aConstr)
{
  mConstraints.push_back(move(aConstr));
}

size_t Context::GetConstraintSize()
{
  return mConstraints.size();
}

TimeConstraint * Context::GetConstraintByIndex(int index)
{
  return mConstraints[index].get();
}

TimeConstraint * Context::GetConstraintByTeacher(Teacher * aTeacher)
{
  auto it = find_if(mConstraints.begin(), mConstraints.end(), [&](auto const & constraint) {
    return constraint->GetTeacher() == aTeacher;
  });

  if (it != mConstraints.end())
    return it->get();

  return nullptr;
}

void Context::RemoveConstraint(int index)
{
  if (index >= mConstraints.size())
    return;

  mConstraints.erase(mConstraints.begin() + index);
}

vector<vector<string>> Context::GetTimeTable()
{
  Solver solver;

  TransformLessonDetails lessonsStringData;
  return lessonsStringData.LessonsDataToString(GetInstituteData(), solver.FindSolution(*this));
}

bool Context::CheckTimetable()
{
  return GetLessonByIndex(0)->GetPlacement().IsValid();
}
