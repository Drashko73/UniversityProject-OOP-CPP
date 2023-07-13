#ifndef SEMINARSKI_OPERATIONS_H
#define SEMINARSKI_OPERATIONS_H

#include "team.h"

class Operations : public Team {

public:
    Operations(const string&, const int&);
    void presentTeam() const override;
    void callTeamLeader( Team* );

};

#endif