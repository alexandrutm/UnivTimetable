#include "ThirdPage.h"
#include"INavigator.h"
#include"SubjectDialog.h"

ThirdPage::ThirdPage(INavigator *navigator, Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(navigator),mContext(aContext)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
}

ThirdPage::~ThirdPage()
{
}

void ThirdPage::on_NextButtonBasicInfo_clicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}

void ThirdPage::on_NextButtonSubject_clicked()
{
	ui.stackedWidget->setCurrentIndex(2);
}

void ThirdPage::on_AddSubjectButton_clicked()
{
	SubjectDialog AddSubject(this);

	if (AddSubject.exec())
	{
		QString subjectName = AddSubject.SubjectName->text();
		QString abbreviation = subjectName.left(2);

		if (!subjectName.isEmpty())
		{
			QListWidgetItem* item = new QListWidgetItem(subjectName, ui.listWidgetSubject);
			item->setData(Qt::UserRole, abbreviation);
			ui.listWidgetSubject->setCurrentItem(item);

			//change status of statusbar
			mNavigator->ChangeStatus("You have successfully added a new item");
		}
	}

}

void ThirdPage::on_listWidgetSubject_currentItemChanged()
{

}
