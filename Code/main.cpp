/*
    *   
    *   ----------------------------------------------------------------------------
    *   Seminarski rad iz predmeta Praktikum iz objektno-orijentisanog programiranja
    *   Tema projekta: Sistemi za rukovodjenje projektima IT kompanije
    *   Autor: Radovan Draskovic 73/2021
    *   Datum: 08.07.2023.
    *   Opis teme:
    *       - Izabrati neku hijerarhiju zaposlenih prema nekoj kompaniji
    *       - Definisati projekte i timove zaposlenih koji rade na projektima
    *       - Definisati podelu zadataka sa rokovima
    *       - Pracenje probijanja rokova, smanjenje plate
    *   
*/

#include "./Teams/team.h"
#include "./Teams/engineering.h"
#include "./Teams/operations.h"
#include "./Teams/sales.h"
#include "./Teams/hr.h"
#include "./Teams/finance.h"

#include "./Persons/person.h"
#include "./Persons/worker.h"
#include "./Persons/director.h"
#include "./Persons/teamLeader.h"

#include "./Other/date.h"
#include "./Other/task.h"
#include "./Other/project.h"
#include "./Other/instanceof.h"

#define NEW_LINES "\n\n\n";

static void hello(void);
static void presentPersons(vector<Person*>*, bool);

