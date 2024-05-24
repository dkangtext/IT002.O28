#pragma once
#ifndef _DIEM3C
#define _DIEM3C
#include "DIEM.h"


class DIEM3C:public DIEM
{
protected:
	double z;
	static int dem;

public:
	~DIEM3C();
	DIEM3C(double = 0, double = 0, double = 0);
	DIEM3C(const DIEM3C&);
	double GetZ() const;
	void SetZ(double);
	void SetXYZ(double, double, double);
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEM3C&) const;
	void DiChuyen(double, double, double);
	double TinhKhoangCach(const DIEM3C&) const;
	DIEM3C TimDoiXung() const;
	friend istream& operator>>(istream&, DIEM3C&);
	friend ostream& operator<<(ostream&, const DIEM3C&);
	double TinhChuViTamGiac(const DIEM3C&, const DIEM3C&) const;
	double TinhDienTichTamGiac(const DIEM3C&, const DIEM3C&) const;
};

#endif // !_DIEM3C