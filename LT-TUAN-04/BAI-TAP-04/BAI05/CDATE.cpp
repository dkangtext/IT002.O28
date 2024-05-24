#include "CDATE.h"
#include <iostream>
using namespace std;

CDATE::CDATE(int day, int month, int year)
{
    this->month = (month >= 1 && month <= 12) ? month : 0;
    this->year = (year >= 0) ? year : 0;
    if (checkday() == 1)
        this->day = day;
    else this->day = 1;
}

bool CDATE::checkday()
{
    if (day > 31 || day < 1)
        return 0;
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return 0;
    }
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day > 29)
                return 0;
        }
        else if (day > 28)
            return 0;
    }
    return 1;
}

ostream& operator<<(ostream& os, const CDATE& a)
{
    os << a.day << "/" << a.month << "/" << a.year << endl;
    return os;
}

istream& operator>>(istream& is, CDATE& a)
{
    do
    {
        cout << "Nhap nam: ";
        is >> a.year;
    } while (a.year < 0);
    do
    {
        cout << "Nhap thang: ";
        is >> a.month;
    } while (a.month < 0 || a.month >12);
    do
    {
        cout << "Nhap ngay: ";
        is >> a.day;
    } while (!a.checkday());
    return is;
}

CDATE CDATE::datelimit()
{
    CDATE limit;
    limit.month = month;
    limit.year = year;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        limit.day = 30;
    else
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                limit.day = 29;
            else limit.day = 28;
        }
        else limit.day = 31;
    return limit;
}

CDATE operator+(CDATE date, const int& a)
{
    CDATE limit = date.datelimit();
    date.day += a;
    while (date.day > limit.day)
    {
        date.day -= limit.day;
        date.month++;
        if (date.month > 12)
        {
            date.month -= 12;
            date.year++;
        }
        limit = date.datelimit();
    }
    return date;
}

CDATE operator+(const int& a, CDATE date)
{
    CDATE limit = date.datelimit();
    date.day += a;
    while (date.day > limit.day)
    {
        date.day -= limit.day;
        date.month++;
        if (date.month > 12)
        {
            date.month -= 12;
            date.year++;
        }
        limit = date.datelimit();
    }
    return date;
}

CDATE operator-(CDATE date, const int& a)
{
    CDATE limit = date.datelimit();
    date.day -= a;
    while (date.day < 1)
    {
        date.month--;
        if (date.month < 1)
        {
            date.month += 12;
            date.year--;
        }
        limit = date.datelimit();
        date.day += limit.day;
    }
    return date;
}

CDATE operator-(const int& a, CDATE date)
{
    CDATE limit = date.datelimit();
    date.day -= a;
    while (date.day < 1)
    {
        date.month--;
        if (date.month < 1)
        {
            date.month += 12;
            date.year--;
        }
        limit = date.datelimit();
        date.day += limit.day;
    }
    return date;
}

CDATE operator-(CDATE a, CDATE b)
{
    a.month -= b.month;
    a.year -= b.year;
    while (a.month < 1)
    {
        a.month += 12;
        a.year -= 1;
    }
    a = a - b.day;
    return a;
}

void CDATE::SetDate(const int& day, const int& month, const int& year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void CDATE::SetDay(const int& day)
{
    this->day = day;
}

void CDATE::SetMonth(const int& month)
{
    this->month = month;
}

void CDATE::SetYear(const int& year)
{
    this->year = year;
}

int CDATE::GetDay()
{
    return day;
}

int CDATE::GetMonth()
{
    return month;
}

int CDATE::GetYear()
{
    return year;
}