#include "SINHVIENCHINHQUY.h"
#include "SINHVIEN.h"

SINHVIENCHINHQUY::~SINHVIENCHINHQUY() {}

SINHVIENCHINHQUY::SINHVIENCHINHQUY(string maso, string hoten, string khoa, double diemtrungbinh, int diemrenluyen) : SINHVIEN(maso, hoten, khoa, diemtrungbinh), DiemRenLuyen(diemrenluyen) {}

int SINHVIENCHINHQUY::getDiemRenLuyen() const
{
	return DiemRenLuyen;
}

void SINHVIENCHINHQUY::setDiemRenLuyen(int diemrenluyen)
{
	while (diemrenluyen < 0 || diemrenluyen > 100)
	{
		cout << "Nhap lai Diem ren luyen hop le: ";
		cin >> diemrenluyen;
	}
	DiemRenLuyen = diemrenluyen;
}

void SINHVIENCHINHQUY::Nhap()
{
	SINHVIEN::Nhap();
	do
	{
		cout << "Nhap Diem ren luyen: ";
		cin >> DiemRenLuyen;
		if (DiemRenLuyen < 0 || DiemRenLuyen > 100)
			cout << "Vui long nhap lai Diem ren luyen hop dong!" << endl;
	} while (DiemRenLuyen < 0 || DiemRenLuyen > 100);
}

void SINHVIENCHINHQUY::Xuat()
{
	SINHVIEN::Xuat();
	cout << "Diem ren luyen: " << DiemRenLuyen << endl;
}

long SINHVIENCHINHQUY::TinhHocBong()
{
	return ((getDiemTrungBinh() >= 9.5 && DiemRenLuyen >= 85) ? 1500000 : ((getDiemTrungBinh() >= 8.5 && DiemRenLuyen >= 85) ? 1200000 : ((getDiemTrungBinh() >= 7.5 && DiemRenLuyen >= 85) ? 1000000 : 0)));
}

string SINHVIENCHINHQUY::getLoai()
{
	return "CQ";
}