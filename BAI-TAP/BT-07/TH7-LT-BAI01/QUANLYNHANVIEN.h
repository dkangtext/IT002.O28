#pragma once
#ifndef _QUANLYNHANVIEN
#define _QUANLYNHANVIEN
#include "NHANVIEN.h"

class QUANLYNHANVIEN
{
protected:
	NHANVIEN** DuLieu;
	long SoLuongNhanVien;
	long TongSoLuongPhaiTra;
	long LuongCaoNhat, Max;
	long LuongThapNhat, Min;

public:
	~QUANLYNHANVIEN();
	QUANLYNHANVIEN();
	void Nhap();
	void Xuat();
};

#endif // !_QUANLYNHANVIEN