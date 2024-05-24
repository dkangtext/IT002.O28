#pragma once
#ifndef _HCN
#include "DIEM.h"

class HCN
{
private:
	DIEM A, B;
	static int Dem;

public:
	~HCN();
	HCN();
	HCN(const DIEM&, const DIEM&);
	HCN(double, double, double, double);
	DIEM GetA() const;
	DIEM GetB() const;
	static int GetDem();
	void SetA(const DIEM&);
	void SetB(const DIEM&);
	void SetAB(const DIEM&, const DIEM&);
	void Nhap();
	void Xuat() const;
	bool KiemTraHopLe() const;
	double TinhChuVi() const;
	double TinhDienTich() const;
};

#endif;
