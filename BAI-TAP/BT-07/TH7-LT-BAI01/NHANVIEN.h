#pragma once
#ifndef _NHANVIEN
#define _NHANVIEN

#include <iostream>
#include <string>
using namespace std;

class NHANVIEN
{
protected:
	char HoTen[100];
	int Ngay, Thang, Nam;

public:
	~NHANVIEN();
	NHANVIEN();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};

#endif // !_NHANVIEN