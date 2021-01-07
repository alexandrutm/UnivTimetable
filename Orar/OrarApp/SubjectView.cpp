#include "SubjectView.h"
#include "INavigator.h"
#include "Context.h"
#include "SubjectDialog.h"
#include "Subject.h"

SubjectView::SubjectView(INavigator* aNavigator,Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(aNavigator),mContext(aContext)
{
	ui.setupUi(this);

}

SubjectView::~SubjectView()
{
}


void SubjectView::on_Add_clicked()
{
	SubjectDialog AddSubject(this);

	if (AddSubject.exec())
	{
		QString subjectName = AddSubject.Name->text();

		if (!subjectName.isEmpty())
		{
			QListWidgetItem* item = new QListWidgetItem(subjectName, ui.listWidgetSubject);
			ui.listWidgetSubject->setCurrentItem(item);

			/// store data
			shared_ptr<Subject> buildSubject = make_shared<Subject>(subjectName.toStdString());
			mContext.AddSubject(buildSubject);

			//change statusbar
			mNavigator->ChangeStatus("You have successfully added a new subject");
		}

	}

}


void SubjectView::on_Delete_clicked()
{
	QListWidgetItem* currentItem = ui.listWidgetSubject->currentItem();
	
	if (currentItem)
	{
		int row = ui.listWidgetSubject->row(currentItem);
		ui.listWidgetSubject->takeItem(row);
		
		string subjectName=currentItem->text().toStdString();
		
		mContext.RemoveSubjectByName(subjectName);
		delete currentItem;

		if (ui.listWidgetSubject->count() > 0)
			ui.listWidgetSubject->setCurrentRow(row);

	}
}

void SubjectView::on_Edit_clicked()
{
	SubjectDialog EditSubject(this);
	QListWidgetItem* item = ui.listWidgetSubject->currentItem();


	if (item)
	{
		EditSubject.Name->setText(item->text());
		EditSubject.Abbreviation->setText(item->text().left(2));

		if (EditSubject.exec())
		{
			QString subjectName = EditSubject.Name->text();

			if (item->text().toStdString() != subjectName.toStdString())
			{
				//update item in context
				mContext.EditSubjectByName(item->text().toStdString(), subjectName.toStdString());

				//update item in view
				item->setText(subjectName);
			}
		}
	}
}
