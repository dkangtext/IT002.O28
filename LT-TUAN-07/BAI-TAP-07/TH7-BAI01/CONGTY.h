#pragma once
#ifndef _CONGTY
#define _CONGTY
#include <iostream>
#include "NHANVIEN.h"
#include "NHANVIENBIENCHE.h"
#include "NHANVIENHOPDONG.h"

using namespace std;

class CONGTY
{
private:
	NHANVIEN** PDTNhanVien;
	int SoLuong;

public:
	~CONGTY();
	CONGTY();
	int GetSoLuong() const;
	void Nhap();
	void Xuat();
	NHANVIEN* Nhap1();
	void LietKeNhanVienCoHeSoLuongTu35TroLen();
	int DemNhanVienHopDongCoSoNgayCongLa26();
	long TinhTongTienLuongNhanVienPhongKeToan();
	double TinhTienLuongTrungBinhCuaNhanVienBienChe();
	bool KiemTraCongTyCoNhanVienHopDongKhongDiLamNgayNaoKhong();
	void TimCacNhanVienBienCheCoHeSoLuongCaoNhat();
	string DoiChuoiInHoa(string);
	string DoiChuoiInThuong(string);
	void SapXepDanhSachNhanVienTangDanTheoMaSo();
	void Them(NHANVIEN*, int);
	int Xoa(string);
	void TimKiemNhanVienTheoThongTinChung(string = "-100000", string = "-100000", string = "-100000", double = -100000, double = -100000, long = -100000, int = -100000, double = -100000);
};

#endif // !_CONGTY