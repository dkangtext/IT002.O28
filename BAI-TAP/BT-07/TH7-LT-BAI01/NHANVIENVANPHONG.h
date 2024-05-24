#pragma once
#ifndef _NHANVIENVANPHONG
#define _NHANVIENVANPHONG
#include "NHANVIEN.h"

class NHANVIENVANPHONG:virtual public NHANVIEN
{
protected:
	long SoNgayLamViec;

public:
	~NHANVIENVANPHONG();
	NHANVIENVANPHONG();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};

#endif // !_NHANVIENVANPHONG