#include "PTB1.h"

PTB1::PTB1()
{
	a = b = 0;
}

PTB1::PTB1(double b)
{
	a = 0;
	this->b = b;
}

PTB1::PTB1(double a, double b)
{
	this->a = a;
	this->b = b;
}

void PTB1::Nhap()
{
	cout << "Nhap 2 he so a va b: ";
	cin >> a >> b;
}

void PTB1::Giai()
{
	if (a == 0)
		if (b == 0)
			cout << "Phuong trinh vo so nghiem.";
		else
			cout << "Phuong trinh vo nghiem";
	else
		cout << "Phuong trinh co nghiem x = " << -b / a;
}

void PTB1::Xuat()
{
	cout << "Phuong trinh bac 1: " << a << "x + " << b << " = 0 => ";
	Giai();
	cout << endl;
}