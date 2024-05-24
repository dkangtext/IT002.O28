#include "HCN.h"

int HCN::Dem = 0;

HCN::~HCN()
{
	cout << "Da huy 1 hinh chu nhat => Con " << --Dem << " hinh chu nhat\n";
}

HCN::HCN() :A(0, 0), B(1, 0)
{
	Dem++;
}

/*
Hoặc:
	HCN::HCN()
	{
		A.SetXY(0,0);
		B.SetXY(0,1);
		Dem++;
	}
*/

HCN::HCN(const DIEM& A, const DIEM& B)
{
	if (!KiemTraHopLe())
		Nhap();
	Dem++;
}

/*
Hoặc:
	HCN::HCN(const DIEM& A, const DIEM& B)
	{
		this->A = A;
		this->B = B;
		if(!KiemTraHopLe())
			Nhap();
		Dem++;
	}
*/

HCN::HCN(double xA, double yA, double xB, double yB)
{
	if (!KiemTraHopLe())
		Nhap();
	Dem++;
}

/*
Hoặc:
	HCN::HCN(double xA, double yA, double xB, double yB)
	{
		A.SetXY(xA, yA);
		B.SetXY(xB, yB);
		if (!KiemTraHopLe())
			Nhap();
		Dem++
	}
*/

DIEM HCN::GetA() const
{
	return A;
}

DIEM HCN::GetB() const
{
	return B;
}

int HCN::GetDem()
{
	return Dem;
}

void HCN::SetA(const DIEM& A)
{
	this->A = A;
	while (!KiemTraHopLe())
	{
		cout << "Nhap toa do dinh A:\n";
		this->A.Nhap();
	}
}

void HCN::SetB(const DIEM& B)
{
	this->B = B;
	while (!KiemTraHopLe())
	{
		cout << "Nhap toa do dinh B:\n";
		this->B.Nhap();
	}
}

void HCN::SetAB(const DIEM& A, const DIEM& B)
{
	SetA(A);
	SetB(B);
}

void HCN::Nhap()
{
	do
	{
		cout << "Nhap toa do 2 diem cua hinh chu nhat:\n";
		A.Nhap();
		B.Nhap();
	} while (!KiemTraHopLe());
}

void HCN::Xuat() const
{
	cout << "Hinh chu nhat di qua 2 diem co toa do la: ";
	cout << "A("; A.Xuat(); cout << ") ";
	cout << "B("; B.Xuat(); cout << ") ";
	cout << endl;
	
	/* 
	cout << "Dien tich: " << TinhDienTich() << endl;
	cout << "Chu vi: " << TinhChuVi() << endl;
	*/
}

bool HCN::KiemTraHopLe() const
{
	double dai = abs(A.GetX() - B.GetX());
	double rong = abs(A.GetY() - B.GetY());

	return (dai > 0 && rong > 0);
}

double HCN::TinhChuVi() const
{
	double dai = abs(A.GetX() - B.GetX());
	double rong = abs(A.GetY() - B.GetY());

	return 2 * (dai + rong);
}
double HCN::TinhDienTich() const
{
	double dai = abs(A.GetX() - B.GetX());
	double rong = abs(A.GetY() - B.GetY());

	return dai * rong;
}

