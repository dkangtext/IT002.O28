#include "LAPTRINHVIEN.h"

LAPTRINHVIEN::~LAPTRINHVIEN() {}

LAPTRINHVIEN::LAPTRINHVIEN(string manhanvien, string hoten, int tuoi, string sodienthoai, string email, double luongcoban, float sogiolamthem):NHANVIEN(manhanvien, hoten, tuoi, sodienthoai, email, luongcoban), soGioLamThem(sogiolamthem) {}

float LAPTRINHVIEN::getSoGioLamThem() const
{
	return soGioLamThem;
}

void LAPTRINHVIEN::setSoGioLamThem(float sglt)
{
	while (sglt < 0)
	{
		cout << "Nhap so gio lam them (sglt >= 0): " << endl;
		cin >> sglt;
	} 
	soGioLamThem = sglt;
}

void LAPTRINHVIEN::Nhap()
{
	NHANVIEN::Nhap();
	do
	{
		cout << "Nhap so gio lam them (sglt >= 0): " << endl;
		cin >> soGioLamThem;
		if (soGioLamThem < 0)
			cout << "Vui long nhap so hop le!";
	} while (soGioLamThem < 0);
}

void LAPTRINHVIEN::Xuat()
{
	NHANVIEN::Xuat();
	cout << "So gio lam them: " << soGioLamThem << endl;
}

double LAPTRINHVIEN::Luong()
{
	return (luongCoBan + soGioLamThem * 2000000);
}

string LAPTRINHVIEN::getLoai()
{
	return "LTV";
}