#pragma once


class Subject
{
public:

	Subject() = default;
	~Subject() = default;
	Subject(const Subject&) = default;

	Subject(string);
	string GetName();
	void SetName(string aName);
	

private:

	string mName;


};

Q_DECLARE_METATYPE(Subject);
