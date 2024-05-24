#pragma once
#ifndef _TRUONGDAIHOC
#define _TRUONGDAIHOC
#include "SINHVIEN.h"

class TRUONGDAIHOC
{
private:
	SINHVIEN** PDTSinhVien;
	int SoLuong;

public:
	~TRUONGDAIHOC();
	TRUONGDAIHOC();
	int getSoLuong() const;
	void Nhap();
	void Xuat();
	SINHVIEN* Nhap1();
	void LietKeCacSinhVienChinhQuyCoDiemRenLuyenLa100();
	int DemSoLuongSinhVienLienThongKhongNghiBuoiNao();
	long TinhTongHocBongCapChoCacSinhVien();
	double TinhDiemTrungBinhCuaCacSinhVienChinhQuyDuocCapHocBong();
	bool KiemTraTruongCoSinhVienLienThongCoDiemTrungBinhTu9TroLenVaKhongNghiBuoiNaoKhong();
	void TimCacSinhVienChinhQuyCoDiemTrungBinhCaoNhat();
	string DoiChuoiInHoa(string);
	string DoiChuoiInThuong(string);
	void SapXepSinhVienTangDanTheoMaSo();
	void Them(SINHVIEN*, int);
	int Xoa(string);
	void TimKiemSinhVienTheoThongTinChung(string = "-100000", string = "-100000", string = "-100000", double = -100000, int = -100000, int = -100000);
};

#endif // !_TRUONGDAIHOC