#pragma once


class Subject
{
public:
	enum class Color
	{
		red,
		green,
		black,
		yellow
	};


	string GetName();
	void SetName(string aName);
	void SetColor(int i);

private:

	string mName;
	Color mColor;

};
