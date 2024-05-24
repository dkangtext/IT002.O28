#include "PHANSO.h"

int PHANSO::Dem = 0;

PHANSO::~PHANSO()
{
	//cout << "Da huy 1 phan so  => " << --Dem << " phan so\n";
	Dem--;
}

PHANSO::PHANSO() : tuSo(0), mauSo(1)
{
	Dem++;
}

PHANSO::PHANSO(int tuSo) : tuSo(tuSo), mauSo(1)
{
	Dem++;
}

PHANSO::PHANSO(int tuSo, int mauSo) : tuSo(tuSo), mauSo(mauSo)
{
	Dem++;
}

PHANSO::PHANSO(const PHANSO& ps) : tuSo(ps.tuSo), mauSo(ps.mauSo)
{
	Dem++;
}

//PHANSO(int = 0, int = 1);

void PHANSO::Nhap()
{
	cout << "Nhap tu so: ";
	cin >> tuSo;

	do
	{
		cout << "Nhap mau so (khac 0): ";
		cin >> mauSo;
	} while (mauSo == 0);
}

void PHANSO::Xuat()
{
	RutGon();
	if (mauSo < -1)
		cout << -tuSo << "/" << -mauSo;
	else if (mauSo == -1)
		cout << -tuSo;
	else if (mauSo == 0)
		cout << "Khong chia cho so 0";
	else if (mauSo == 1)
		cout << tuSo;
	else
		cout << tuSo << "/" << mauSo;
}

int PHANSO::TimUSCLN(int a, int b)
{
	int USCLN;
	a = abs(a); // absolute |a|
	b = abs(b); // absolute |b|

	if (a == 0 && b == 0)
		USCLN = 1;
	else if (a == 0 || b == 0)
		USCLN = a + b;
	else
	{
		// Dùng giải thuật Euclide
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		USCLN = a; // hoặc: USCLN = b;
	}
	return USCLN;
}

void PHANSO::RutGon()
{
	int USCLN = TimUSCLN(tuSo, mauSo);
	tuSo /= USCLN;
	mauSo /= USCLN;
}

int PHANSO::GetTuSo() const
{
	return tuSo;
}

int PHANSO::GetMauSo() const
{
	return mauSo;
}

int PHANSO::GetDem()
{
	return Dem;
}

void PHANSO::SetTuSo(int tuSo)
{
	this->tuSo = tuSo;
}

void PHANSO::SetMauSo(int mauSo)
{
	this->mauSo = mauSo;
}

void PHANSO::SetPhanSo(int tuSo, int mauSo)
{
	this->tuSo = tuSo;
	this->mauSo = mauSo;
}

/* 
PHANSO PHANSO::Cong(const PHANSO& ps)
{
	return PHANSO(tuSo * ps.mauSo + mauSo * ps.tuSo, mauSo * ps.mauSo);
}
*/

/*
PHANSO PHANSO::operator+(const PHANSO& ps)
{
	return PHANSO(tuSo * ps.mauSo + mauSo * ps.tuSo, mauSo * ps.mauSo);
}
*/

/* 
PHANSO Cong(const PHANSO& ps1, const PHANSO& ps2)
{
	return PHANSO(ps1.tuSo * ps2.mauSo + ps1.mauSo * ps2.tuSo, ps1.mauSo * ps2.mauSo);
}
*/

PHANSO operator+(const PHANSO& ps1, const PHANSO& ps2)
{
	return PHANSO(ps1.tuSo * ps2.mauSo + ps1.mauSo * ps2.tuSo, ps1.mauSo * ps2.mauSo);
}

PHANSO operator-(const PHANSO& ps1, const PHANSO& ps2)
{
	return PHANSO(ps1.tuSo * ps2.mauSo - ps1.mauSo * ps2.tuSo, ps1.mauSo * ps2.mauSo);
}

PHANSO operator*(const PHANSO& ps1, const PHANSO& ps2)
{
	return PHANSO(ps1.tuSo * ps2.tuSo, ps1.mauSo * ps2.mauSo);
}

