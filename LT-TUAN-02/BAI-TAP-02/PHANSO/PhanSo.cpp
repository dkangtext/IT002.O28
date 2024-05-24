#include "PhanSo.h"

#include <iostream>
using namespace std;

PhanSo::PhanSo()
{
	tuSo = 0;
	mauSo = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
	tuSo = tu;
	mauSo = mau;
}

void PhanSo::Nhap()
{
	cout << "Nhap tu so: ";
	cin >> tuSo;

	do
	{
		cout << "Nhap mau so (khac 0): ";
		cin >> mauSo;
		if (mauSo != 0)
			break;
		else
			cout << "Mau so khong hop le ! \n";
	} while (mauSo == 0);
}

void PhanSo::Xuat()
{
	int USCLN = 1;
	int a = tuSo;
	int b = mauSo;

	a = abs(a);
	b = abs(b);

	if (a == 0 && b == 0)
		USCLN = 1;
	else if (a == 0 || b == 0)
		USCLN = a + b;
	else
	{
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		USCLN = a;
	}

	tuSo = tuSo / USCLN;
	mauSo = mauSo / USCLN;

	if (mauSo < -1)
		cout << -tuSo << "/" << -mauSo;
	else if (mauSo == -1)
		cout << -tuSo;
	else if (mauSo == 0)
		cout << "Khong chia cho so 0";
	else if (mauSo == 1)
		cout << tuSo;
	else
		cout << tuSo << "/" << mauSo;
}

PhanSo PhanSo::Cong(PhanSo ps)
{
	PhanSo Tong;
	Tong.tuSo = tuSo * ps.mauSo + ps.tuSo * mauSo;
	Tong.mauSo = mauSo * ps.mauSo;
	return Tong;
}

PhanSo PhanSo::Tru(PhanSo ps)
{
	PhanSo Hieu;
	Hieu.tuSo = tuSo * ps.mauSo - ps.tuSo * mauSo;
	Hieu.mauSo = mauSo * ps.mauSo;
	return Hieu;
}

PhanSo PhanSo::Nhan(PhanSo ps)
{
	PhanSo Tich;
	Tich.tuSo = tuSo * ps.tuSo;
	Tich.mauSo = mauSo * ps.mauSo;
	return Tich;
}

PhanSo PhanSo::Chia(PhanSo ps)
{
	PhanSo Thuong;
	Thuong.tuSo = tuSo * ps.mauSo;
	Thuong.mauSo = mauSo * ps.tuSo;
	return Thuong;
}