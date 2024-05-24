#include "NHANVIENSANXUAT.h"

NHANVIENSANXUAT::~NHANVIENSANXUAT() {}

NHANVIENSANXUAT::NHANVIENSANXUAT() {}

void NHANVIENSANXUAT::Nhap()
{
	NHANVIEN::Nhap();
	cout << "Nhap muc luong co ban: ";
	cin >> LuongCoBan;
	cout << "Nhap so san pham: ";
	cin >> SoSanPham;
}

void NHANVIENSANXUAT::Xuat()
{
	NHANVIEN::Xuat();
	cout << "Muc luong co ban: " << LuongCoBan << endl;
	cout << "So san pham lam duoc: " << SoSanPham << endl;
}

long NHANVIENSANXUAT::Luong()
{
	return LuongCoBan + (SoSanPham * 5000);
}