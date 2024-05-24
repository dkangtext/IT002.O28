#pragma once
#ifndef _SINHVIENCHINHQUY
#define _SINHVIENCHINHQUY
#include "SINHVIEN.h"

class SINHVIENCHINHQUY:public SINHVIEN
{
protected:
	int DiemRenLuyen;

public:
	~SINHVIENCHINHQUY();
	SINHVIENCHINHQUY(string = "", string = "", string = "", double = 0, int = 0);
	int getDiemRenLuyen() const;
	void setDiemRenLuyen(int);
	void Nhap();
	void Xuat();
	long TinhHocBong();
	string getLoai();
};
#endif // !_SINHVIENCHINHQUY