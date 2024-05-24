#pragma once
#ifndef _GIASUC
#define _GIASUC

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GIASUC
{
protected:
	int Loai;

public:
	~GIASUC();
	GIASUC();
	virtual void Keu() = 0;
	virtual int Sua() = 0;
	virtual int SinhCon() = 0;
	virtual int getLoai() = 0;
};

#endif // !_GIASUC