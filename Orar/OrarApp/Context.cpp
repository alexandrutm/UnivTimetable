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


