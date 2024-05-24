#pragma once
#ifndef _MANG1C
#define _MANG1C
#include <iostream>
using namespace std;

class MANG1C
{
private:
	int* a;
	int n;

public:
	MANG1C();
	MANG1C(int);
	MANG1C(int, int);
	MANG1C(int = 0, int = 0);
	~MANG1C();

	int* GetA();
	int GetN();

	void Nhap();
	void Xuat();

	friend istream& operator>>(istream& is, MANG1C& m);
	friend ostream& operator<<(ostream& os, const MANG1C& m);
};

#endif // !_MANG1C

