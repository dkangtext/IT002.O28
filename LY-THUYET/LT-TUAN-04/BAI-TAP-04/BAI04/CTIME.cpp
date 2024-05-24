#include "CTIME.h"

CTIME::CTIME(int hour, int minute, int second)
{
    this->hour = (hour >= 0 && hour <= 23) ? hour : 0;
    this->minute = (minute >= 0 && hour <= 60) ? minute : 0;
    this->second = (second >= 0 && hour <= 60) ? second : 0;
}

ostream& operator<<(ostream& os, const CTIME& a)
{
    os << a.hour << ":" << a.minute << ":" << a.second << endl;
    return os;
}

istream& operator>>(istream& is, CTIME& a)
{
    do
    {
        cout << "Nhap gio: ";
        is >> a.hour;
    } while (a.hour < 0 || a.hour>23);
    do
    {
        cout << "Nhap phut: ";
        is >> a.minute;
    } while (a.minute < 0 || a.minute >59);
    do
    {
        cout << "Nhap giay: ";
        is >> a.second;
    } while (a.second < 0 || a.second>59);
    return is;
}

CTIME operator+(const CTIME& time, const int& a)
{
    CTIME kq;
    int demphut = 0, demgio = 0;
    kq.second = time.second + a;
    
    while (kq.second >= 60)
    {
        demphut++;
        kq.second -= 60;
    }
    kq.minute = demphut + time.minute;
    
    while (kq.minute >= 60)
    {
        demgio++;
        kq.minute -= 60;
    }
    kq.hour = demphut + time.hour;
    
    while (kq.hour >= 24)
    {
        kq.hour -= 24;
    }
    return kq;
}

CTIME operator+(const int& a, const CTIME& time)
{
    CTIME kq;
    int demphut = 0, demgio = 0;
    kq.second = time.second + a;
    while (kq.second >= 60)
    {
        demphut++;
        kq.second -= 60;
    }
    kq.minute = demphut + time.minute;
    while (kq.minute >= 60)
    {
        demgio++;
        kq.minute -= 60;
    }
    kq.hour = demphut + time.hour;
    while (kq.hour >= 24)
    {
        kq.hour -= 24;
    }

    return kq;
}

CTIME operator-(const CTIME& time, const int& a)
{
    CTIME kq;
    int demphut = 0, demgio = 0;
    
    kq.second = time.second - a;
    while (kq.second < 0)
    {
        demphut++;
        kq.second += 60;
    }
    
    kq.minute = time.minute - demphut;
    while (kq.minute < 0)
    {
        demgio++;
        kq.minute += 60;
    }
    
    kq.hour = time.hour - demgio;
    while (kq.hour < 0)
    {
        kq.hour += 24;
    }

    return kq;
}

CTIME CTIME::operator++()
{
    return *this + 1;
}

CTIME CTIME::operator++(int)
{
    CTIME time = *this;
    *this = *this + 1;
    return time;
}

CTIME CTIME::operator--()
{
    return *this - 1;
}

CTIME CTIME::operator--(int)
{
    CTIME time = *this;
    *this = *this - 1;
    return time;
}

CTIME operator-(const CTIME& a, const CTIME& b)
{
    CTIME kq;
    kq.hour = a.hour - b.hour;
    kq.minute = a.minute - b.minute;
    kq.second = a.second - b.second;
    int demphut = 0, demgio = 0;
    while (kq.second < 0)
    {
        demphut++;
        kq.second += 60;
    }
    kq.minute = kq.minute - demphut;
    while (kq.minute < 0)
    {
        demgio++;
        kq.minute += 60;
    }
    kq.hour = kq.hour - demgio;
    while (kq.hour < 0)
    {
        kq.hour += 24;
    }
    return kq;
}

void CTIME::SetTime(const int& hour, const int& minute, const int& second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

void CTIME::Sethour(const int& hour)
{
    this->hour = hour;
}

void CTIME::Setminute(const int& minute)
{
    this->minute = minute;
}

void CTIME::Setsecond(const int& second)
{
    this->second = second;
}

int CTIME::Gethour()
{
    return hour;
}

int CTIME::Getminute()
{
    return minute;
}

int CTIME::Getsecond()
{
    return second;
}