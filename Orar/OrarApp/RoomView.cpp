#include"stdafx.h"
#include "RoomView.h"
#include "Context.h"
#include"INavigator.h"

RoomView::RoomView(INavigator* aNavigator, Context& aContext, QWidget* parent)
	: QWidget(parent), mNavigator(aNavigator), mContext(aContext)
{
	ui.setupUi(this);
}

RoomView::~RoomView()
{
}
void RoomView::ClearData()
{
	ui.mList->clear();
}
void RoomView::on_mAdd_clicked()
{

}
void RoomView::on_mEdit_clicked()
{
}

void RoomView::on_mDelete_clicked()
{
}

void RoomView::on_mConstraints_clicked()
{
}

void RoomView::on_mNext_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::teacherView);
}

void RoomView::on_mBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::classesView);
}