int main(int argc, char **argv) {

    hello();

    vector<Team*> createdTeams;
    vector<Person*> persons;

    Person *marko = new Person("Marko", "Markovic");
    Person *milica = new Person("Milica", "Milic");

    Worker *pera = new Worker("Petar", "Petrovic", "Software Engineer");
    Worker *nidza = new Worker("Nikola", "Markovic", "DevOps");
    
    Worker *laza = new Worker("Lazar", "Lazic", "Financial Analyst");
    Worker *ognjen = new Worker("Ognjen", "Petrovic", "Account Manager");
    
    Worker *nadezda = new Worker("Nadezda", "Markovic", "Operations consultant");
    Worker *mihajlo = new Worker("Mihajlo", "Zajic", "Assistant");

    Worker *nemanja = new Worker("Nemanje", "Petrovic", "HR Trainee");
    Worker *mare = new Worker("Marko", "Milosavljevic", "HR Trainee");

    Worker *nevena = new Worker("Nevena", "Nedic", "Marketing manager");
    Worker *marica = new Worker("Marica", "Maric", "Sales representative");

    Worker *testWorker = new Worker("Test", "Test", "Test"); // Worker used to demonstrate exception handling

    Director *nikola = new Director("Nikola", "Nikolic");

    persons.push_back(marko);
    persons.push_back(milica);
    persons.push_back(pera);
    persons.push_back(nidza);
    persons.push_back(laza);
    persons.push_back(ognjen);
    persons.push_back(nadezda);
    persons.push_back(mihajlo);
    persons.push_back(nemanja);
    persons.push_back(mare);
    persons.push_back(nikola);
    persons.push_back(nevena);
    persons.push_back(marica);

    Team *imiEngineering = new Engineering("Imi engineering", 3);
    Team *imiFinance = new Finance("Imi finance", 3);
    Team *imiOperations = new Operations("Imi operations", 2);
    Team *imiHR = new HR("Imi HR", 2);
    Team *imiSales = new Sales("Imi sales", 3);
    
    createdTeams.push_back(imiEngineering);
    createdTeams.push_back(imiFinance);
    createdTeams.push_back(imiOperations);
    createdTeams.push_back(imiHR);
    createdTeams.push_back(imiSales);

    presentPersons(&persons, false);

    cout << "================================================================================================\n";
    while(1) {
        cout << "ADD SKILLS TO A SPECIFIED WORKER:\n";
        cout << "Choose number in front of a person to add skill (choose -1 to stop):\n\n";
        for(int i = 0; i < persons.size(); i++) {
            int a = i+1;
            cout << "[" << a << "] " << persons[i]->getFirstName() << " " << persons[i] -> getLastName() << "\n";
        }

        int op;
        string skill;

        cout << "\n+Number: ";
        cin >> op;
        if(op != -1 and (op < 1 || op > persons.size())) {
            cout << "\tERROR: Invalid number!\n";
            continue;
        }

        if(op == -1) break;
        cout << "Enter skill (one word): ";
        cin >> skill;
        persons[op-1] -> addSkill(skill);
        cout << "--------------------------------------------------------------------------------------------\n";
    }
    getchar();

    presentPersons(&persons, true);

    cout << "================================================================================================\n";
    cout << "ADDING WORKERS TO A TEAM:\n";
    
        // Engineering team
    try {
        imiEngineering -> addWorker(pera);
        imiEngineering -> addWorker(nidza);
    }
    catch(NumberExceeded e) { cout << e.what() << "\n"; }
    catch(...) { cout << "Unrecognized error, check this!\n"; }

        // Finance team
    try {
        imiFinance -> addWorker(laza);
        imiFinance -> addWorker(ognjen);
    }
    catch(NumberExceeded e) { cout << e.what() << "\n"; }
    catch(...) { cout << "Unrecognized error, check this!\n"; }

        // HR team
    try {
        imiHR -> addWorker(mare);
        imiHR -> addWorker(nemanja);
        imiHR -> addWorker(testWorker);
    }
    catch(NumberExceeded e) { cout << e.what() << "\n"; }
    catch(...) { cout << "Unrecognized error, check this!\n"; }

        // Operations team
    try {
        imiOperations -> addWorker(nadezda);
        imiOperations -> addWorker(mihajlo);
        imiOperations -> addWorker(testWorker);
    }
    catch(NumberExceeded e) { cout << e.what() << "\n"; }
    catch(...) { cout << "Unrecognized error, check this!\n"; }

        // Sales team
    try {
        imiSales -> addWorker(nevena);
        imiSales -> addWorker(marica);
    }
    catch(NumberExceeded e) { cout << e.what() << "\n"; }
    catch(...) { cout << "Unrecognized error, check this!\n"; }

    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "CALLING DIRECTOR IN ORDER TO CHOOSE TEAM LEADERS:\n";
    
    // Commented lines below represent transfering and removing worker from a team
    /*
    imiEngineering -> transferWorker(1, imiFinance); // transfer workers from one team to another one
    try {
		imiFinance -> removeWorker(1);
    }
    catch(DefaultException& e) {
		cout << e.what();
	}
	catch(...) {
		cout << "Unrecognized error! Check this!\n";
	}
	*/
    
    bool directorCalled = false; // Prevent choosing team leader more than once if multiple directors are present.
    for(int i = 0; i < persons.size(); i++) {
        if(instanceof<Director>(persons[i])) {
            if(!directorCalled) {
                directorCalled = true;
                cout << "\tCalled " << persons[i]->getFullName() << "\n";
                for(auto tm : createdTeams) {
                    cout << "\tChoosing team leader for team: " << tm -> getTeamName() << "\n";
                    dynamic_cast<Director*>(persons[i]) -> choseTeamLeader(tm);
                }
            }
        }
    }
    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "PRESENT CREATED TEAMS:\n";
    for(auto it : createdTeams)
        it -> presentTeam();
    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "DEFINE PROJECT FOR EACH TEAM:\n";
    cout << "------------------------------------------------------------------------------------------------\n";
    for(auto tm : createdTeams) {
        cout << "Create project for team: " << tm -> getTeamName() << "\n";
        tm -> startProject();
        getchar();
    }
    cout << "================================================================================================\n";
    cout << NEW_LINES;
    
    cout << "================================================================================================\n";
    cout << "INTERACTIVE WAY TO ASSIGN TASKS TO EACH TEAM MEMBER\n";
    cout << "[ In order to assign tasks choose the correct option [Option #1]... ]\n";

    for(auto tm : createdTeams) {
        if(instanceof<Operations>(tm)) { 
            for(auto tm2 : createdTeams) {
                cout << "CURRENT TEAM: " << tm2 -> getTeamName() << "\n";
                dynamic_cast<Operations*>(tm) -> callTeamLeader(tm2);
            }
        }
    }

    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "CALLING TEAM LEADERS IN ORDER TO CHECK WORKERS AND THEIR TASKS:\n";
    cout << "Please choose option [2] in order to ask team leader to check the deadline of assigned tasks...\n";
    for(auto tm : createdTeams) {
        if(instanceof<Operations>(tm)) {
            for(auto tm2 : createdTeams) {
                cout << "CURRENT TEAM: " << tm2 -> getTeamName() << endl;
                dynamic_cast<Operations*>(tm) -> callTeamLeader(tm2);
            }
        }
    }
    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "CALLING FINANCE TEAM TO CALCULATE SALARY FOR WORKERS:\n";
    for(auto tm : createdTeams) {
        if(instanceof<Finance>(tm)) {
            for(auto tm2 : createdTeams) {
                cout << "\tCalculating salary for team: " << tm2 -> getTeamName() << " ...\n";
                dynamic_cast<Finance*>(tm) -> calculateSalaryForWorkers(tm2);
            }
        }
    }
    cout << "================================================================================================\n";
    cout << NEW_LINES;
    
    cout << "================================================================================================\n";
    cout << "LIST SALARY FOR EACH WORKER:\n";
    for(auto it : persons) {
        if(instanceof<Worker>(it)) {
            cout << "\t" << dynamic_cast<Worker*>(it) -> getWorkerID() << " " << it -> getFirstName() << " " << it -> getLastName() << " Salary: " << dynamic_cast<Worker*>(it) -> getSalary() << " (Penalty: "<< dynamic_cast<Worker*>(it) -> getPenalties() << " )\n";
        }
    }
    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "CALLING HR TEAM TO CHECK SKILLS OF WORKERS:\n";
    for(auto tm : createdTeams) {
        if(instanceof<HR>(tm)) {
            for(auto tm2 : createdTeams) {
                cout << "\tTeam name: " << tm2 -> getTeamName() << "\n";
                dynamic_cast<HR*>(tm) -> checkWorkerSkills(tm2);
            }
        }
    }
    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "FINISHING TASKS:\n";
    for(auto it : persons) {
        if(instanceof<Worker>(it)) {
            cout << "\tWorker: " << dynamic_cast<Worker*>(it) -> getWorkerID() << " " <<  it -> getFirstName() << " " << it -> getLastName() << "\n";
            dynamic_cast<Worker*>(it) -> finishTask();
        }
    }

    cout << "================================================================================================\n";
    cout << NEW_LINES;

    cout << "================================================================================================\n";
    cout << "FINISHING PROJECTS:\n";
    for(auto tm : createdTeams)
        tm -> finishProject();
    cout << "================================================================================================\n";
    cout << NEW_LINES;

    // Delete created teams
    for(auto it : createdTeams) delete it;
    delete nikola;
    delete marko;
    delete milica;
    delete testWorker;

    return 0;
}

