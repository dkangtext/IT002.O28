#pragma once

#ifndef _PTB1
#define _PTB1

#include <iostream>
using namespace std;

// ax + b = 0

class PTB1
{
private:
	double a, b;

public:
	PTB1();
	PTB1(double);
	PTB1(double, double);
	void Nhap();
	void Xuat();
	void Giai();
};

#endif 