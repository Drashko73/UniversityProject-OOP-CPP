#include "task.h"

Task::Task(const int& id, Date* s, Date* e, const string& desc) {
    
    if(*e <= *s)
        throw DefaultException("Expected date for finishing the task is before start date!");

    this -> workerID = id;
    this -> startDate = s;
    this -> expectedFinishDate = e;
    this -> taskDescription = desc;
    this -> taskStatus = NOT_FINISHED;
}

Task::~Task() {
    delete startDate;
    delete expectedFinishDate;
}

bool Task::isFinished() const { return this -> taskStatus == FINISHED; }

void Task::changeStatus(STATUS s) { this -> taskStatus = s; }

string Task::getTaskDescription() const {
    string s = "";
    s += "On this task is working worker #" + to_string(workerID) + "\n";
    s += "Task description: " + taskDescription + "\n";
    return s;
}

Date* Task::getExpectedFinishDate() const { return expectedFinishDate; }