/*
    *
    *
    *
    * 
    *   Welcome banner and helper functions :) 
    * 
    * 
    *   
    * 
*/

static void hello(void) {

    cout << NEW_LINES;
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << ">>>   **  ** **  **      ****  ****  ****  ****    ****  ***  ****    *  ****   ****  *****  <<<\n";
    cout << ">>>   **  * * *  **      *  *  *  *  *  *  *  *    *  *  * *  *  *    *  *      *       *    <<<\n";
    cout << ">>>   **  *   *  **  --  ****  *  *  *  *  ****    ****  **   *  *    *  ****   *       *    <<<\n";
    cout << ">>>   **  *   *  **      *     *  *  *  *  *       *     * *  *  *    *  *      *       *    <<<\n";
    cout << ">>>   **  *   *  **      *     ****  ****  *       *     *  * ****  ***  ****   ****    *    <<<\n";
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << NEW_LINES;

}

static void presentPersons(vector<Person*> *reference, bool displaySkills) {
    cout << "================================================================================================\n";
    cout << "PRESENT CREATED PERSONS:\n";
    for(auto it : *reference) {
        cout << "\t" << it -> getFullName() << "\n";
        if(displaySkills) {
            cout << "\t\tList of skills: "; it -> displaySkills();
        }
    }
    cout << "================================================================================================\n";
    cout << NEW_LINES;
}
