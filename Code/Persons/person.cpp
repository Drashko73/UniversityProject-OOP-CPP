#include "person.h"

Person::Person( const string& fn, const string& ln ) : firstName(fn), lastName(ln) {}

string Person::getFullName() const { return firstName + " " + lastName; }

void Person::addSkill ( const string& skill ) {
    auto test = skills.insert(skill);
    if(test.second == true)
        cout << "\tMESSAGE: Skill added!\n";
    else
        cout << "\tMESSAGE: Skill already exists\n";
}

void Person::displaySkills() const {

    if(skills.empty()) {
        cout << "None...\n";
        return;
    }

    for(auto it : skills)
        cout << it << " ";
    cout << "\n";
}

set<string> Person::getSkills() const { return skills; }

string Person::getFirstName() const { return firstName; }

string Person::getLastName() const { return lastName; }