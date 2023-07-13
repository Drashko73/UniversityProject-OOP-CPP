#ifndef SEMINARSKI_HR_H
#define SEMINARSKI_HR_H

#include "team.h"

class HR : public Team {

public:
    HR(const string&, const int&);
    void presentTeam() const override;
    void checkWorkerSkills(Team*) const;

};

#endif