#ifndef SEMINARSKI_TEAMLEADER_H
#define SEMINARSKI_TEAMLEADER_H

#include "worker.h"
#include "director.h"
#include <list>
#include "../Other/date.h"
#include "../Exceptions/DefaultException.h"
#include <ctime>

class TeamLeader : public Worker , private Director {

private:
    void parseDateInputAsString(int&, int&, int&, int&, int&, int&, const string&) const;

public:
    TeamLeader(const string&, const string&, const string& );
    string getFullName() const override;
    string getJobTitle() const override;
    void checkWorkers(list<Worker*>);
    void assignTasks(list<Worker*>);
};

#endif
