#include "HomePage.h"
#include "OrarApp.h"

HomePage::HomePage(OrarApp* parentView,QWidget *parent)
	: QWidget(parent),parentview(parentView)
{
	ui.setupUi(this);
}

HomePage::~HomePage()
{
}

void HomePage::on_okButton_clicked()
{
	parentview->ChangeViews(2);
}

void HomePage::createNewTimeTable()
{
	
}