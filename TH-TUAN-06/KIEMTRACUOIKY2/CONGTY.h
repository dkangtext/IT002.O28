#pragma once
#ifndef _CONGTY
#define _CONGTY
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "NHANVIEN.h"
#include "LAPTRINHVIEN.h"
#include "KIEMCHUNGVIEN.h"

using namespace std;

class CONGTY: public NHANVIEN, KIEMCHUNGVIEN, LAPTRINHVIEN
{
private:
	vector<NHANVIEN*> danhSachNhanVien;

public:
	~CONGTY();
	void nhapDanhSachNhanVien();
	void xuatDanhSachNhanVien();
	void LietKeDanhSachLapTrinhVienCoLuongThapHonMucLuongTrungBinh();
	void KiemTraCoKiemChungVienNaoChiPhatHienDuocDuoi5LoiKhong();
	void CapNhatThongTinNhanVien(string maNhanVien);
	void XoaDanhSachNhanVien();
	void DocFile(string tenFile);
	void LuuFile(string tenFile);
	double TinhLuongTrungBinh();
};
#endif // !_CONGTY