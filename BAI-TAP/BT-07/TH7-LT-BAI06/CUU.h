#pragma once
#ifndef _CUU
#define _CUU
#include "GIASUC.h"

class CUU :public GIASUC
{
public:
	~CUU();
	CUU();
	void Keu() override;
	int Sua() override;
	int SinhCon() override;
	int getLoai() override;
};

#endif // !_CUU