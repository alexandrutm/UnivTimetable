#include"stdafx.h"
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

void SubjectView::ClearData()
{
	ui.mList->clear();
}


void SubjectView::on_mAdd_clicked()
{
	SubjectDialog AddSubject(this);

	if (AddSubject.exec())
	{
		QString subjectName = AddSubject.Name->text();

		if (!subjectName.isEmpty())
		{
			QListWidgetItem* item = new QListWidgetItem(subjectName, ui.mList);
			ui.mList->setCurrentItem(item);

			shared_ptr<Subject> buildSubject = make_shared<Subject>(subjectName.toStdString());
			mContext.AddSubject(buildSubject);

			mNavigator->ChangeStatus("A new subject was added");

		}

	}

}


void SubjectView::on_mDelete_clicked()
{
	QListWidgetItem* currentItem = ui.mList->currentItem();
	
	if (currentItem)
	{
		int row = ui.mList->row(currentItem);
		ui.mList->takeItem(row);
		
		string subjectName=currentItem->text().toStdString();
		
		mContext.RemoveSubjectByName(subjectName);
		delete currentItem;

		if (ui.mList->count() > 0)
			ui.mList->setCurrentRow(row);

	}
}

void SubjectView::on_mConstraints_clicked()
{
}

void SubjectView::on_mNext_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::classesView);
}

void SubjectView::on_mBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::basicInfoView);
}

void SubjectView::on_mEdit_clicked()
{
	SubjectDialog EditSubject(this);
	QListWidgetItem* item = ui.mList->currentItem();


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
