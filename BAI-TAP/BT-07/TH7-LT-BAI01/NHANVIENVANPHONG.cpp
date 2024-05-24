#include "NHANVIENVANPHONG.h"

NHANVIENVANPHONG::~NHANVIENVANPHONG() {}

NHANVIENVANPHONG::NHANVIENVANPHONG() {}

void NHANVIENVANPHONG::Nhap()
{
	NHANVIEN::Nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> SoNgayLamViec;
}

void NHANVIENVANPHONG::Xuat()
{
	NHANVIEN::Xuat();
	cout << "So ngay lam viec: " << SoNgayLamViec << endl;
}

long NHANVIENVANPHONG::Luong()
{
	return SoNgayLamViec * 100000;
}