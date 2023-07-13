#ifndef SEMINARSKI_DIRECTOR_H
#define SEMINARSKI_DIRECTOR_H

#include "person.h"
class Team;

class Director : public virtual Person {

public:
    Director(const string&, const string&);
    void choseTeamLeader(Team*) const ;
    string getFullName() const override;

};

#endif