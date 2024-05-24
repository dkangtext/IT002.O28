#pragma once
#ifndef _BO
#define _BO

#include "GIASUC.h"

class BO : public GIASUC
{
public:
	~BO();
	BO();
	void Keu() override;
	int Sua() override;
	int SinhCon() override;
	int getLoai() override;
};

#endif // !_BO