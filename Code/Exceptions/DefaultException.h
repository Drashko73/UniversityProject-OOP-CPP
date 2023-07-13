#ifndef SEMINARSKI_DEFAULT_EXCEPTION_H
#define SEMINARSKI_DEFAULT_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

class DefaultException : public exception {
	
public:
	DefaultException(const string& msg= "Default exception has been thrown!") : message(msg) {}
	const char* what() const throw() override { return message.c_str(); }

private:
	string message;
	
};

#endif
