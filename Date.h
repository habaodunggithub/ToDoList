#pragma once

#include <iostream>
#include <string>

class Date {
public:
    Date();
    Date(int, int, int);

    int getDay() const;
    void setDay(int);
    int getMonth() const;
    void setMonth(int);
    int getYear() const;
    void setYear(int);
private:    
    int day;
    int month;
    int year;
};

int compare(const Date&, const Date&);
bool enterDate(Date& d, const std::string&);
std::string getDateString(const Date&);