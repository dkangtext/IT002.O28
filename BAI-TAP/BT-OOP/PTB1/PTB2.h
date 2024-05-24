#pragma once

#ifndef _PTB2
#define _PBT2

#include <iostream>
using namespace std;

// ax^2 + bx + c = 0;

class PTB2
{
private:
	double a, b, c;

public:
	PTB2();
	PTB2(double);
	PTB2(double, double);
	PTB2(double, double, double);
	void Nhap();
	void Xuat();
	void Giai();
};

#endif
