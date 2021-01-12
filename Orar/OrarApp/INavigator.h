#pragma once


class INavigator
{
public:

	enum class viewId {
		homepage,
		basicInfoView,
		subjectView,
		classesView,
		roomView,
		teacherView,
		lessonView
	};

	virtual void ChangeView(viewId theView) = 0;
	virtual void ChangeStatus(string) = 0;
};