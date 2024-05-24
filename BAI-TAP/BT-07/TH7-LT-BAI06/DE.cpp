#include "DE.h"

DE::~DE() {}

DE::DE()
{
	Loai = 3;
}

void DE::Keu()
{
	cout << "Hee Hee" << endl;
}

int DE::Sua()
{
	return rand() % 10;
}

int DE::SinhCon()
{
	return 1 + rand() % 8;
}

int DE::getLoai()
{
	return Loai;
}