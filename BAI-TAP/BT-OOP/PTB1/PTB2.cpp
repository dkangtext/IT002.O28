#include "PTB2.h"
#include "PTB1.h"

PTB2::PTB2()
{
	a = b = c = 0;
}

PTB2::PTB2(double c)
{
	a = b = 0;
	this->c = c;
}

PTB2::PTB2(double b, double c)
{
	a = 0;
	this->b = b;
	this->c = c;
}

PTB2::PTB2(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void PTB2::Nhap()
{
	cout << "Nhap 3 he so a, b, c: ";
	cin >> a >> b >> c;
}

void PTB2::Giai()
{
	if (a == 0)
	{
		PTB1 ptb1(b, c);
		ptb1.Xuat();
	}
	else
	{
		double delta = b * b - 4 * a * c;
		if (delta < 0)
			cout << "Phuong trinh vo nghiem vi delta < 0";
		else if (delta == 0)
			cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a);
		else
			cout << "Phuong trinh co hai nghiem phan biet x1 = " << (-b - sqrt(delta)) / (2 * a) << " x2 = " << (-b + sqrt(delta)) / (2 * a);
	}
}

void PTB2::Xuat()
{
	cout << "Phuong trinh bac 2: " << a << "x^2 + " << b << "x + " << c << " = 0 => ";
	Giai();
	cout << endl;
}