#pragma once
#include <iostream>
using namespace std;
#ifndef _DIEM

class DIEM
{
protected:
	double x, y;
	static int dem;

public:
	~DIEM();
	DIEM(double = 0, double = 0);
	DIEM(const DIEM&);
	double GETX() const;
	double GETY() const;
	static int GetDem();
	void SetX(double);
	void SetY(double);
	void SetXY(double, double);
	void Nhap();
	void Xuat() const;
	void DiChuyen(double, double);
	bool KiemTraTrung(const DIEM&) const;
	double TinhKhoangCach(const DIEM&) const;
	DIEM TimDoiXung() const;
	bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
	double TinhChuViTamGiac(const DIEM&, const DIEM&) const;
	double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
	string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
	friend istream& operator>>(istream&, DIEM&);
	friend ostream& operator<<(ostream&, const DIEM&);
};

#endif // !_DIEM
