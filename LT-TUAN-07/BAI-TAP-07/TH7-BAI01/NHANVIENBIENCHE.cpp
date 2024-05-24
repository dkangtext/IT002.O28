#include "NHANVIENBIENCHE.h"

NHANVIENBIENCHE::~NHANVIENBIENCHE() {}

NHANVIENBIENCHE::NHANVIENBIENCHE(string maso, string hoten, string phongban, double hsl, double hspccv) : NHANVIEN(maso, hoten, phongban), HeSoLuong(hsl), HeSoPhuCapChucVu(hspccv) {}

double NHANVIENBIENCHE::getHeSoLuong() const
{
	return HeSoLuong;
}

double NHANVIENBIENCHE::getHeSoPhuCapChucVu() const
{
	return HeSoPhuCapChucVu;
}

void NHANVIENBIENCHE::setHeSoLuong(double hsl)
{
	while (hsl < 0)
	{
		cout << "Nhap he so luong (hsl >= 0): ";
		cin >> hsl;
	}
	HeSoLuong = hsl;
}

void NHANVIENBIENCHE::setHeSoPhuCapChucVu(double hspccv)
{
	while (hspccv < 0)
	{
		cout << "Nhap he so phu cap chuc vu (hspccv >= 0): ";
		cin >> hspccv;
	}
	HeSoPhuCapChucVu = hspccv;
}

void NHANVIENBIENCHE::Nhap()
{
	NHANVIEN::Nhap();
	do
	{
		cout << "Nhap he so luong (hsl >= 0): " << endl;
		cin >> HeSoLuong;
		cout << "Nhap he so phu cap chuc vu (hspccv >= 0): " << endl;
		cin >> HeSoPhuCapChucVu;
		if (HeSoLuong < 0 || HeSoPhuCapChucVu < 0)
			cout << "Vui long nhap so hop le" << endl;
	} while (HeSoLuong < 0 || HeSoPhuCapChucVu < 0);
}

void NHANVIENBIENCHE::Xuat()
{
	NHANVIEN::Xuat();
	cout << "He so luong: " << HeSoLuong << endl;
	cout << "He so phu cap chuc vu: " << HeSoPhuCapChucVu << endl;
}

double NHANVIENBIENCHE::Luong()
{
	return (1 + HeSoLuong + HeSoPhuCapChucVu) * 1000;
}

string NHANVIENBIENCHE::getLoai()
{
	return "BC";
}