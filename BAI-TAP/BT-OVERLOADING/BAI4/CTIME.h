#pragma once
#ifndef _CTIME
#define _CTIME
#include <iostream>
using namespace std;

class CTIME
{
private:
    int hour, minute, second;

public:
    CTIME(int = 0, int = 0, int = 0);

    void SetTime(const int&, const int&, const int&);
    void Sethour(const int&);
    void Setminute(const int&);
    void Setsecond(const int&);
    
    int Gethour();
    int Getminute();
    int Getsecond();
    
    friend ostream& operator<<(ostream&, const CTIME&);
    friend istream& operator>>(istream&, CTIME&);
    
    friend CTIME operator+(const int&, const CTIME&);
    friend CTIME operator+(const CTIME&, const int&);
    friend CTIME operator-(const CTIME&, const int&);
    
    CTIME operator++();
    CTIME operator++(int);
    CTIME operator--();
    CTIME operator--(int);
    
    friend CTIME operator-(const CTIME&, const CTIME&);
};

#endif // !_CTIME

