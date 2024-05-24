#include "NHANVIEN.h"

NHANVIEN::~NHANVIEN() {}

NHANVIEN::NHANVIEN()
{
	MaSo="";
	HoTen="";
	PhongBan="";
}
NHANVIEN::NHANVIEN(string maso, string hoten, string phongban): MaSo(maso), HoTen(hoten), PhongBan(phongban) {}

string NHANVIEN::getMaSo() const
{
	return MaSo;
}

string NHANVIEN::getHoTen() const
{
	return HoTen;
}

string NHANVIEN::getPhongBan() const
{
	return PhongBan;
}

void NHANVIEN::setHoTen(string HoTen)
{
	this->HoTen = HoTen;
}

void NHANVIEN::setPhongBan(string PhongBan)
{
	this->PhongBan = PhongBan;
}

void NHANVIEN::Nhap()
{
	cin.ignore();
	cout << "Nhap ma so nhan vien: " << endl;
	getline(cin, MaSo);
	cout << "Nhap ho va ten nhan vien: " << endl;
	getline(cin, HoTen);
	cout << "Nhap phong ban: " << endl;
	getline(cin, PhongBan);
}

void NHANVIEN::Xuat()
{
	cout << "Ma so nhan vien: " << MaSo << endl;
	cout << "Ho ten nhan vien: " << HoTen << endl;
	cout << "Phong ban: " << PhongBan << endl;
	cout << "Loai: " << getLoai();
	cout << "Luong: " << Luong();
}

