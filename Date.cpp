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

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
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