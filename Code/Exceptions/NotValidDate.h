#ifndef SEMINARSKI_NOT_VALID_DATE_H
#define SEMINARSKI_NOT_VALID_DATE_H

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class NotValidDate : public exception {

public:
    NotValidDate(const string& msg= "Date format is not valid!") : message(msg) {}
    const char* what() const throw() override { return message.c_str(); }

private:
    string message;
};

#endif