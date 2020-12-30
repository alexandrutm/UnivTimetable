#include "SubjectView.h"
#include "INavigator.h"
#include "Context.h"
#include "SubjectDialog.h"
#include "Subject.h"

SubjectView::SubjectView(INavigator* aNavigator,Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(aNavigator),mContext(aContext)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
}

SubjectView::~SubjectView()
{
}

void SubjectView::on_NextButtonSubject_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::classesView);
}

void SubjectView::on_AddSubjectButton_clicked()
{
	SubjectDialog AddSubject(this);

	if (AddSubject.exec())
	{
		QString subjectName = AddSubject.Name->text();
		int colorNumber = AddSubject.Color->currentIndex();

		if (!subjectName.isEmpty())
		{
			QListWidgetItem* item = new QListWidgetItem(subjectName, ui.listWidgetSubject);
			item->setData(Qt::UserRole, colorNumber);
			ui.listWidgetSubject->setCurrentItem(item);

			/// build and add subject to context
			Subject buildSubject;
			buildSubject.SetColor(colorNumber);
			buildSubject.SetName(subjectName.toStdString());

			mContext.AddSubject(buildSubject);

			//change status of statusbar
			mNavigator->ChangeStatus("You have successfully added a new item");
		}

	}

}

void SubjectView::on_pushButtonBackSubject_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::thirdpage);
}

void SubjectView::on_DeleteSubjectButton_clicked()
{
	QListWidgetItem* currentItem = ui.listWidgetSubject->currentItem();
	
	if (currentItem)
	{
		int row = ui.listWidgetSubject->row(currentItem);
		ui.listWidgetSubject->takeItem(row);
		
		string subjectName=currentItem->text().toStdString();
		
		mContext.RemoveSubjectByName(subjectName);//remove subject from subjects vector
		delete currentItem;

		if (ui.listWidgetSubject->count() > 0)
			ui.listWidgetSubject->setCurrentRow(row);
		else
			on_listWidgetSubject_currentItemChanged();
	}
}

void SubjectView::on_EditSubjectButton_clicked()
{
	SubjectDialog EditSubject(this);
	QListWidgetItem* item = ui.listWidgetSubject->currentItem();


	if (item)
	{
		EditSubject.Name->setText(item->text());
		EditSubject.Abbreviation->setText(item->text().left(2));
	}

	if (EditSubject.exec())
	{
		QString subjectName = EditSubject.Name->text();
		int colorNumber = EditSubject.Color->currentIndex();
		
		//update item in context
		mContext.EditSubjectByName(item->text().toStdString(), subjectName.toStdString(), colorNumber);
		
		//update itm in view
		item->setText(subjectName);
		item->setData(Qt::UserRole, colorNumber);
	}


}

void SubjectView::on_listWidgetSubject_currentItemChanged()
{

}
