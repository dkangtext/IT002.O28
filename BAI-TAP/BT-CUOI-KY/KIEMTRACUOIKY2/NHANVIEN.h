#pragma once
#ifndef _NHANVIEN
#define _NHANVIEN
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class NHANVIEN
{
protected:
	string maNhanVien;
	string hoTen;
	int Tuoi;
	string soDienThoai;
	string Email;
	double luongCoBan;

public:
	~NHANVIEN();
	NHANVIEN(string = "", string = "", int = 0, string = "", string = "", double = 0);
	string getMaNhanVien() const;
	string getHoTen() const;
	int getTuoi() const;
	string getSoDienThoai() const;
	string getEmail() const;
	double getLuongCoBan() const;
	void setMaNhanVien(string);
	void setHoTen(string);
	void setTuoi(int);
	void setSoDienThoai(string);
	void setEmail(string);
	void setLuongCoBan(double);
	virtual double Luong() = 0;
	virtual string getLoai() = 0;
	virtual void Nhap();
	virtual void Xuat();
};

#endif // !_NHANVIEN