PHANSO operator/(const PHANSO& ps1, const PHANSO& ps2)
{
	return PHANSO(ps1.tuSo * ps2.mauSo, ps1.mauSo * ps2.tuSo);
}

PHANSO PHANSO::operator++() //++ps_this
{
	tuSo = tuSo + mauSo; // tăng ps_this lên 1
	return *this; // trả về ps_this sau khi tăng 1
}

PHANSO PHANSO::operator++(int) //ps_this++
{
	PHANSO pstam(tuSo, mauSo); // lưu giá trị ps_this trước khi tăng lên 1
	tuSo = tuSo + mauSo; // tăng ps_this lên 1
	return pstam; // trả về giá trị ps_this trước khi tăng lên 1
}

PHANSO PHANSO::operator--() //--ps_this
{
	tuSo = tuSo - mauSo; // giảm ps_this xuống 1
	return *this; // trả về ps_this sau khi giảm xuống 1
}

PHANSO PHANSO::operator--(int) //ps_this--
{
	PHANSO pstam(tuSo, mauSo); // lưu giá trị ps_this trước khi giảm xuống 1
	tuSo = tuSo - mauSo; // giảm ps_this xuống 1
	return pstam; // trả về giá trị ps_this trước khi giảm xuống 1
}

/*
Ép kiểu số thực cho ps_this: (double)ps_this.

Nếu có phương thức này thì phải ép kiểu tường minh số và phân số khi tính giá trị biểu thức để tránh nhọc nhằng:
VD: PHANSO A = ++ps2 + ps3-- + (PHANSO)5;
	double B = (double)ps2 + 3;
*/

PHANSO::operator double() const //(double)ps_this
{
	return (double)tuSo / mauSo;
}

bool operator==(const PHANSO& ps1, const PHANSO& ps2)
{
	return ps1.tuSo * ps2.mauSo == ps2.tuSo * ps1.mauSo;
	// return (double)ps1 == (double)ps2;
}

bool operator!=(const PHANSO& ps1, const PHANSO& ps2)
{
	return ps1.tuSo * ps2.mauSo != ps2.tuSo * ps1.mauSo;
	// return (double)ps1 != (double)ps2;
}

bool operator<(const PHANSO& ps1, const PHANSO& ps2)
{
	return ps1.tuSo * ps2.mauSo < ps2.tuSo * ps1.mauSo;
	// return (double)ps1 < (double)ps2;
}

bool operator<=(const PHANSO& ps1, const PHANSO& ps2)
{
	return ps1.tuSo * ps2.mauSo <= ps2.tuSo * ps1.mauSo;
	// return (double)ps1 <= (double)ps2;
}

bool operator>(const PHANSO& ps1, const PHANSO& ps2)
{
	return ps1.tuSo * ps2.mauSo > ps2.tuSo * ps1.mauSo;
	// return (double)ps1 > (double)ps2;
}

bool operator>=(const PHANSO& ps1, const PHANSO& ps2)
{
	return ps1.tuSo * ps2.mauSo > ps2.tuSo * ps1.mauSo;
	// return (double)ps1 >= (double)ps2;
}

istream& operator>>(istream& is, PHANSO& ps)
{
	cout << "Nhap tu so: ";
	is >> ps.tuSo;

	do
	{
		cout << "Nhap mau so (khac 0): ";
		is >> ps.mauSo;
	} while (ps.mauSo == 0);
	return is;
	
	/* 
	Hoặc:
		ps.Nhap();
		return is;
	*/
}

ostream& operator<<(ostream& os, PHANSO& ps)
{
	ps.RutGon();

	if (ps.mauSo < -1)
		os << -ps.tuSo << "/" << -ps.mauSo;
	else if (ps.mauSo == -1)
		os << -ps.tuSo;
	else if (ps.mauSo == 0)
		os << "Khong chia cho so 0";
	else if (ps.mauSo == 1)
		os << ps.tuSo;
	else
		os << ps.tuSo << "/" << ps.mauSo;
	return os;

	/* 
	Hoặc:
		ps.Xuat();
		return os;
	*/
}