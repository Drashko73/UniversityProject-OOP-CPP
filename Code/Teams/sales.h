#ifndef SEMINARSKI_SALES_H
#define SEMINARSKI_SALES_H

#include "team.h"

class Sales : public Team {

public:
    Sales(const string&, const int&);
    void presentTeam() const override;

};

#endif