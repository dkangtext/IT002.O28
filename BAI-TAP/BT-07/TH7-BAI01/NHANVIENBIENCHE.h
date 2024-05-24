#pragma once
#ifndef _NHANVIENBIENCHE
#define _NHANVIENBIENCHE
#include "NHANVIEN.h"

class NHANVIENBIENCHE:public NHANVIEN
{
private:
	double HeSoLuong;
	double HeSoPhuCapChucVu;

public:
	~NHANVIENBIENCHE();
	NHANVIENBIENCHE(string = "", string = "", string = "", double = 0, double = 0);
	double getHeSoLuong() const;
	double getHeSoPhuCapChucVu() const;
	void setHeSoLuong(double);
	void setHeSoPhuCapChucVu(double);
	virtual void Nhap();
	virtual void Xuat();
	double Luong();
	string getLoai();
};
#endif // !_NHANVIENBIENCHE