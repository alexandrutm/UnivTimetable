#include"stdafx.h"
#include"Context.h"
#include"Teacher.h"
#include"BasicInfo.h"
#include"Classes.h"
#include"Subject.h"

Context::Context()
{

}

void Context::AddTeacher(shared_ptr<Teacher> aTeacher)
{
	mTeachers.push_back(aTeacher);
}

void Context::RemoveTeacher(shared_ptr<Teacher>aTeacher)
{
	auto i = begin(mTeachers);

	while (i != end(mTeachers))
	{
		if ((*i)==aTeacher)
		{
			i = mTeachers.erase(i);
			break;
		}
		else
			i++;
	}

}

void Context::EditTeacher(shared_ptr<Teacher> aOldTeacher,shared_ptr<Teacher> aNewTeacher)
{
	auto it = find_if(mTeachers.begin(), mTeachers.end(), [&](shared_ptr<Teacher>const& t) {
		return *t == *aOldTeacher;
		});

	if (it != mTeachers.end()) {
		(*(*it)).SetFirstName(aNewTeacher->GetFirstName());
		(*(*it)).SetLastName(aNewTeacher->GetLastName());
	}
}

vector<shared_ptr<Teacher>>& Context::GetTeachers()
{
	return mTeachers;
}

void Context::AddSubject(shared_ptr<Subject> aSubject)
{
	mSubjects.push_back(aSubject);
}

void Context::RemoveSubject(shared_ptr<Subject> aSubject)
{
	auto i = begin(mSubjects);

	while (i != end(mSubjects))
	{
		if ((*i) == aSubject)
		{
			i = mSubjects.erase(i);
			break;
		}
		else
			i++;
	}
}

void Context::EditSubject(shared_ptr<Subject> aSubject, shared_ptr<Subject> aNewSubject)
{
	auto i = find_if(mSubjects.begin(), mSubjects.end(), [&](shared_ptr<Subject>const& s)
		{
			return *s == *aSubject;
		});

	if (i != mSubjects.end())
	{
		(*(*i)).SetName((*aNewSubject).GetName());
	}
}

vector<shared_ptr<Subject>>& Context::GetSubjects()
{
	return mSubjects;
}

void Context::AddClass(shared_ptr<Classes> aClass)
{
	mClasses.push_back(aClass);
}

void Context::RemoveClass(shared_ptr<Classes> aClass)
{
	auto i = begin(mClasses);

	while (i != end(mClasses))
	{
		if ((*i) == aClass)
		{
			i = mClasses.erase(i);
			break;
		}
		else
			i++;
		
	}
}

void Context::EditClasses(shared_ptr<Classes> aClass, shared_ptr<Classes> aNewClass)
{
	auto it = find_if(mClasses.begin(), mClasses.end(), [&](shared_ptr<Classes>const& c)
		{
			return *c == *aNewClass;
		});

	if (it != mClasses.end())
	{
		(*(*it)).SetName((*aNewClass).GetName());
		(*(*it)).SetNumberOfStudents((*aNewClass).GetNumberOfStudents());
	}
}

vector<shared_ptr<Classes>>& Context::GetClasses()
{
	return mClasses;
}

void Context::AddLesson(shared_ptr<Lesson> aLesson)
{
	mLessons.push_back(aLesson);
}

void Context::RemoveLesson(shared_ptr<Lesson> aLesson)
{
	auto i = begin(mLessons);

	while (i != end(mLessons))
	{
		if ((*i) == aLesson)
		{
			i = mLessons.erase(i);
			break;
		}
		else
			i++;

	}
}

void Context::EditLesson(shared_ptr<Lesson> aLesson, shared_ptr<Lesson> aNewLesson)
{
	auto it = find_if(mLessons.begin(), mLessons.end(), [&](shared_ptr<Lesson>const& l)
		{
			return *l == *aNewLesson;
		});


}

vector<shared_ptr<Lesson>>& Context::GetLesson()
{
	return mLessons;
}


void Context::AddBasicInfo(shared_ptr<BasicInfo> aBasicInfo)
{
	mBasicInfo = aBasicInfo;
}

void Context::DeleteData()
{
	mTeachers.clear();
	mSubjects.clear();
	mClasses.clear();
	mLessons.clear();
	mBasicInfo.reset();
}
