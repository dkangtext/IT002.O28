#include "DIEM.h"
#define epsilon 0.000000001
int DIEM::dem = 0;

DIEM::~DIEM()
{
	cout << "Da huy 1 diem 2C => Con " << --dem << " diem 2C\n";
}

DIEM::DIEM(double x, double y) :x(x), y(y)
{
	cout << "Da tao 1 diem 2C => Co " << ++dem << " diem 2C\n";
}

DIEM::DIEM(const DIEM& d) : x(d.x), y(d.y)
{
	cout << "Da tao 1 diem 2C => Co " << ++dem << " diem 2C\n";
}

double DIEM::GETX() const
{
	return x;
}

double DIEM::GETY() const
{
	return y;
}

int DIEM::GetDem()
{
	return dem;
}

void DIEM::SetX(double x)
{
	this->x = x;
}

void DIEM::SetY(double y)
{
	this->y = y;
}

void DIEM::SetXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void DIEM::Nhap()
{
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}

void DIEM::Xuat() const
{
	cout << x << ", " << y;
}

void DIEM::DiChuyen(double dx, double dy)
{
	x += dx;
	y += dy;
}

bool DIEM::KiemTraTrung(const DIEM& d) const
{
	return x == d.x && y == d.y;
}

double DIEM::TinhKhoangCach(const DIEM& d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

DIEM DIEM::TimDoiXung() const
{
	return DIEM(-x == 0 ? x : -x, -y == 0 ? y : -y);
}

bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b;
}

double DIEM::TinhChuViTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a + b + c;
}

double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	double p = (a + b + c) / 2;
	return  sqrt(p * (p - a) * (p - b) * (p - c));
}

string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	string chuoikq = "";
	if (!KiemTraTamGiacHopLe(d1, d2))
		chuoikq = "TG khong hop le";
	else if (a == b && b == c)
		chuoikq = "TG deu";
	else if (a == b || b == c || c == a)
		if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
			chuoikq = "TG vuong can";
		else
			chuoikq = "TG can";
	else if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
		chuoikq = "TG vuong";
	else
		chuoikq = "TG thuong";
	return chuoikq;
}

istream& operator>>(istream& is, DIEM& d)
{
	cout << "Nhap hoanh do: ";
	is >> d.x;
	cout << "Nhap tung do: ";
	is >> d.y;
	return is;
}

ostream& operator<<(ostream& os, const DIEM& d)
{
	os << d.x << ", " << d.y;
	return os;
}