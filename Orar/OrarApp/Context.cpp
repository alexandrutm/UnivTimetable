#include"Context.h"

void Context::AddTeacher(Teacher aTeacher)
{
	mTeachers.push_back(aTeacher);
}

void Context::RemoveTeacherByFirstName(string aFirstName)
{
	//not optimal ///////// need changes

	auto i = begin(mTeachers);

	while (i != end(mTeachers))
	{
		if ((*i).GetFirstName() == aFirstName)
		{
			i = mTeachers.erase(i);
			break;
		}
		else
			i++;
	}

}

void Context::EditTeacherByFirstName(string aOldName, string aNewFirstName,string aNewLastName)
{
	auto i = begin(mTeachers);

	while (i != end(mTeachers))
	{
		if ((*i).GetFirstName() == aOldName)
		{
			(*i).SetFirstName(aNewFirstName);
			(*i).SetLastName(aNewLastName);
		}
		else
			i++;
	}
}

void Context::AddSubject(Subject aSubject)
{
	mSubjects.push_back(aSubject);
}

void Context::RemoveSubjectByName(string aName)
{
	auto i = begin(mSubjects);

	while (i != end(mSubjects))
	{
		if ((*i).GetName() == aName)
		{
			i = mSubjects.erase(i);
			break;
		}
		else
			i++;
	}
}

void Context::EditSubjectByName(string aOldName,string aNewName,int aColorPosition)
{
	auto i = begin(mSubjects);

	while (i != end(mSubjects))
	{
		if ((*i).GetName() == aOldName)
		{
			(*i).SetName(aNewName);
			(*i).SetColor(aColorPosition);
		}
		else
			i++;
	}
}

void Context::AddClass(Classes aClass)
{
	mClasses.push_back(aClass);
}

void Context::RemoveClassByName(string aName)
{
	auto i = begin(mClasses);

	while (i != end(mClasses))
	{
		if ((*i).GetName() == aName)
		{
			i = mClasses.erase(i);
			break;
		}
		else
			i++;
	}
}

void Context::EditClassesByName(string aOldName,string aNewName,int aNumberOfStudents)
{
	auto i = begin(mClasses);

	while (i != end(mClasses))
	{
		if ((*i).GetName() == aOldName)
		{
			(*i).SetName(aNewName);
			(*i).SetNumberOfStudents(aNumberOfStudents);
		}
		else
			i++;
	}
}

void Context::AddBasicInfo(BasicInfo aBasicInfo)
{
	mBasicInfo = aBasicInfo;
}
