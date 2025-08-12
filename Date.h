#pragma once

#include <iostream>

class Date {
public:
    Date();
    Date(int, int, int);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
private:    
    int day;
    int month;
    int year;
};

int compare(const Date&, const Date&);