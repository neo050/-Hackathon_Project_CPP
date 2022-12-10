#pragma once
#include<iostream>
#include <ctime>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    bool setDay(int);
    bool setMonth(int);
    bool setYear(int);
public:
    Date();
    Date(int, int, int);
    Date(const Date&);
    ~Date();
    void today();
    int getDay()const { return day; }
        int getMonth()const { return month; }
        int getYear()const;
    const bool validDate(int, int, int)const;
    void setDate(int, int, int);
    void printDate()const;
    void printMonth()const;
    int getDays()const;
    bool isLeapYear()const;
    Date getNextDate()const;
    friend ostream& operator<<(ostream& os, Date& A);
    friend istream& operator >> (istream& input, Date& A);
};
