#ifndef SEMINARSKI_WORKER_H
#define SEMINARSKI_WORKER_H

#include "person.h"
#include "../Other/task.h"

class Worker : public virtual Person {

public:
    Worker( const string&, const string&, const string& );
    ~Worker();

    string virtual getJobTitle() const;
    string virtual getFullName() const;
    void setSalary(const double&);
    void assignTask(Task*);
    void finishTask();
    void increasePenalties();

    Task* getAssignedTask() const;
    int getWorkerID() const;
    int getPenalties() const;
    double getSalary() const;

protected:
    static int idGenerator;

private:
    string jobTitle;
    int workerID;
    double salary;
    Task* assignedTask;
    int penalties;

};

#endif