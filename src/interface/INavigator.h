#pragma once

class INavigator
{
public:
  enum class viewId
  {
    homepage,
    instituteInfo,
    mainPage

  };

  virtual void ChangeView(viewId theView) = 0;
  virtual void ChangeStatus(string)       = 0;
};
