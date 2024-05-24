#include "DIEM3CMAU.h"

int DIEM3CMAU::dem = 0;

DIEM3CMAU::~DIEM3CMAU()
{
	cout << "Da huy 1 diem mau => Con " << --dem << " diem mau\n";
}

DIEM3CMAU::DIEM3CMAU(double x, double y, double z, int r, int g, int b): DIEM3C(x,y,z), MAU(r,g,b)
{
	cout << "Da tao 1 mau => Co " << ++dem << " mau\n";
}

int DIEM3CMAU::GetDem()
{
	return dem;
}

void DIEM3CMAU::Nhap()
{
	DIEM3C::Nhap();
	MAU::Nhap();
}

void DIEM3CMAU::Xuat() const
{
	DIEM3C::Xuat();
	MAU::Xuat();
}

bool DIEM3CMAU::KiemTraTrung(const DIEM3CMAU& d) const
{
	return DIEM3C::KiemTraTrung(d) && MAU::KiemTraTrung(d);
}

istream& operator>>(istream& is, DIEM3CMAU& d)
{
	d.Nhap();
	return is;
}

ostream& operator<<(ostream& os, DIEM3CMAU& d)
{
	d.Xuat();
	return os;
}