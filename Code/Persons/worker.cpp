#include "worker.h"

int Worker::idGenerator = 0;

Worker::Worker( const string& fn, const string& ln, const string& jt ) : Person(fn, ln), jobTitle(jt) {
    this -> assignedTask = nullptr;
    this ->penalties = 0;
    workerID = ++idGenerator;
}

Worker::~Worker() {
    delete assignedTask;
}

void Worker::assignTask(Task* task) { this -> assignedTask = task; }

string Worker::getJobTitle() const { return jobTitle; }

string Worker::getFullName() const {
    string s = "WorkerID: " + to_string(workerID) + " | Job title: " + jobTitle + " | Name: " + Person::getFullName();
    return s;
}

void Worker::setSalary(const double& s) {
    this -> salary = s;
}

void Worker::increasePenalties() { penalties++; }

void Worker::finishTask() { 
    if(assignedTask == nullptr) {
        cout << "\t\tMESSAGE: Cannot finish task! There is no task assigned to this worker\n";
        return;
    }

    if(assignedTask -> isFinished()) {
        cout << "\t\tMESSAGE: Task is already marked as finished\n";
        return;
    }

    assignedTask->changeStatus(FINISHED);
    cout << "\t\tMESSAGE: Task finished!\n";
}

Task* Worker::getAssignedTask() const { return this -> assignedTask; }

int Worker::getWorkerID() const { return workerID; }

int Worker::getPenalties() const { return this->penalties; }

double Worker::getSalary() const { return this->salary; }