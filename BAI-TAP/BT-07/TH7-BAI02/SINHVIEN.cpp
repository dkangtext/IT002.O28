#include "SINHVIEN.h"

SINHVIEN::~SINHVIEN() {}
SINHVIEN::SINHVIEN()
{
	MaSo = "";
	HoTen = "";
	Khoa = "";
	DiemTrungBinh = 0;
}
SINHVIEN::SINHVIEN(string maso, string hoten, string khoa, double diemtrungbinh) : MaSo(maso), HoTen(hoten), Khoa(khoa), DiemTrungBinh(diemtrungbinh) {}

string SINHVIEN::getMaSo() const
{
	return MaSo;
}

string SINHVIEN::getHoTen() const
{
	return HoTen;
}

string SINHVIEN::getKhoa() const
{
	return Khoa;
}

double SINHVIEN::getDiemTrungBinh() const
{
	return DiemTrungBinh;
}

void SINHVIEN::setHoTen(string hoten)
{
	this->HoTen = hoten;
}

void SINHVIEN::setKhoa(string khoa)
{
	this->Khoa = khoa;
}

void SINHVIEN::setDiemTrungBinh(double diemtrungbinh)
{
	while (diemtrungbinh < 0 || diemtrungbinh > 10)
	{
		cout << "Nhap lai Diem Trung binh hop le: ";
		cin >> diemtrungbinh;
	}
	this->DiemTrungBinh = diemtrungbinh;
}

void SINHVIEN::Nhap()
{
	cin.ignore();
	cout << "Nhap ma so sinh vien: " << endl;
	getline(cin, MaSo);
	cout << "Nhap ho va ten sinh vien: " << endl;
	getline(cin, HoTen);
	cout << "Nhap khoa: " << endl;
	getline(cin, Khoa);
	do
	{
		cout << "Nhap Diem Trung binh: ";
		cin >> DiemTrungBinh;
		if (DiemTrungBinh < 0 || DiemTrungBinh > 10)
			cout << "Vui long nhap Diem Trung binh hop le!" << endl;
	} while (DiemTrungBinh < 0 || DiemTrungBinh > 0);
}

void SINHVIEN::Xuat()
{
	cout << "Ma so sinh vien: " << MaSo << endl;
	cout << "Ho va ten sinh vien: " << HoTen << endl;
	cout << "Khoa: " << Khoa << endl;
	cout << "Diem Trung binh: " << DiemTrungBinh << endl;
	cout << "Xep loai: " << getLoai();
	cout << "Hoc bong: " << TinhHocBong();
}