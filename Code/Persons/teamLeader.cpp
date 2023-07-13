#include "teamLeader.h"

TeamLeader::TeamLeader(const string& fn, const string& ln, const string& jt) : Person(fn, ln), Worker(fn, ln, jt), Director(fn, ln) {}

string TeamLeader::getFullName() const { return "Team Leader " + Worker::Person::getFullName(); }

string TeamLeader::getJobTitle() const { return "Team Leader"; }

void TeamLeader::checkWorkers(list<Worker*> workers) {
    
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "Team Leader called for CHECKING... Current date and time: ";

    struct tm *timeStruct;
    time_t currentTime = time(0);

    timeStruct = localtime(&currentTime);

    int year = timeStruct -> tm_year + 1900;
    int month = timeStruct -> tm_mon + 1;
    int day = timeStruct -> tm_mday;
    int hour = timeStruct -> tm_hour;
    int minute = timeStruct -> tm_min;
    int second = timeStruct -> tm_sec;

    Date currentDate(hour, minute, second, day, month, year);
    cout << currentDate << "\n";

    for(auto it : workers) {
        if(it -> getAssignedTask() != nullptr) {
            if( it->getAssignedTask()->isFinished() == false && *(it->getAssignedTask()->getExpectedFinishDate())<currentDate ) {
                it->increasePenalties();
            }
        }
    }

    cout << "------------------------------------------------------------------------------------------------\n";
}

void TeamLeader::assignTasks(list<Worker*> workers) {

    getchar();

    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "Team Leader called for ASSIGNING... Current date and time: ";

    struct tm *timeStruct;
    time_t currentTime = time(0);

    timeStruct = localtime(&currentTime);

    int year = timeStruct -> tm_year + 1900;
    int month = timeStruct -> tm_mon + 1;
    int day = timeStruct -> tm_mday;
    int hour = timeStruct -> tm_hour;
    int minute = timeStruct -> tm_min;
    int second = timeStruct -> tm_sec;

    Date currentDate(hour, minute, second, day, month, year);
    cout << currentDate << "\n";

    int workerID;
    string taskDescription, finish;
    int day1, month1, year1, hour1, minute1, second1;

    for(auto it : workers) {
        cout << "\tWorker: " << it -> getFirstName() << " " << it -> getLastName() << "\n";
        workerID = it->getWorkerID();
        cout << "\tFinish date (dd.mm.yyyy. hh:mm:ss): "; getline(cin, finish);
        cout << "\tTask description: "; getline(cin, taskDescription);

        try {
            parseDateInputAsString(day1, month1, year1, hour1, minute1, second1, finish);
            it->assignTask(new Task(workerID, new Date(hour, minute, second, day, month, year), new Date(hour1, minute1, second1, day1, month1, year1), taskDescription));
            cout << "+OK\n";
        }
        catch(DefaultException& e) { cout << e.what() << "\n"; }
        catch(NotValidDate e) { cout << e.what() << "\n"; }
        catch(...) { cout << "Unrecognizable error. Check this out!"; }
    }
    cout << "------------------------------------------------------------------------------------------------\n";
}

void TeamLeader::parseDateInputAsString(int& day, int& month, int& year, int& hour, int& minute, int& sec, const string& inputString) const {
    day = month = year = hour = minute = sec = -1;

    int number = 0;
    for(int i = 0; i < inputString.length(); i++) {

        if(inputString[i] >= '0' && inputString[i] <= '9') number = number * 10 + (inputString[i] - '0');
        else if(inputString[i] == '.') {
            if(day == -1) day = number;
            else if(month == -1) month = number;
            else if(year == -1) year = number;
            else throw DefaultException("Input string is not valid!");

            number = 0;
        }
        else if(inputString[i] == ':') {
            if(hour == -1) hour = number;
            else if(minute == -1) minute = number;
            else throw DefaultException("Input string is not valid!");

            number = 0;
        }
        else if(inputString[i] == ' ') continue;
        else throw DefaultException("Input string is not valid!");
    }

    if(number != -1 && sec == -1) sec = number;

} 
