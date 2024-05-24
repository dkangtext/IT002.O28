#include "NHANVIEN.h"

NHANVIEN::~NHANVIEN() {}

NHANVIEN::NHANVIEN(string manhanvien, string hoten, int tuoi, string sodienthoai, string email, double luongcoban) : maNhanVien(manhanvien), hoTen(hoten), Tuoi(tuoi), soDienThoai(sodienthoai), Email(email), luongCoBan(luongcoban) {}

string NHANVIEN::getMaNhanVien() const
{
	return maNhanVien;
}

string NHANVIEN::getHoTen() const
{
	return hoTen;
}

int NHANVIEN::getTuoi() const
{
	return Tuoi;
}

string NHANVIEN::getSoDienThoai() const
{
	return soDienThoai;
}

string NHANVIEN::getEmail() const
{
	return Email;
}

double NHANVIEN::getLuongCoBan() const
{
	return luongCoBan;
}

void NHANVIEN::setMaNhanVien(string maNhanVien)
{
	this->maNhanVien = maNhanVien;
}

void NHANVIEN::setHoTen(string hoTen)
{
	this->hoTen = hoTen;
}

void NHANVIEN::setTuoi(int Tuoi)
{
	this->Tuoi = Tuoi;
}

void NHANVIEN::setSoDienThoai(string soDienThoai)
{
	this->soDienThoai = soDienThoai;
}

void NHANVIEN::setEmail(string Email)
{
	this->Email = Email;
}

void NHANVIEN::setLuongCoBan(double luongCoBan)
{
	this->luongCoBan = luongCoBan;
}

void NHANVIEN::Nhap()
{
	cin.ignore();
	
	cout << "Nhap ma so nhan vien: " << endl;
	getline(cin, maNhanVien);

	cout << "Nhap ho va ten nhan vien: " << endl;
	getline(cin, hoTen);

	cout << "Nhap tuoi: " << endl;
	cin >> Tuoi;

	cout << "Nhap so dien thoai: " << endl;
	cin >> soDienThoai;

	cout << "Nhap email: " << endl;
	cin >> Email;

	cout << "Nhap muc luong co ban: " << endl;
	cin >> luongCoBan;
}

void NHANVIEN::Xuat()
{
	cout << "Ma so nhan vien: " << maNhanVien << endl;
	cout << "Ho va ten: " << hoTen << endl;
	cout << "Tuoi: " << Tuoi << endl;
	cout << "So dien thoai: " << soDienThoai << endl;
	cout << "Email: " << Email << endl;
	cout << "Luong co ban: " << luongCoBan << endl;
	cout << "Loai: " << getLoai() << endl;
	cout << "Luong: " << Luong() << endl;
}