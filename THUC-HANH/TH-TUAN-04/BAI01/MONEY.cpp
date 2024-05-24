#include "MONEY.h"

MONEY::MONEY()
{
	dollar = 0;
	cent = 0;
}

MONEY::MONEY(int c)
{
	dollar = 0;
	cent = c;
}

MONEY::MONEY(int d, int c)
{
	dollar = d;
	cent = c;
}

MONEY::MONEY(const MONEY& m)
{
	dollar = m.dollar;
	cent = m.cent;
}

MONEY::~MONEY()
{
	return;
}

int MONEY::GetDollar() const
{
	return dollar;
}

int MONEY::GetCent() const
{
	return cent;
}

void MONEY::SetDollar(int dollar)
{
	this->dollar = dollar;
}

void MONEY::SetCent(int cent)
{
	this->cent = cent;
}

void MONEY::SetMoney(int dollar, int cent)
{
	dollar = dollar;
	cent = cent;
}

istream& operator >> (istream& is, MONEY& m)
{
	do
	{
		cout << "Nhap dollar: ";
		is >> m.dollar;
	} while (m.dollar < 0);

	do
	{
		cout << "Nhap cent: ";
		is >> m.cent;
	} while (m.cent < 0);

	return is;
}

ostream& operator << (ostream& os, const MONEY& m)
{
	os << m.dollar << " dollars " << m.cent << " cents";
	return os;
}

double MONEY::convertToVND(double TyGia) const
{
	return dollar * TyGia + cent * TyGia / 100.0;
}

MONEY& MONEY::operator++()
{
	if (cent < 99)
		++cent;
	else
	{
		cent = 0;
		++dollar;
	}
	return *this;
}

MONEY MONEY::operator++(int)
{
	MONEY temp(*this);
	++(*this);
	return temp;
}