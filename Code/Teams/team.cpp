#include "team.h"
#include "finance.h"

int Team::idGenerator = 0;

Team::Team(const string& name, const int& maxNumber) : teamName(name), maxCount(maxNumber) {
    this -> currentProject = nullptr;
    this -> teamID = ++idGenerator;
    this -> teamMemberCount = 0;
}

Team::~Team() {
    delete teamLeader;
    delete currentProject;
    for(auto it : workers) delete it;
}

void Team::startProject() {

    string prName, startDate, endDate;
    int day1, month1, year1;
    int day2, month2, year2;
    double earn, spend;

    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "CALLED FUNCTION FOR CREATING NEW PROJECT...\n";
    cout << "In order to create project please provide the following information about the project:\n";
    
    cout << "\tProject name: "; getline(cin, prName);
    cout << "\tStart date of the project (day.month.year): "; cin >> startDate;
    cout << "\tExpected date for finishing the project (day.month.year): "; cin >> endDate;
    cout << "\tEarnings after finishing the project: "; cin >> earn;
    cout << "\tCost of the project: "; cin >> spend;

    try {
        parseDateInput(day1, month1, year1, startDate);
        parseDateInput(day2, month2, year2, endDate);

        currentProject = new Project(prName, new Date(0, 0, 0, day1, month1, year1), new Date(0, 0, 0, day2, month2, year2), earn, spend);

        cout << "MESSAGE: Project created successfully!\n";
        cout << "------------------------------------------------------------------------------------------------\n";
        return;
    }
    catch(DefaultException& e) {
        cout << e.what() << "\n";
    }
    catch(NotValidDate &e) {
        cout << e.what() << "\n";
    }
    catch(...) {
        cout << "Unrecognized error, check this!\n";
    }

    cout << "MESSAGE: There was an error creating the project! Try again...\n";
    cout << "------------------------------------------------------------------------------------------------\n";
}

void Team::finishProject() {
    if(this -> currentProject == nullptr) {
        cout << "\tMESSAGE: Cannot finish project... There is not an active project\n";
        return;
    }

    if(this ->currentProject -> isFinished()) {
        cout << "\tMESSAGE: Project already finished\n";
        return;
    }

    cout << "\tMESSAGE: Project marked as finished\n";
    this -> currentProject -> changeStatus(FINISHED);
}

void Team::listWorkers() const {
    if(teamLeader != nullptr)
        cout << "\t" << teamLeader -> getFullName() << "\n";
    cout << "\tWorkers:\n";
    int counter = 1;
    for(auto it : workers) cout << "\t" << counter++ << ") " << it -> getFullName() << "\n";
}

/*
    This function parses the input string and extracts number from it in organised order so it can be used
    to create new Date. The available format is dd.mm.yyyy{.}. In case of a different format than this one
    the (const char*) error is thrown.
*/

void Team::parseDateInput(int& day, int& month, int& year, const string& inputString) const {
    
    day = month = year = -1;

    int number = 0;
    for(int i = 0; i < inputString.length(); i++) {
        if(inputString[i] >= '0' && inputString[i] <= '9')
            number = number * 10 + (inputString[i] - '0');
        else if (inputString[i] == '.' ) {
            if(day == -1) day = number;
            else if(month == -1) month = number;
            else if(year == -1) year = number;
            number = 0;
        }
        else throw DefaultException("Passed format for Date is NOT VALID!");
    }

    if(number > 0 && year == -1) year = number; 
}

// This function adds new worker to a list of already created workers if there is enough space for a new one
void Team::addWorker(Worker* newWorker) {

    if(this -> teamMemberCount >= this -> maxCount) {
        throw NumberExceeded();
        return;
    }

    workers.push_front(newWorker);
    newWorker -> setSalary(salary_worker);
    teamMemberCount++;


    cout << "\tUPDATE(TeamName: '" << teamName << "'): Added new worker to a team! | Member count: " << teamMemberCount << "\n";
}

void Team::removeWorker(const int& id) {
	
	list<Worker*>::iterator it = workers.begin();
	int counter = 0;
	bool flagExists = false;
	
	for(auto w : workers) {
		if(w -> getWorkerID() == id) {
			flagExists = true;
			break;
		}
		counter++;
	}
	
	if(!flagExists) throw DefaultException("Worker specified for removing does not belong to the team!");
	advance(it, counter);
	workers.erase(it);
	teamMemberCount--;
}

void Team::transferWorker(const int& id, Team* toTeam) {
	list<Worker*>::iterator it = workers.begin();
	int counter = 0;
	bool flagExists = false;
	
	for(auto w : workers) {
		if(w -> getWorkerID() == id) {
			flagExists = true;
			break;
		}
		counter++;
	}
	
	if(!flagExists) throw DefaultException("Worker specified for removing does not belong to the team!");
	
	advance(it, counter);
	
	try {
		toTeam -> addWorker(*it);
		workers.erase(it);
		teamMemberCount--;
	}
	catch(NumberExceeded& e) {
		cout << e.what();
	}
	catch(...) {
		cout << "Unrecognized error. Check out this!\n";
	}
}

string Team::getTeamName() const { return teamName; }
