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

void SubjectView::UpdateList()
{
	this->ClearData();

	auto mSubject = mContext.GetSubjects();

	for (auto i : mSubject)
	{
		QVariant subject;
		subject.setValue(i);

		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString((*i).GetName()), ui.mList);
		item->setData(Qt::UserRole, subject);
		ui.mList->setCurrentItem(item);
	}

}


void SubjectView::on_mAdd_clicked()
{
	SubjectDialog AddSubject(this);

	if (AddSubject.exec())
	{
		QString subjectName = AddSubject.Name->text();

		if (!subjectName.isEmpty())
		{
			shared_ptr<Subject> buildSubject = make_shared<Subject>(subjectName.toStdString());
			mContext.AddSubject(buildSubject);

			this->UpdateList();
			mNavigator->ChangeStatus("A new subject was added");
		}

	}

}

void SubjectView::on_mEdit_clicked()
{
	SubjectDialog EditSubject(this);
	QListWidgetItem* item = ui.mList->currentItem();


	if (item)
	{
		if (EditSubject.exec())
		{
			QString subjectName = EditSubject.Name->text();

			if (item->text().toStdString() != subjectName.toStdString())
			{
				shared_ptr<Subject> oldSubject = qvariant_cast<shared_ptr<Subject>>(item->data(Qt::UserRole));
				shared_ptr<Subject> newsubject = make_shared<Subject>(subjectName.toStdString());
				mContext.EditSubject(oldSubject,newsubject);

				this->UpdateList();
			}
		}
	}
}

void SubjectView::on_mDelete_clicked()
{
	QListWidgetItem* currentItem = ui.mList->currentItem();
	
	if (currentItem)
	{
		mContext.RemoveSubject(qvariant_cast<shared_ptr<Subject>>(currentItem->data(Qt::UserRole)));
		delete currentItem;

		this->UpdateList();

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

