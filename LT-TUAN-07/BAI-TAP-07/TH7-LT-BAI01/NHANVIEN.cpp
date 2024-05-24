#include "NHANVIEN.h"

NHANVIEN::~NHANVIEN() {}

NHANVIEN::NHANVIEN() {}

void NHANVIEN::Nhap()
{
	cout << "Nhap Ho va ten: ";
	cin >> HoTen;
	cout << "Nhap Ngay sinh: ";
	cin >> Ngay;
	cout << "Nhap thang sinh: ";
	cin >> Thang;
	cout << "Nhap nam sinh: ";
	cin >> Nam;
}

void NHANVIEN::Xuat()
{
	cout << "Ho va ten Nhan vien: " << HoTen << endl;
	cout << "Ngay thang nam sinh: " << Ngay << "/" << Thang << "/" << Nam << endl;
}

long NHANVIEN::Luong()
{
	return 0;
}
