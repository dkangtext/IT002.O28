#pragma once
#ifndef _SINHVIENLIENTHONG
#define _SINHVIENLIENTHONG
#include "SINHVIEN.h"

class SINHVIENLIENTHONG:public SINHVIEN
{
protected:
	int SoBuoiVang;

public:
	~SINHVIENLIENTHONG();
	SINHVIENLIENTHONG(string = "", string = "", string = "", double = 0, int = 0);
	int getSoBuoiVang() const;
	void setSoBuoiVang(int);
	void Nhap();
	void Xuat();
	long TinhHocBong();
	string getLoai();
};

#endif // !_SINHVIENLIENTHONG