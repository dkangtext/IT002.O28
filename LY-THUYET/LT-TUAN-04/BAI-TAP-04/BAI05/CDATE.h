#pragma once
#ifndef _CDATE
#define _CDATE

#include <iostream>
using namespace std;

class CDATE
{
private:
    int day, month, year;

public:
    CDATE(int = 1, int = 1, int = 1);
    
    bool checkday();
    
    CDATE datelimit();
    
    void SetDate(const int&, const int&, const int&);
    void SetDay(const int&);
    void SetMonth(const int&);
    void SetYear(const int&);
    
    int GetDay();
    int GetMonth();
    int GetYear();

    friend CDATE operator+(const int&, CDATE);
    friend CDATE operator+(CDATE, const int&);
    friend CDATE operator-(CDATE, const int&);
    friend CDATE operator-(const int&, CDATE);
    friend CDATE operator-(CDATE, CDATE);

    friend ostream& operator<<(ostream&, const CDATE&);
    friend istream& operator>>(istream&, CDATE&);
};

#endif