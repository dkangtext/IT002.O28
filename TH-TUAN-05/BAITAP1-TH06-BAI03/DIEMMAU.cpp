#include "DIEMMAU.h"
int DIEMMAU::dem = 0;

DIEMMAU::~DIEMMAU()
{
	cout << "Da huy 1 diem mau => Con " << --dem << " diem mau\n";
}

DIEMMAU::DIEMMAU(double x, double y, int r, int g, int b) :DIEM(x, y), MAU(r, g, b)
{
	cout << "Da tao 1 mau => Co " << ++dem << " mau\n";
}

int DIEMMAU::GetDem()
{
	return dem;
}

void DIEMMAU::Nhap()
{
	DIEM::Nhap();
	MAU::Nhap();
}

void DIEMMAU::Xuat() const
{
	DIEM::Xuat();
	MAU::Xuat();
}

bool DIEMMAU::KiemTraTrung(const DIEMMAU& dm) const
{
	return DIEM::KiemTraTrung(dm) && MAU::KiemTraTrung(dm);
}

istream& operator>>(istream& is, DIEMMAU& dm)
{
	dm.Nhap();
	return is;
}

ostream& operator<<(ostream& os, const DIEMMAU& dm)
{
	dm.Xuat();
	return os;
}