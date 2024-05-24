#include "DIEM.h"
#include <iostream>
using namespace std;

DIEM::DIEM(double x, double y)
{
	this->x = x;
	this->y = y;
}

DIEM::~DIEM() {}

double DIEM::GetX() const
{
	return x;
}

double DIEM::GetY() const
{
	return y;
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
	x = x + dx;
	y = y + dy;
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
	return DIEM(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}

bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const
{
	double a = TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a > 0 && b > 0 && c > 0 && (a + b > c) && (b + c > a) && (a + c > b);
}

double DIEM::TinhChuViTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a + b + c;
}

double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	string chuoiKetQua = "";
	if (!KiemTraTamGiacHopLe(d1, d2))
		chuoiKetQua = "Tam giac khong hop le !";
	else if (a == b || b == c || c == a)
		chuoiKetQua = "Tam giac deu";
	else if (a == b || b == c || c == a)
		if (b * b + c * c - a * a <= epsilon || a * a + c * c - b * b <= epsilon || a * a + b * b - c * c <= epsilon)
			chuoiKetQua = "Tam giac vuong can";
		else
			chuoiKetQua = "Tam giac can";
	else if (b * b + c * c - a * a <= epsilon || a * a + c * c - b * b <= epsilon || a * a + b * b - c * c <= epsilon)
		chuoiKetQua = "Tam giac vuong";
	else
		chuoiKetQua = "Tam giac thuong";
	return chuoiKetQua;
}