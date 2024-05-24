#include "DIEM3C.h"
int DIEM3C::dem = 0;

DIEM3C::~DIEM3C()
{
	cout << "Da huy 1 diem 3C => Con " << --dem << " diem 3C\n";
}

DIEM3C::DIEM3C(double x, double y, double z) :DIEM(x, y), z(z)
{
	cout << "Da tao 1 diem 3C => Co " << ++dem << " diem 3C\n";
}

DIEM3C::DIEM3C(const DIEM3C& d3c) :DIEM(d3c.x, d3c.y), z(d3c.z)
{
	cout << "Da tao 1 diem 3C => Co " << ++dem << " diem 3C\n";
}

double DIEM3C::GetZ() const
{
	return z;
}

void DIEM3C::SetZ(double z)
{
	this->z = z;
}

void DIEM3C::SetXYZ(double x, double y, double z)
{
	SetXY(x, y);
	SetZ(z);
}

int DIEM3C::GetDem()
{
	return dem;
}

void DIEM3C::Nhap()
{
	DIEM::Nhap();
	cout << "Nhap cao do: ";
	cin >> z;
}

void DIEM3C::Xuat() const
{
	DIEM::Xuat();
	cout << ", " << z;
}

bool DIEM3C::KiemTraTrung(const DIEM3C& d) const
{
	return DIEM::KiemTraTrung(d) && z == d.z;
}

void DIEM3C::DiChuyen(double dx, double dy, double dz)
{
	DIEM::DiChuyen(dx, dy);
	z += dz;
}

double DIEM3C::TinhKhoangCach(const DIEM3C& d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2) + pow(z - d.z, 2));
}

DIEM3C DIEM3C::TimDoiXung() const
{
	return DIEM3C(-x == 0 ? x : -x, -y == 0 ? y : -y, -z == 0 ? z : -z);
}

istream& operator>>(istream& is, DIEM3C& d)
{
	d.Nhap();
	cout << "Nhap cao do:";
	is >> d.z;
	return is;
}

ostream& operator<<(ostream& os, const DIEM3C& d)
{
	d.Xuat();
	os << ", " << d.z;
	return os;
}

double DIEM3C::TinhChuViTamGiac(const DIEM3C& d1, const DIEM3C& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a + b + c;
}

double DIEM3C::TinhDienTichTamGiac(const DIEM3C& d1, const DIEM3C& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}