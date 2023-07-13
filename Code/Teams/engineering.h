#ifndef SEMINARSKI_ENGINEERING_H
#define SEMINARSKI_ENGINEERING_H

#include "team.h"

class Engineering : public Team {

public:
    Engineering(const string&, const int&);
    void presentTeam() const override;
};

#endif