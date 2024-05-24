#include "KIEMCHUNGVIEN.h"

KIEMCHUNGVIEN::~KIEMCHUNGVIEN() {}

KIEMCHUNGVIEN::KIEMCHUNGVIEN(string manhanvien, string hoten, int tuoi, string sodienthoai, string email, double luongcoban, float soloi) :NHANVIEN(manhanvien, hoten, tuoi, sodienthoai, email, luongcoban), soLoi(soloi) {}

float KIEMCHUNGVIEN::getSoLoi() const
{
	return soLoi;
}

void KIEMCHUNGVIEN::setSoLoi(float soloi)
{
	while (soloi < 0)
	{
		cout << "Nhap so loi (soloi >= 0): " << endl;
		cin >> soloi;
	}
	soLoi = soloi;
}

void KIEMCHUNGVIEN::Nhap()
{
	NHANVIEN::Nhap();
	do
	{
		cout << "Nhap so loi (soloi >= 0): " << endl;
		cin >> soLoi;
		if (soLoi < 0)
			cout << "Vui long nhap so hop le!";
	} while (soLoi < 0);
}

void KIEMCHUNGVIEN::Xuat()
{
	NHANVIEN::Xuat();
	cout << "So loi phat hien duoc: " << soLoi << endl;
}
double KIEMCHUNGVIEN::Luong()
{
	return (luongCoBan + soLoi * 50000);
}

string KIEMCHUNGVIEN::getLoai()
{
	return "KCV";
}