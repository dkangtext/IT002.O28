#pragma once

#ifndef _DATHUC
#define _DATHUC

#include <iostream>
using namespace std;

class DATHUC
{
private:
    double* x;
    int NumberOfElement;

public:
    DATHUC();
    DATHUC(int n);
    DATHUC(const DATHUC& DT);
    ~DATHUC();

    int getNumberOfElement() const { return NumberOfElement; }
    double getX(int index) const { return x[index]; }
    void setX(int index, double value) { x[index] = value; }

    DATHUC& operator=(const DATHUC& DT);
    friend DATHUC  operator+(const DATHUC& DT1, const DATHUC& DT2);
    friend DATHUC  operator-(const DATHUC& DT1, const DATHUC& DT2);
    friend DATHUC  operator*(const DATHUC& DT1, const DATHUC& DT2);
    friend ostream& operator<<(ostream& os, const DATHUC& DT);
    friend istream& operator>>(istream& is, DATHUC& DT);

    bool PreAllZero(int k);
};

#endif
