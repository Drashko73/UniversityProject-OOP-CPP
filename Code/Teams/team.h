#ifndef SEMINARSKI_TEAM_H
#define SEMINARSKI_TEAM_H

#include <iostream>
#include <string.h>
#include <list>
#include "../Other/project.h"
#include "../Exceptions/NumberExceeded.h"
#include "../Exceptions/DefaultException.h"

#include "../Persons/teamLeader.h"
#include "../Persons/director.h"
using namespace std;

class Team {

public:
    Team(const string&, const int& );
    ~Team();
    void startProject();
    void finishProject();
    void virtual presentTeam() const =0;
    void listWorkers() const;
    void addWorker(Worker*);
    void removeWorker(const int&);
    void transferWorker(const int&, Team*);
    string getTeamName() const;

protected:
    static int idGenerator;
    string teamName;
    int teamMemberCount;
    double salary_worker;
    double salary_team_leader;

private:
    void parseDateInput(int&, int&, int&, const string&) const;
    friend void Director::choseTeamLeader( Team* ) const;
    friend class Finance;
    friend class Operations;
    friend class HR;

private:
    int teamID;
    int maxCount;
    Project *currentProject;
    TeamLeader *teamLeader;
    list<Worker*> workers;

};

#endif
