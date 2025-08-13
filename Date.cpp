#include "Date.h"

Date::Date() {}

Date::Date(int day, int month, int year)
    : day(day)
    , month(month)
    , year(year)
    {}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    this->day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    this->month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    this->year = year;
}

int compare(const Date& d1, const Date& d2) {
    if (d1.getYear() != d2.getYear()) {
        if (d1.getYear() > d2.getYear())
            return 1;
        else
            return -1;
    }

    if (d1.getMonth() != d2.getMonth()) {
        if (d1.getMonth() > d2.getMonth())
            return 1;
        else 
            return -1;
    }

    if (d1.getDay() > d2.getDay())
        return 1;
    else if (d1.getDay() == d2.getDay()) 
        return 0;
    
    return -1;
}

bool enterDate(Date& d, const std::string& dateString) {
    size_t idx;
    std::string temp;

    int pos1 = dateString.find("/");
    if (pos1 == std::string::npos) return false;

    temp = dateString.substr(0, pos1);
    int day = std::stoi(temp, &idx, 10);
    if (idx == 0) return false;

    d.setDay(day);

    int pos2 = dateString.find("/", pos1 + 1);
    if (pos2 == std::string::npos) return false;
    
    temp = dateString.substr(pos1 + 1, pos2 - pos1 - 1);
    int month = std::stoi(temp, &idx, 10);
    if (idx == 0) return false;

    d.setMonth(month);
    temp = dateString.substr(pos2 + 1);
    int year = std::stoi(temp, &idx, 10);
    if (idx == 0) return false;

    d.setYear(year);

    return true;
}