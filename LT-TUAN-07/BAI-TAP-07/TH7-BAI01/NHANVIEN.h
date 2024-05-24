#pragma once
#ifndef _NHANVIEN
#define _NHANVIEN
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

class NHANVIEN
{
private:
	string MaSo;
	string HoTen;
	string PhongBan;

public:
	~NHANVIEN();
	NHANVIEN();
	NHANVIEN(string = "", string = "", string = "");
	string getMaSo() const;
	string getHoTen() const;
	string getPhongBan() const;
	void setHoTen(string);
	void setPhongBan(string);
	virtual void Nhap();
	virtual void Xuat();
	virtual double Luong() = 0;
	virtual string getLoai() = 0;
};
#endif // !_NHANVIEN