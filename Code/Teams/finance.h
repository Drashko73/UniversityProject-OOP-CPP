#ifndef SEMINARSKI_FINANCE_H
#define SEMINARSKI_FINANCE_H

#include "team.h"

class Finance : public Team {

public:
    Finance(const string&, const int&);
    void presentTeam() const override;
    void calculateSalaryForWorkers( Team* );

};

#endif