#ifndef SEMINARSKI_TASK_H
#define SEMINARSKI_TASK_H

#include "STATUS_enum.h"
#include "date.h"
#include "../Exceptions/DefaultException.h"

class Task {
    
public:
    Task(const int&, Date*, Date*, const string&);
    ~Task();
    bool isFinished() const;
    void changeStatus(STATUS);
    string getTaskDescription() const;
    Date* getExpectedFinishDate() const;

private:
    int workerID;
    string taskDescription;
    STATUS taskStatus;
    Date* startDate;
    Date* expectedFinishDate;

};

#endif
