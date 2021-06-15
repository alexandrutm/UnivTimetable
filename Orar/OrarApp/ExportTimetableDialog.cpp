#include "stdafx.h"
#include "ExportTimetableDialog.h"
#include "Context.h"
#include "InstituteData.h"
#include "TreeModelClasses.h"

ExportTimetableDialog::ExportTimetableDialog(Context &              aContext,
                                             vector<vector<string>> aLessons,
                                             shared_ptr<TreeModel>  aGroupModel,
                                             QWidget *              parent)
  : mTimetable(aLessons)
  , mContext(aContext)
  , mGroupModel(aGroupModel)
  , QDialog(parent)
{
  ui.setupUi(this);
  ui.treeView->setModel(mGroupModel.get());
}

ExportTimetableDialog::~ExportTimetableDialog()
{
}

vector<string> ExportTimetableDialog::FilterData(vector<string> pattern)
{
  vector<string> mLessonsDetails(mContext.GetInstituteData()->GetNumberOfDaysPerWeek());
  if (!pattern.empty())
  {
    int i = 0;

    for (auto day : mTimetable)
    {
      for (auto lesson : day)
      {
        for (auto groupName : pattern)
        {
          auto pos = lesson.find(groupName);
          if (pos != std::string::npos)
          {
            mLessonsDetails[i].append(lesson);
          }
        }
      }
      i++;
    }
  }

  return mLessonsDetails;
}

void ExportTimetableDialog::PrintTimetable(vector<string> aLessonsDetails)
{
  auto header = mContext.GetInstituteData()->GetDaysWeek();

  header.insert(header.begin(), "Hours\Days");

  ofstream myfile;
  myfile.open("example.txt");

  myfile << "<table>\n"
         << "  <tr>\n";
  for (auto head : header)
  {
    myfile << "    <th>" << head << "</th>\n";
  }
  myfile << "  </tr>\n";

  for (auto day : aLessonsDetails)
  {
    myfile << "  <tr>\n";
    for (auto col : row)
    {
      myfile << "    <td>" << col << "</td>\n";
    }
    myfile << "  </tr>\n";
  }
  myfile << "</table>\n";
}

void ExportTimetableDialog::on_mPrint_clicked()
{
  auto indexRowSelected = ui.treeView->selectionModel()->currentIndex();

  if (!indexRowSelected.isValid())
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
    return;
  }

  QModelIndex nameIndex =
    ui.treeView->model()->index(indexRowSelected.row(), 0, indexRowSelected.parent());

  auto parentGroup = mGroupModel->getItem(nameIndex);

  PrintTimetable(FilterData(mContext.GetGroupsNameToFilter(parentGroup)));
}
