#include "sales.h"

Sales::Sales(const string& name, const int& maxNumber) : Team(name, maxNumber) {
    salary_worker = 367.45;
    salary_team_leader = 500.01;
}

void Sales::presentTeam() const {
    
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "\t-----This is Sales team-----\n";
    cout << "\tTeam name: #### " << teamName << " #### \n";
    cout << "\tTeam member count: " << teamMemberCount << "\n";
    Team::listWorkers();
    cout << "------------------------------------------------------------------------------------------------\n";
}