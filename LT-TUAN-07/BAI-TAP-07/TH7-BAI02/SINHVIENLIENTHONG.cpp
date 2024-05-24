#include "SINHVIENLIENTHONG.h"

SINHVIENLIENTHONG::~SINHVIENLIENTHONG() {}

SINHVIENLIENTHONG::SINHVIENLIENTHONG(string maso, string hoten, string khoa, double diemtrungbinh, int sobuoivang) : SINHVIEN(maso, hoten, khoa, diemtrungbinh), SoBuoiVang(sobuoivang) {}

int SINHVIENLIENTHONG::getSoBuoiVang() const
{
	return SoBuoiVang;
}

void SINHVIENLIENTHONG::setSoBuoiVang(int sobuoivang)
{
	while (sobuoivang < 0)
	{
		cout << "Nhap lai So buoi vang hop le: ";
		cin >> sobuoivang;
	}
	SoBuoiVang = sobuoivang;
}

void SINHVIENLIENTHONG::Nhap()
{
	SINHVIEN::Nhap();
	do
	{
		cout << "Nhap So buoi vang: ";
		cin >> SoBuoiVang;
		if (SoBuoiVang < 0)
			cout << "Vui long nhap lai So buoi vang hop le!";
	} while (SoBuoiVang < 0);
}

void SINHVIENLIENTHONG::Xuat()
{
	SINHVIEN::Xuat();
	cout << "So buoi vang: " << SoBuoiVang << endl;
}

long SINHVIENLIENTHONG::TinhHocBong()
{
	return ((getDiemTrungBinh() >= 9 && SoBuoiVang <= 3) ? 1500000 : ((getDiemTrungBinh() >= 8 && SoBuoiVang <= 3) ? 1200000 : ((getDiemTrungBinh() >= 7 && SoBuoiVang <= 3) ? 1000000 : 0)));
}

string SINHVIENLIENTHONG::getLoai()
{
	return "LT";
}