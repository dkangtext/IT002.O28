#include "NHANVIENHOPDONG.h"

NHANVIENHOPDONG::~NHANVIENHOPDONG() {}

NHANVIENHOPDONG::NHANVIENHOPDONG(string maso, string hoten, string phongban, long tiencong, int songaycong, double hesovuotgio) : NHANVIEN(maso, hoten, phongban), SoNgayCong(songaycong), HeSoVuotGio(hesovuotgio) {}

long NHANVIENHOPDONG::getTienCong() const
{
	return TienCong;
}

int NHANVIENHOPDONG::getSoNgayCong() const
{
	return SoNgayCong;
}

double NHANVIENHOPDONG::getHeSoVuotGio() const
{
	return HeSoVuotGio;
}

void NHANVIENHOPDONG::setTienCong(long tc)
{
	while (tc < 0)
	{
		cout << "Nhap tien cong (tc >= 0): ";
		cin >> tc;
	}
	TienCong = tc;
}

void NHANVIENHOPDONG::setSoNgayCong(int snc)
{
	while (snc < 0)
	{
		cout << "Nhap so ngay cong (snc >= 0): ";
		cin >> snc;
	}
	SoNgayCong = snc;
}

void NHANVIENHOPDONG::setHeSoVuotGio(double hsvg)
{
	while (hsvg < 0)
	{
		cout << "Nhap he so vuot gio (hsvg >= 0): ";
		cin >> hsvg;
	}
	HeSoVuotGio = hsvg;
}

void NHANVIENHOPDONG::Nhap()
{
	NHANVIEN::Nhap();
	do
	{
		cout << "Nhap tien cong: " << endl;
		cin >> TienCong;
		cout << "Nhap so ngay cong: " << endl;
		cin >> SoNgayCong;
		cout << "Nhap he so vuot gio: " << endl;
		cin >> HeSoVuotGio;
		if (TienCong < 0 || HeSoVuotGio < 0 || SoNgayCong < 0)
			cout << "Vui long nhap so hop le!" << endl;
	} while (TienCong < 0 || HeSoVuotGio < 0 || SoNgayCong < 0);
}

void NHANVIENHOPDONG::Xuat()
{
	NHANVIEN::Xuat();
	cout << "Tien cong: " << TienCong << endl;
	cout << "So ngay cong: " << SoNgayCong << endl;
	cout << "He so vuot gio: " << HeSoVuotGio << endl;
}

double NHANVIENHOPDONG::Luong()
{
	return (TienCong * SoNgayCong * (1 + HeSoVuotGio));
}
string NHANVIENHOPDONG::getLoai()
{
	return "HD";
}