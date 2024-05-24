#include "FX.h"

FX::FX()
{
	a = 0;
	b = 0;
	c = 0;
}

FX::FX(double a)
{
	this-> a = a;
	b = 0;
	c = 0;
}

FX::FX(double a, double b)
{
	this->a = a;
	this->b = b;
	c = 0;
}

FX::FX(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

double FX::getA() const
{
	return a;
}

double FX::getB() const
{
	return b;
}

double FX::getC() const
{
	return c;
}

void FX::SetA(double a)
{
	this->a = a;
}

void FX::SetB(double b)
{
	this->b = b;
}

void FX::SetC(double c)
{
	this->c = c;
}

istream& operator >> (istream& is, FX& fx)
{
	cout << "Nhap he so a: ";
	is >> fx.a;
	cout << "Nhap he so b: ";
	is >> fx.b;
	cout << "Nhap he so c: ";
	is >> fx.c;
	return is;
}

ostream& operator << (ostream& os, FX& fx)
{
	os << "F(x) = " << fx.a << "x^2 + " << fx.b << "x + " << fx.c;
	return os;
}

double FX::GiaTriDaThuc(double x0)
{
	return a * x0 * x0 + b * x0 + c;
}

void FX::TinhNghiemDaThuc() const
{
	double delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		cout << "Phuong trinh F(x) da cho vo nghiem." << endl;
	}
	else if (delta == 0)
	{
		double Nghiem = -b / (2 * a);
		cout << "Phuong trinh F(x) co nghiem kep x1 = x2 = " << Nghiem << endl;
	}
	else
	{
		double Nghiem1 = (-b + sqrt(delta)) / (2 * a);
		double Nghiem2 = (-b - sqrt(delta)) / (2 * a);
		cout << "Phuong trinh F(x) co 2 nghiem phan biet. x1 = " << Nghiem1 << " va x2 = " << Nghiem2 << endl;
	}
}

FX FX::operator+(const FX& fx) const
{
	FX CongDaThuc;
	CongDaThuc.a = a + fx.a;
	CongDaThuc.b = b + fx.b;
	CongDaThuc.c = c + fx.c;
	return CongDaThuc;
}