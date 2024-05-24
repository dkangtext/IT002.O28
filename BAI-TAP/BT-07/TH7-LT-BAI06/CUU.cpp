#include "CUU.h"

CUU::~CUU() {}

CUU::CUU()
{
	Loai = 2;
}

void CUU::Keu()
{
	cout << "Be be" << endl;
}

int CUU::Sua()
{
	return rand() % 5;
}

int CUU::SinhCon()
{
	return 1 + rand() % 8;
}

int CUU::getLoai()
{
	return Loai;
}