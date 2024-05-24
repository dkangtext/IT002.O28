#pragma once
#ifndef _DIEM
#include <iostream>

using namespace std;

class DIEM
{
private:
	double x;
	double y;
	static int Dem;

public:
	~DIEM();
	DIEM(double = 0, double = 0);
	DIEM(const DIEM&);
	void SetX(double);
	void SetY(double);
	void SetXY(double, double);
	double GetX() const;
	double GetY() const;
	static int GetDem();
	void Nhap();
	void Xuat() const;
	void DiChuyen(double, double);
	bool KiemTraTrung(const DIEM&) const;
	double TinhKhoangCach(const DIEM&) const;
	DIEM TimDiemDoiXung() const;

	bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
	bool KiemTraTamGiacHopLe(double, double, double) const;
	double TinhChuViTamGiac(const DIEM&, const DIEM&) const;
	double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
	string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
};

#endif
