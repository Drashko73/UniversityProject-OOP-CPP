#include "engineering.h"

Engineering::Engineering(const string& name, const int& maxNumber) : Team(name, maxNumber) {
    salary_worker = 970.49;
    salary_team_leader = 1345.65;
}

void Engineering::presentTeam() const {
    
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "\t-----This is Engineering team-----\n";
    cout << "\tTeam name: #### " << teamName << " #### \n";
    cout << "\tTeam member count: " << teamMemberCount << "\n";
    Team::listWorkers();
    cout << "------------------------------------------------------------------------------------------------\n";
}