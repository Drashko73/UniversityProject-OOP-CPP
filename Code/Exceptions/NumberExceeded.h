#ifndef SEMINARSKI_NUMBEREXCEEDED_H
#define SEMINARSKI_NUMBEREXCEEDED_H

#include <iostream>
#include <string>
#include <exception>
using namespace std;

class NumberExceeded : public exception {

public:
    NumberExceeded(const string& msg= "Oops! Maximum number is exceeded!") : message(msg) {}
    const char* what() const throw() override { return message.c_str(); }
private:
    string message;
    
};

#endif