#pragma once
#ifndef _LAPTRINHVIEN
#define _LAPTRINHVIEN
#include <iostream>
#include "NHANVIEN.h"

using namespace std;

class LAPTRINHVIEN : public NHANVIEN
{
private:
	float soGioLamThem;

public:
	~LAPTRINHVIEN();
	LAPTRINHVIEN(string = "", string = "", int = 0, string = "", string = "", double = 0, float = 0);
	float getSoGioLamThem() const;
	void setSoGioLamThem(float);
	virtual void Nhap();
	virtual void Xuat();
	double Luong();
	string getLoai();
};
#endif // !_LAPTRINHVIEN