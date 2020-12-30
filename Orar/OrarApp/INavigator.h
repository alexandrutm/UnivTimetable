#pragma once


class INavigator
{
public:

	enum class viewId {
		homepage,
		secondpage,
		thirdpage,
		subjectView,
		classesView
	};

	virtual void ChangeView(viewId theView) = 0;
	virtual void ChangeStatus(QString status) = 0;
	
};