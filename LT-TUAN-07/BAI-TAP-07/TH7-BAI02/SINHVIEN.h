#pragma once
#ifndef _SINHVIEN
#define _SINHVIEN
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;

class SINHVIEN
{
protected:
	string MaSo;
	string HoTen;
	string Khoa;
	double DiemTrungBinh;

public:
	~SINHVIEN();
	SINHVIEN();
	SINHVIEN(string = "", string = "", string = "", double = 0);
	string getMaSo() const;
	string getHoTen() const;
	string getKhoa() const;
	double getDiemTrungBinh() const;
	void setHoTen(string);
	void setKhoa(string);
	void setDiemTrungBinh(double);
	virtual void Nhap();
	virtual void Xuat();
	virtual long TinhHocBong() = 0;
	virtual string getLoai() = 0;
};

#endif // !_SINHVIEN