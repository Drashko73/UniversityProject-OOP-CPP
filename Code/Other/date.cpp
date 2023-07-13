#include "date.h"

bool Date::validateDay(const int& day, const int& month, const int& year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month != 2) {
        if(day > days[month-1]) return false;
        return true;
    }
    if(day > 29) return false;
    if(day <= 28) return true;

    // it's 29, check year
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) return true;
            else return false;
        }
        else return true;
    }
    
    return false;
}

Date::Date(const int& h, const int& mi, const int& s, const int& d, const int& m, const int& y ) {
    
    if( h < 0 || h >= 24 ) throw NotValidDate();
    if( mi < 0 || mi >= 60 ) throw NotValidDate();
    if( s < 0 || s >= 60 ) throw NotValidDate();
    if( d < 1 || d > 31) throw NotValidDate();
    if( m < 1 || m > 12 ) throw NotValidDate();
    if( y < 1900 || y > 2100 ) throw NotValidDate();
    if(!validateDay(d, m, y)) throw NotValidDate();

    this->second = s;
    this->minute = mi;
    this->hour = h;
    this->day = d;
    this->month = m;
    this->year = y;
}

void Date::printDate() {
    string currentDate = "";
    
    currentDate += (day < 10) ? ("0"+to_string(day)):(to_string(day)); currentDate += "-";
    currentDate += (month < 10) ? ("0"+to_string(month)):(to_string(month)); currentDate += "-";
    currentDate += to_string(year) + " ";
    currentDate += (hour < 10) ? ("0"+to_string(hour)):(to_string(hour)); currentDate += ":";
    currentDate += (minute < 10) ? ("0"+to_string(minute)):(to_string(minute)); currentDate += ":";
    currentDate += (second < 10) ? ("0"+to_string(second)):(to_string(second));

    cout << currentDate << "\n";
}

void Date::setDate() {
    int hours, minutes, seconds, day, month, year;

    cout << "------------------------------------------------------------------------------------------------\n";
    cout << "CALLED FUNCTION FOR SETTING CUSTOM DATE...\n";
    cout << "In order to set the date please answer to the following questions:\n";

    cout << "\tHours: ";    cin >> hours;
    cout << "\tMinutes: ";  cin >> minutes;
    cout << "\tSconds: ";   cin >> seconds;
    cout << "\tDay: ";      cin >> day;
    cout << "\tMonth: ";    cin >> month;
    cout << "\tYear: ";     cin >> year;

    if( hours < 0 || hours >= 24 ) throw NotValidDate();
    if( minutes < 0 || minutes >= 60 ) throw NotValidDate();
    if( seconds < 0 || seconds >= 60 ) throw NotValidDate();
    if( day < 1 || day > 31) throw NotValidDate();
    if( month < 1 || month > 12 ) throw NotValidDate();
    if( year < 1900 || year > 2100 ) throw NotValidDate();
    if(!validateDay(day, month, year)) throw NotValidDate();

    this->second = seconds;
    this->minute = minutes;
    this->hour = hours;
    this->day = day;
    this->month = month;
    this->year = year;

    cout << "Date set successfully!\n";
    cout << "------------------------------------------------------------------------------------------------\n";
}

bool Date::operator<(Date& other) const {
    if(this->year < other.year) return true;
    if(this->year > other.year) return false;
    if(this->month < other.month) return true;
    if(this->month > other.month) return false;
    if(this->day < other.day) return true;
    if(this->day > other.day) return false;
    if(this->hour < other.hour) return true;
    if(this->hour > other.hour) return false;
    if(this->minute < other.minute) return true;
    if(this->minute > other.minute) return false;
    if(this->second < other.second) return true;
    return false;
}

bool Date::operator<=(Date& other) const {
    if(this->year < other.year) return true;
    if(this->year > other.year) return false;
    if(this->month < other.month) return true;
    if(this->month > other.month) return false;
    if(this->day < other.day) return true;
    if(this->day > other.day) return false;
    if(this->hour < other.hour) return true;
    if(this->hour > other.hour) return false;
    if(this->minute < other.minute) return true;
    if(this->minute > other.minute) return false;
    if(this->second > other.second) return false;
    return true;
}

bool Date::operator>(Date& other) const {
    if(this->year < other.year) return false;
    if(this->year > other.year) return true;
    if(this->month < other.month) return false;
    if(this->month > other.month) return true;
    if(this->day < other.day) return false;
    if(this->day > other.day) return true;
    if(this->hour < other.hour) return false;
    if(this->hour > other.hour) return true;
    if(this->minute < other.minute) return false;
    if(this->minute > other.minute) return true;
    if(this->second > other.second) return true;
    return false;
}

bool Date::operator>=(Date& other) const {
    if(this->year < other.year) return false;
    if(this->year > other.year) return true;
    if(this->month < other.month) return false;
    if(this->month > other.month) return true;
    if(this->day < other.day) return false;
    if(this->day > other.day) return true;
    if(this->hour < other.hour) return false;
    if(this->hour > other.hour) return true;
    if(this->minute < other.minute) return false;
    if(this->minute > other.minute) return true;
    if(this->second < other.second) return false;
    return true;
}

bool Date::operator==(Date& other) const {
    if(this->year != other.year) return false;
    if(this->month != other.month) return false;
    if(this->day != other.day) return false;
    if(this->hour != other.hour) return false;
    if(this->minute != other.minute) return false;
    if(this->second != other.second) return false;
    return true;
}

bool Date::operator!=(Date& other) const {
    if(this->year != other.year) return true;
    if(this->month != other.month) return true;
    if(this->day != other.day) return true;
    if(this->hour != other.hour) return true;
    if(this->minute != other.minute) return true;
    if(this->second != other.second) return true;
    return false;
}

ostream& operator<<(ostream& out, Date& date) {

    string currentDate = "";

    currentDate += (date.day < 10) ? ("0"+to_string(date.day)):(to_string(date.day)); currentDate += "-";
    currentDate += (date.month < 10) ? ("0"+to_string(date.month)):(to_string(date.month)); currentDate += "-";
    currentDate += to_string(date.year) + " ";
    currentDate += (date.hour < 10) ? ("0"+to_string(date.hour)):(to_string(date.hour)); currentDate += ":";
    currentDate += (date.minute < 10) ? ("0"+to_string(date.minute)):(to_string(date.minute)); currentDate += ":";
    currentDate += (date.second < 10) ? ("0"+to_string(date.second)):(to_string(date.second));

    return out << currentDate;
}