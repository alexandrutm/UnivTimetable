#pragma once


class Subject
{
public:

	Subject() = default;
	~Subject() = default;
	Subject(const Subject&) = default;
	bool operator==(const Subject&);
	Subject& operator=(const Subject& aSubject);

	Subject(string);
	string GetName();
	void SetName(string aName);
	

private:

	string mName;


};

Q_DECLARE_METATYPE(Subject);
