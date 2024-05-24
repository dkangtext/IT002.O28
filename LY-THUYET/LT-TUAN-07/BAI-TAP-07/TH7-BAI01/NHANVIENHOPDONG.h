#pragma once
#ifndef _NHANVIENHOPDONG
#define _NHANVIENHOPDONG
#include "NHANVIEN.h"

class NHANVIENHOPDONG: public NHANVIEN
{
private:
	long TienCong;
	int SoNgayCong;
	double HeSoVuotGio;

public:
	~NHANVIENHOPDONG();
	NHANVIENHOPDONG(string = "", string = "", string = "", long = 0, int = 0, double = 0);
	long getTienCong() const;
	int getSoNgayCong() const;
	double getHeSoVuotGio() const;
	void setTienCong(long);
	void setSoNgayCong(int);
	void setHeSoVuotGio(double);
	virtual void Nhap();
	virtual void Xuat();
	double Luong();
	string getLoai();
};

#endif // !_NHANVIENHOPDONG