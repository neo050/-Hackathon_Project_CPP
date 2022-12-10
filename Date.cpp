#include"Date.h"
Date::Date()
{
    today();
}
void Date::today()
{
    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    day = timeinfo.tm_mday;
    month = timeinfo.tm_mon + 1;
    year = timeinfo.tm_year + 1900;
}
bool Date::setYear(int y)
{
    if (y < 0)
        return false;
    year = y;
    return true;
}
bool Date::setMonth(int m)
{
    if (m >= 1 && m <= 12)
    {
        month = m;
        return true;
    }
    return false;
}
bool Date::setDay(int d)
{
    if (d >= 1 && d <= this->getDays())
    {
        day = d;
        return true;
    }
    return false;
}

Date::Date(int d, int m, int y)
{

    if (!setYear(y) || !setMonth(m) || !setDay(d))
        today();


}
const bool Date::validDate(int d, int m, int y)const
{
    if (y < 0)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > this->getDays())
        return false;
    return true;
}
void Date::setDate(int d, int m, int y)
{
    if (d == 0 || m == 0 || y == 0) {
        setYear(y);
        setMonth(m);
        setDay(d);
    }
    else if (!validDate(d, m, y))
    {
        today();
    }
    else
    {
        setYear(y);
        setMonth(m);
        setDay(d);
    }

}
Date::Date(const Date& d)
{
    day = d.day;
    month = d.month;
    year = d.year;

}

Date::~Date()
{
}

Date Date::getNextDate()const
{


    if (day == this->getDays() && month == 12)
    {
        return Date(1, 1, year + 1);
    }
    if (day == this->getDays() && month != 12)
    {
        return Date(1, month + 1, year);
    }
    return Date(day + 1, month, year);
}

bool Date::isLeapYear()const
{
    if (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)))
    {
        return true;
    }

    return false;

}

int Date::getDays()const
{
    switch (month)
    {
    case 2:
        if (isLeapYear())
            return 29;
        return 28;


    case 4:
    case 6:
    case 9:
    case 11:

        return 30;
    default:
        return 31;
    }
}

void Date::printDate()const
{
    if (day < 10)
    {
        cout << "0" << day << "/";
    }
    else
    {
        cout << day << "/";
    }

    if (month < 10)
    {
        cout << "0" << month << "/" << year << endl;
    }
    else
    {
        cout << month << "/" << year << endl;
    }
}

void Date::printMonth()const
{
    char arr[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dev" };
    cout << arr[month] << endl;
}

ostream& operator<<(ostream& os,  Date& A)
{
    A.printDate();

    return os;
}

istream& operator >> (istream& is, Date& A)
{
    int day;
    int month;
    int year;
    cout << "Enter -> day, month ,year" << endl;
    cin >> day >> month >> year;
    cout << endl;
    A.setDate(day ,month , year);

    return is;
}
int Date::getYear() const
{ 
    int y = year;
    return y; 
}