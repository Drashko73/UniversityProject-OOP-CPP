#include "finance.h"

Finance::Finance(const string& name, const int& maxNumber) : Team(name, maxNumber) {
    salary_worker = 432.0;
    salary_team_leader = 499.99;
}

void Finance::presentTeam() const {
    
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "\t-----This is Finance team-----\n";
    cout << "\tTeam name: #### " << teamName << " #### \n";
    cout << "\tTeam member count: " << teamMemberCount << "\n";
    Team::listWorkers();
    cout << "------------------------------------------------------------------------------------------------\n";
}

void Finance::calculateSalaryForWorkers(Team *team) {
    for(auto it : team->workers) {
        double salaryWithoutPenalties = team->salary_worker;
        it -> setSalary(salaryWithoutPenalties - salaryWithoutPenalties/100 * it->getPenalties() );
    }

    if(team -> teamLeader == nullptr) return;

    double tmLeaderSalary = team -> salary_team_leader;
    team -> teamLeader -> setSalary(tmLeaderSalary - tmLeaderSalary/100* team -> teamLeader -> getPenalties() );

}
