#pragma once

class Classes
{
public:

	Classes() = default;
	~Classes() = default;
	Classes(const Classes&) = default;


	Classes(string ,int);
	void SetNumberOfStudents(int aNrOfStudent);
	int GetNumberOfStudents();
	void SetName(string aName);
	string GetName();

	bool operator==(const Classes& aClass);

private:
	string mName;
	int mNumberOfStudents;
};


Q_DECLARE_METATYPE(Classes);