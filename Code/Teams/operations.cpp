#include "operations.h"

Operations::Operations(const string& name, const int& maxNumber) : Team(name, maxNumber) {
    salary_worker = 450.36;
    salary_team_leader = 573.25;
}

void Operations::presentTeam() const {
    
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "\t-----This is Operations team-----\n";
    cout << "\tTeam name: #### " << teamName << " #### \n";
    cout << "\tTeam member count: " << teamMemberCount << "\n";
    Team::listWorkers();
    cout << "------------------------------------------------------------------------------------------------\n";
}

void Operations::callTeamLeader( Team* team ) {
    if( team -> teamLeader == nullptr ) {
        cout << "MESSAGE: Team Leader is not defined\n";
        return;
    }

    if( team -> currentProject == nullptr || team -> currentProject -> isFinished()) {
        cout << "MESSAGE: There is not an active project for team '" << team->teamName << "'. Please define project before calling this function\n";
        cout << "------------------------------------------------------------------------------------------------\n";
        return;
    }

    cout << "Choose one of the following options:\n";
    cout << "\t1) Call team leader of this team and assign new tasks to all workers\n";
    cout << "\t2) Call team leader that is going to check whether workers have finished their tasks\n";
    cout << "Enter either 1 or 2 ...\n";

    int option;

    cout << "+Option: "; cin >> option;
    while(option != 1 && option != 2) {
        cout << "Error! Please enter valid option: [1,2]: ";
        cin >> option;
    }
    
    if(option == 1) team -> teamLeader -> assignTasks(team -> workers);
    else team -> teamLeader -> checkWorkers(team -> workers);
}