#include "project.h"

int Project::idGenerator = 0;

Project::Project(const string& name, Date* startDate, Date* expectedEndDate, const double& earnings, const double& expenses) {

    if(*expectedEndDate <= *startDate)
        throw DefaultException("Specified expected finish date is before start date!");

    this -> projectName = name;
    this -> startDate = startDate;
    this -> expectedFinishDate = expectedEndDate;
    this -> earnings = earnings;
    this -> expenses = expenses;
    this -> projectStatus = NOT_FINISHED;
    this -> projectID = ++idGenerator;
}

Project::~Project() {
    delete startDate;
    delete expectedFinishDate;
}

bool Project::isFinished() const { return this -> projectStatus == FINISHED; }

void Project::changeStatus(STATUS s) {
    this -> projectStatus = s;
    if(s == FINISHED)
        writeArchiveAboutProject();
}

double Project::getExpenses() const { return this -> expenses; }

double Project::getEarnings() const { return this -> earnings; }


void Project::writeArchiveAboutProject() const {

    ofstream outfile;
    string projectNameForFile = "";
    for(int i = 0; i < projectName.length(); i++) {
        if(projectName[i] == ' ') projectNameForFile += "_";
        else projectNameForFile += projectName[i];
    }

    string datName = "../Code/FinishedProjects/" + projectNameForFile + ".txt";
    struct tm *timeStruct;
    time_t currentTime = time(0);

    timeStruct = localtime(&currentTime);

    int year = timeStruct -> tm_year + 1900;
    int month = timeStruct -> tm_mon;
    int day = timeStruct -> tm_mday;
    int hour = timeStruct -> tm_hour;
    int minute = timeStruct -> tm_min;
    int second = timeStruct -> tm_sec;

    Date currentDate(hour, minute, second, day, month, year);
    
    outfile.open(datName);

    outfile << "Project ID: " << projectID << "\n";
    outfile << "Project Name: " << projectName << "\n";
    outfile << "Cost of the project: " << expenses << "\n";
    outfile << "Earnings of the project: " << earnings << "\n";
    outfile << "Start date: ";
    outfile << *startDate << "\n";
    outfile << "Finished: ";
    outfile << currentDate << "\n";

    outfile.close();

    cout << "\t[ File written to: ../FinishedProjects/" << projectNameForFile << ".txt ]" << endl;

}
