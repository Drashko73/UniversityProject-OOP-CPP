#ifndef SEMINARSKI_PROJECT_H
#define SEMINARSKI_PROJECT_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Exceptions/DefaultException.h"
#include "date.h"
#include "task.h"
#include "STATUS_enum.h"

using namespace std;

class Project {

public:
    Project(const string&, Date*, Date*, const double&, const double&);
    ~Project();
    bool isFinished() const;
    void changeStatus(STATUS);
    double getExpenses() const;
    double getEarnings() const;

protected:
    static int idGenerator;

private:
    int projectID;
    string projectName;
    Date *startDate;
    Date *expectedFinishDate;
    double earnings;
    double expenses;
    STATUS projectStatus;

    void writeArchiveAboutProject() const;
};

#endif
