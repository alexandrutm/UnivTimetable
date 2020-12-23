#pragma once


class INavigator
{
public:

	enum class viewId {
		homepage = 0,
		secondpage = 1,
		thirdpage=2
	};

	virtual void ChangeView(viewId theView) = 0;
	virtual void ChangeStatus(QString status) = 0;
	
};