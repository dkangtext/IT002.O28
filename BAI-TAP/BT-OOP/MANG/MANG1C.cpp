#include "MANG1C.h"

MANG1C::MANG1C()
{
	n = 0;
	a = NULL;
}

MANG1C::MANG1C(int n)
{
	while (n < 0)
	{
		cout << "Nhap n > 0: ";
		cin >> n;
	} 
	this->n = n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = 0; // a[i]
	}
}

MANG1C::MANG1C(int n, int m)
{
	while (n < 0)
	{
		cout << "Nhap n > 0: ";
		cin >> n;
	}
	this->n = n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		*(a + i) = m; // a[i] = m;
	}
}

MANG1C::MANG1C(int = 0, int = 0)
{

}

MANG1C::~MANG1C()
{
	n = 0;

}

int* MANG1C::GetA()
{

}

int MANG1C::GetN()
{

}

void MANG1C::Nhap()
{

}

void MANG1C::Xuat()
{

}

istream& operator>>(istream& is, MANG1C& m)
{

}

ostream& operator<<(ostream& os, const MANG1C& m)
{

}