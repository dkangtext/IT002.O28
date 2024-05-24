#include "DIEM.h"
#define epsilon 0.000000001

int DIEM::Dem = 0;

DIEM::~DIEM()
{
	cout << "Da huy 1 diem => Con " << --Dem << " diem\n";
}

DIEM::DIEM(double x, double y) :x(x), y(y)
{
	Dem++;
}

DIEM::DIEM(const DIEM& d) :x(d.x), y(d.y)
{
	Dem++;
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

double DIEM::GetX() const
{
	return x;
}

double DIEM::GetY() const
{
	return y;
}

int DIEM::GetDem()
{
	return Dem;
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
	return this->x == d.x && this->y == d.y;
}

double DIEM::TinhKhoangCach(const DIEM& d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

DIEM DIEM::TimDiemDoiXung() const
{
	return DIEM(-x == 0 ? x : -x, -y == 0 ? y : -y);
}

bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a);
}

bool DIEM::KiemTraTamGiacHopLe(double a, double b, double c) const
{
	return a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a);
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
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);

	string chuoiKetQua = "";

	if (!KiemTraTamGiacHopLe(d1, d2))
		chuoiKetQua = "Tam giac khong hop le !";
	else if (a == b || b == c || c == a)
		chuoiKetQua = "Tam giac deu";
	else if (a == b || b == c || c == a)
		if (abs(b * b + c * c - a * a) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(a * a + b * b - c * c) <= epsilon)
			chuoiKetQua = "Tam giac vuong can";
		else
			chuoiKetQua = "Tam giac can";
	else if (abs(b * b + c * c - a * a) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(a * a + b * b - c * c) <= epsilon)
		chuoiKetQua = "Tam giac vuong";
	else
		chuoiKetQua = "Tam giac thuong";
	return chuoiKetQua;
}