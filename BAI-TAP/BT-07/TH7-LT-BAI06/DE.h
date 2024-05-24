#pragma once
#ifndef _DE
#define _DE
#include "GIASUC.h"

class DE :public GIASUC
{
public:
	~DE();
	DE();
	void Keu() override;
	int Sua() override;
	int SinhCon() override;
	int getLoai() override;
};

#endif // !_DE