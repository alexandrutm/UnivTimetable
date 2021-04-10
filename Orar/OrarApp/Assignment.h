#pragma once

class Lesson;

// An assignment of all the Lessons. This class decouples an assignment of lesson to their values.
// This is needed for any kind of parallel computations, or in general, to be able to hold multiple
// different assignments in memory.

class Assignment
{
public:
  // Assignment index.Unique identification of the assignment, starting with zero.
  int GetIndex();

  // Returns assignment of a variable, null if not assigned
  pair<TimeSlot, Room> GetValue(Lesson * aLesson);

  // Returns iteration of the last assignment.
  long GetIteration(Lesson * aLesson);

  // Assign the given value to its variable.
  // return previous assignment of the variable, null if it was not assigned
  pair<TimeSlot, Room> Assign(long aIteration, pair<TimeSlot, Room> aValue);

  // Unassign the given variable.
  // return previous assignment of the variable, null if it was not assigned
  pair<TimeSlot, Room> Unassign(long aIteration, Lesson * aLesson);

  // Number of assigned variables in this assignment.
  // return number of assigned variables in this assignment
  int GetNrAssignedVariables();

  // The list of assigned values in the assignment. That is a collection
  //  for all assigned variables in this assignment.
  // return a collection of assigned values in this assignment
  vector<Lesson *> GetAssignedLessons();

  // The list of variables of the model that have no value in this assignment. That is all the
  // variables of the model that is null in this assignment.
  // return a collection of all not assigned variables in this assignment
  vector<Lesson *> GetUnassignedLessons();

  // The list of assigned values in the assignment. That is a collection for all assigned variables
  // in this assignment.
  // return a collection of assigned values in this assignment

private:
  Context & mContext;

  vector<Lesson *> mAssignedLesson;
  vector<Lesson *> mUnassignedLesson;

  // vector<pair<TimeSlot *, Room *>> mAssignedTimeAndRoom;
  // vector<pair<TimeSlot *, Room *>> mUnassignedTimeAndRoom;
};
