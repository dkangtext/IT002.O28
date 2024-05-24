#pragma once
#ifndef _SOPHUC
#define _SOPHUC

#include<iostream>
using namespace std;

class SOPHUC
{
private:
    double phanThuc;
    double phanAo;
    static int Dem;

public:
    ~SOPHUC();
    SOPHUC();
    SOPHUC(double t, double a);

    void Nhap();
    void Xuat();

    double GetphanThuc() const;
    double GetphanAo() const;
    static int GetDem();

    void SetphanThuc(double);
    void SetphanAo(double);
    void SetSoPhuc(double, double);

    SOPHUC operator+(const SOPHUC& sp);
    SOPHUC operator-(const SOPHUC& sp);
    SOPHUC operator*(const SOPHUC& sp);
    SOPHUC operator/(const SOPHUC& sp);

    bool operator==(const SOPHUC& sp);
    bool operator!=(const SOPHUC& sp);
    bool operator>(const SOPHUC& sp);
    bool operator<(const SOPHUC& sp);
    bool operator>=(const SOPHUC& sp);
    bool operator<=(const SOPHUC& sp);

    friend ostream& operator<<(ostream& os, const SOPHUC& sp);
    friend istream& operator>>(istream& is, SOPHUC& sp);
};

#endif
