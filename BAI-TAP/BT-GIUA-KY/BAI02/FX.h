#pragma once
#ifndef _FX
#define _FX

#include <iostream>
using namespace std;

class FX
{
private:
	double a, b, c;

public:
	FX();
	FX(double);
	FX(double, double);
	FX(double, double, double);

	double getA() const;
	double getB() const;
	double getC() const;

	void SetA(double);
	void SetB(double);
	void SetC(double);

	friend istream& operator >> (istream&, FX&);
	friend ostream& operator << (ostream&, FX&);

	double GiaTriDaThuc(double);
	void TinhNghiemDaThuc() const;
	FX operator+(const FX&) const;
};

#endif // !_FX
