#pragma once

class Classes
{
public:
	void SetNumberOfStudents(int aNrOfStudent);
	int GetNumberOfStudents();
	void SetName(string aName);
	string GetName();


private:
	string mName;
	int mNumberOfStudents;
};