#include "director.h"
#include "../Teams/team.h"

Director::Director(const string& fn, const string& ln) : Person(fn, ln) {}

string Director::getFullName() const { return "Director: " + Person::getFullName(); }

void Director::choseTeamLeader(Team* team) const {

    srand(time(NULL)); // sample random time with a seed based on the current pc time

    int numberOfWorkers = team->workers.size();
    int randomIndex = rand() % numberOfWorkers;
    list<Worker*>::iterator it = team -> workers.begin();
    advance(it, randomIndex); // advance iterator to the specified index from begining

    if(numberOfWorkers == 0) return;

    if( team -> teamLeader == nullptr ) {
        team -> teamLeader = new TeamLeader((*it) -> getFirstName(), (*it) -> getLastName(), "Team Leader");
        team -> teamLeader -> setSalary(team->salary_team_leader);
        team -> workers.erase(it);
    }
    else {
        delete team -> teamLeader; // free space in case team already has a team leader
        team -> teamLeader = new TeamLeader((*it) -> getFirstName(), (*it) -> getLastName(), "Team Leader");
        team -> teamLeader -> setSalary(team->salary_team_leader);
        team -> workers.erase(it);
    }
}
