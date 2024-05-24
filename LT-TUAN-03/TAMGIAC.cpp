#include "TAMGIAC.h"

int TAMGIAC::Dem = 0;

TAMGIAC::~TAMGIAC()
{
	cout << "Da huy 1 tam giac => Con " << --Dem << " tam giac\n";
}

TAMGIAC::TAMGIAC() :A(0, 0), B(1, 0), C(0, 1)
{
	Dem++;
}

/* 
Hoặc:
	TAMGIAC::TAMGIAC()
	{
		A.SetXY(0,0);
		B.SetXY(0,1);
		C.SetXY(1,0);
		Dem++;
	}
*/

TAMGIAC::TAMGIAC(const DIEM& A, const DIEM& B, const DIEM& C)
{
	if (!KiemTraHopLe())
		Nhap();
	Dem++;
}

/* 
Hoặc:
	TAMGIAC::TAMGIAC(const DIEM& A, const DIEM& B, const DIEM&C)
	{
		this->A = A;
		this->B = B;
		this->C = C;
		if(!KiemTraHopLe())
			Nhap();
		Dem++;
	}
*/

TAMGIAC::TAMGIAC(double xA, double yA, double xB, double yB, double xC, double yC)
{
	if (!KiemTraHopLe())
		Nhap();
	Dem++;
}

/* 
Hoặc:
	TAMGIAC::TAMGIAC(double xA, double yA, double xB, double yB, double xC, double yC)
	{
		A.SetXY(xA, yA);
		B.SetXY(xB, yB);
		C.SetXY(xC, yC);
		if (!KiemTraHopLe())
			Nhap();
		Dem++
	}
*/

DIEM TAMGIAC::GetA() const
{
	return A;
}

DIEM TAMGIAC::GetB() const
{
	return B;
}

DIEM TAMGIAC::GetC() const
{
	return C;
}

int TAMGIAC::GetDem()
{
	return Dem;
}

void TAMGIAC::SetA(const DIEM& A)
{
	this->A = A;
	while (!KiemTraHopLe())
	{
		cout << "Nhap toa do dinh A:\n";
		this->A.Nhap();
	}
}

void TAMGIAC::SetB(const DIEM& B)
{
	this->B = B;
	while (!KiemTraHopLe())
	{
		cout << "Nhap toa do dinh B:\n";
		this->B.Nhap();
	}
}

void TAMGIAC::SetC(const DIEM& C)
{
	this->C = C;
	while (!KiemTraHopLe())
	{
		cout << "Nhap toa do dinh C:\n";
		this->C.Nhap();
	}
}

void TAMGIAC::SetABC(const DIEM& A, const DIEM& B, const DIEM& C)
{
	SetA(A);
	SetB(B);
	SetC(C);
}

void TAMGIAC::Nhap()
{
	do
	{
		cout << "Nhap toa do 3 dinh cua tam giac:\n";
		A.Nhap();
		B.Nhap();
		C.Nhap();
	} while (!KiemTraHopLe());
}

void TAMGIAC::Xuat() const
{
	cout << "Tam giac di qua 3 diem ";
	cout << "A("; A.Xuat(); cout << ") ";
	cout << "B("; B.Xuat(); cout << ") ";
	cout << "C("; C.Xuat(); cout << ") ";
	cout << endl;
	
	/*
	cout << "Phan loai: " << PhanLoai() << endl;
	cout << "Dien tich: " << TinhDienTich() << endl;
	cout << "Chu vi: " << TinhChuVi() << endl;
	*/
}

bool TAMGIAC::KiemTraHopLe() const
{
	return A.KiemTraTamGiacHopLe(B, C);
}

string TAMGIAC::PhanLoai() const
{
	return A.PhanLoaiTamGiac(B, C);
}

double TAMGIAC::TinhChuVi() const
{
	return A.TinhChuViTamGiac(B, C);
}
double TAMGIAC::TinhDienTich() const
{
	return A.TinhDienTichTamGiac(B, C);
}

