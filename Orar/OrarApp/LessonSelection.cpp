#include "stdafx.h"
#include "LessonSelection.h"
#include "Context.h"
#include "Solution.h"

// -If there are one or more variables unassigned, the variable selection criterion picks one of
// them randomly. The reason is, that it is easy to go back when a wrong variable is  picked such a
// variable is unassigned when there is a conflict with it in * some of the subsequent iterations.
// -When all variables are assigned, an evaluation is made for each variable according to the above
// described weights. The variable with the worst evaluation is selected. This variable promises the
// best improvement in optimization.

LessonSelection::LessonSelection()
{
}

Lesson * LessonSelection::SelectLesson(Solution * aSolution)
{
  srand(time(NULL));
  if (!aSolution->GetContext()->GetUnassignedLessons().empty())
  {
    auto lessons     = aSolution->GetContext()->GetUnassignedLessons();
    auto randomIndex = rand() % aSolution->GetContext()->GetUnassignedLessons().size();

    return lessons[randomIndex];
  }
  else
  {
    auto lessons     = aSolution->GetContext()->GetAssignedLessons();
    auto randomIndex = rand() % aSolution->GetContext()->GetAssignedLessons().size();

    return lessons[randomIndex];
  }
}
