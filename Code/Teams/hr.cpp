#include "hr.h"

HR::HR(const string& name, const int& maxNumber) : Team(name, maxNumber) {
    salary_worker = 720.0;
    salary_team_leader = 800.36;
}

void HR::presentTeam() const {
    
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "\t-----This is an Human Resources (HR) team-----\n";
    cout << "\tTeam name: #### " << teamName << " #### \n";
    cout << "\tTeam member count: " << teamMemberCount << "\n";
    Team::listWorkers();
    cout << "------------------------------------------------------------------------------------------------\n";
}

void HR::checkWorkerSkills(Team *team) const {
    for(auto it : team -> workers) {
        int skillCount = it -> getSkills().size();
        if(skillCount < 3)
            cout << "\t\tWorker (ID) " << it -> getWorkerID() << " " << it -> getFirstName() << " " << it -> getLastName() << " has LOW skill count! ( " << skillCount << " )\n";
        else if(skillCount < 6)
            cout << "\t\tWorker (ID) " << it -> getWorkerID() << " " << it -> getFirstName() << " " << it -> getLastName() << " has MEDIUM skill count! ( " << skillCount << " )\n";
        else
            cout << "\t\tWorker (ID) " << it -> getWorkerID() << " " << it -> getFirstName() << " " << it -> getLastName() << " has HIGH skill count! ( " << skillCount << " )\n";
    }
}