#include "SoPhuc.h"
#include <iostream>

using namespace std;

SoPhuc::~SoPhuc() {}

SoPhuc::SoPhuc()
{
	phanThuc = 0;
	phanAo = 0;
}

SoPhuc::SoPhuc(float t, float a)
{
	phanThuc = t;
	phanAo = a;
}

void SoPhuc::Nhap()
{
	cout << "Nhap phan thuc: ";
	cin >> phanThuc;
	cout << "Nhap phan ao: ";
	cin >> phanAo;
}

void SoPhuc::Xuat()
{
	cout << "(" << phanThuc;
	if (phanAo >= 0)
		cout << " + " << phanAo << "i)";
	else
		cout << phanAo << "i)";
}

double SoPhuc::Module() const
{
	double mod = sqrt(phanThuc * phanThuc + phanAo * phanAo);
	cout << mod;
	return mod;
}

void SoPhuc::Cong(SoPhuc sp)
{
	phanThuc = phanThuc + sp.phanThuc;
	phanAo = phanAo + sp.phanAo;
}

void SoPhuc::Tru(SoPhuc sp)
{
	phanThuc = phanThuc - sp.phanThuc;
	phanAo = phanAo - sp.phanAo;
}

void SoPhuc::Nhan(SoPhuc sp)
{
	SoPhuc Tich;
	Tich.phanThuc = phanThuc * sp.phanThuc - phanAo * sp.phanAo;
	Tich.phanAo = phanThuc * sp.phanAo + phanAo * sp.phanAo;
	*this = Tich;
}

void SoPhuc::Chia(SoPhuc sp)
{
	SoPhuc Thuong;
	Thuong.phanThuc = (phanThuc * sp.phanThuc + phanAo * sp.phanAo) / (sp.phanThuc * sp.phanThuc + sp.phanAo * sp.phanAo);
	Thuong.phanAo = (phanAo * sp.phanThuc - phanThuc * sp.phanAo) / (sp.phanThuc * sp.phanThuc + sp.phanAo * sp.phanAo);
	*this = Thuong;
}
