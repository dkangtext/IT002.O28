#pragma once
#ifndef _BCC
#define _BCC
#include <iostream>

using namespace std;

class BCC
{
private:
	int m;
	int n;

public:
	BCC(int = 2, int = 9);
	int GetM();
	int GetN();
	void SetM(int);
	void SetN(int);
	void SetMN(int, int);
	void Nhap();
	void Xuat();
	void InBCCm();
	void InBCCmn();
	void InBCCth();
};

#endif // !_BCC
