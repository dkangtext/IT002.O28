#pragma once
#ifndef _NHANVIENSANXUAT
#define _NHANVIENSANXUAT
#include "NHANVIEN.h"

class NHANVIENSANXUAT: virtual public NHANVIEN
{
protected:
	long LuongCoBan, SoSanPham;

public:
	~NHANVIENSANXUAT();
	NHANVIENSANXUAT();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};
#endif // !_NHANVIENSANXUAT