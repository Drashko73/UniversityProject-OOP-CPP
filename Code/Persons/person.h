#ifndef SEMINARSKI_PERSON_H
#define SEMINARSKI_PERSON_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Person {

public:
    Person( const string&, const string& );
    virtual string getFullName() const;
    void addSkill(const string&);
    string getFirstName() const;
    string getLastName() const;
    void displaySkills() const;
    set<string> getSkills() const;

private:
    string firstName;
    string lastName;
    set<string> skills;
};

#endif