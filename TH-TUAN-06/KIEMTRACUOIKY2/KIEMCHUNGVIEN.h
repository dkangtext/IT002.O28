#pragma once
#ifndef _KIEMCHUNGVIEN
#define _KIEMCHUNGVIEN
#include <iostream>
#include "NHANVIEN.h"

class KIEMCHUNGVIEN :public NHANVIEN
{
private:
	float soLoi;

public:
	~KIEMCHUNGVIEN();
	KIEMCHUNGVIEN(string = "", string = "", int = 0, string = "", string = "", double = 0, float = 0);
	float getSoLoi() const;
	void setSoLoi(float);
	virtual void Nhap();
	virtual void Xuat();
	double Luong();
	string getLoai();
};

#endif // !_KIEMCHUNGVIEN