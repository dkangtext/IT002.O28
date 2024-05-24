#include "BO.h"

BO::~BO() {}

BO::BO()
{
	Loai = 1;
}

void BO::Keu()
{
	cout << "Um Bo" << endl;
}

int BO::Sua()
{
	return rand() % 20;
}

int BO::SinhCon()
{
	return 1 + rand() % 8;
}

int BO::getLoai()
{
	return Loai;
}