#ifndef SEMINARSKI_DATE_H
#define SEMINARSKI_DATE_H

#include <iostream>
#include <string>
#include "../Exceptions/NotValidDate.h"
using namespace std;

class Date {
    
public:
    Date(const int& =0, const int& =0, const int& =0, const int& =1, const int& =1, const int& =2023);
    void printDate();
    void setDate();
    bool operator<(Date&) const;
    bool operator<=(Date&) const;
    bool operator>(Date&) const;
    bool operator>=(Date&) const;
    bool operator==(Date&) const;
    bool operator!=(Date&) const;
    friend ostream& operator<<(ostream&, Date&);

private:
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;

    bool validateDay(const int&, const int&, const int&);
};

#endif