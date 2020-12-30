#pragma once
#include"stdafx.h"

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
