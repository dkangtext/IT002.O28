#include "MATRAN.h"

bool MATRAN::KiemTraSoNguyenTo(int n)
{
	bool SoNguyenTo = true;
	if (n < 2)
		SoNguyenTo = false;
	else
		for (int i = 2; i <= n / 2; i++)
			if (n % i == 0)
			{
				SoNguyenTo = false;
				break;
			}
	return SoNguyenTo;
}

bool MATRAN::KiemTraSoChinhPhuong(int n)
{
	bool SoChinhPhuong = false;
	if (n < 1)
		SoChinhPhuong = true;
	else
		/*
		for (int i = 1; i <= sqrt(n); i++)
			if (i * i == n)
			{
				SoChinhPhuong = true;
				break;
			}
		*/
		if (sqrt(n) == (int)sqrt(n))
			SoChinhPhuong = true;
	return SoChinhPhuong;
}

bool MATRAN::KiemTraSoHoanThien(int n)
{
	bool SoHoanThien;
	if (n < 6)
		SoHoanThien = false;
	else
	{
		int TongCuaChung = 0;
		for (int i = 1; i <= n / 2; i++)
			if (n % i == 0)
				TongCuaChung += 1;
		SoHoanThien = TongCuaChung == n ? true : false;
	}
	return SoHoanThien;
}

bool MATRAN::KiemTraSoDoiXung(int n)
{
	bool SoDoiXung;
	if (n < 1)
		SoDoiXung = false;
	else
	{
		int m = n, dv, dao = 0;
		while (m > 0)
		{
			dv = m % 10;			// Trích lấy chữ số hàng đơn vị.
			dao = dao * 10 + dv;	// Ghép chứ số hàng đơn vị vào số đảo.
			m /= 10;				// Bỏ chữ số hàng đơn vị
		}
		SoDoiXung = dao == n ? true : false;
	}
	return SoDoiXung;
}

MATRAN::MATRAN()
{
	sd = 0;
	sc = 0;
	p = nullptr;
}

MATRAN::MATRAN(int d, int c)
{
	sd = d;
	sc = c;
	p = new int* [sd];
	for (int i = 0; i < sd; i++)
	{
		p[i] = new int[sc];
		for (int j = 0; j < sc; j++)
			p[i][j] = 0;
	}
}

MATRAN::MATRAN(int d, int c, int k)
{
	if (sd == 0 && sc == 0)
	{
		this->sd = 0;
		this->sc = 0;
		p = NULL;
	}
	else
	{
		while (sd < 0)
		{
			cout << "Nhap lai so dong (sd > 0): ";
			cin >> sd;
		}
		this->sd = sd;

		while (sc < 0)
		{
			cout << "Nhap lai so cot (sc > 0): ";
			cin >> sc;
		}
		this->sc = sc;

		p = new int* [sd];

		for (int i = 0; i < sd; ++i)
		{
			p[i] = new int[sc];
			for (int j = 0; j < sc; ++j)
				p[i][j] = k;
		}
	}
}

MATRAN& MATRAN::operator=(const MATRAN& m)
{
	sd = m.sd;
	sc = m.sc;
	p = new int* [sd];

	for (int i = 0; i < sd; ++i)
	{
		p[i] = new int[sc];
		for (int j = 0; j < sc; ++j)
		{
			p[i][j] = m.p[i][j];
		}
	}
	return *this;
}

MATRAN::~MATRAN()
{
	sd = 0;
	sc = 0;
	if (p != nullptr)
	{
		for (int i = 0; i < sd; i++)
		{
			delete[] p[i];
		}
		delete[]p;
	}
}

void MATRAN::SetSD(int d)
{
	sd = d;
}

void MATRAN::SetSC(int c)
{
	sc = c;
}

int** MATRAN::GetP()
{
	return p;
}

int MATRAN::GetSD()
{
	return sd;
}

int MATRAN::GetSC() 
{
	return sc;
}

MATRAN MATRAN::SetMaTran(int** m, int d, int c)
{
	if (p != NULL)
	{
		for (int i = 0; i < sd; i++)
			delete[] p[i];
		delete[] p;
	}
	
	sd = d;
	sc = c;
	
	p = new int* [sd];

	for (int i = 0; i < sd; i++)
	{
		p[i] = new int[sc];
		for (int j = 0; j < sc; j++)
			p[i][j] = m[i][j];
	}
	return *this;
}
	
istream& operator >> (istream& is, MATRAN& m)
{
	if (m.p != nullptr)
	{
		for (int i = 0; i < m.sd; ++i)
		{
			delete[] m.p[i];
		}
		delete[] m.p;
	}

	do
	{
		cout << "Nhap so dong cua ma tran: ";
		is >> m.sd;
	} while (m.sd <= 0);

	do
	{
		cout << "Nhap so cot cua ma tran: ";
		is >> m.sc;
	} while (m.sc <= 0);

	m.p = new int* [m.sd];
	cout << "Nhap gia tri cho tung phan tu cua ma tran:\n";
	for (int i = 0; i < m.sd; ++i)
	{
		m.p[i] = new int[m.sc];
		for (int j = 0; j < m.sc; ++j)
		{
			cout << "Nhap a[" << i << "][" << j << "]: ";
			is >> m.p[i][j];
		}
	}
	return is;
}

ostream& operator << (ostream& os, const MATRAN& m)
{
	for (int i = 0; i < m.sd; ++i)
	{
		for (int j = 0; j < m.sc; ++j)
		{
			os << m.p[i][j] << "\t";
		}
		os << "\n";
	}
	return os;
}

void MATRAN::LietKeSoNguyenTo()
{
	cout << "Cac so nguyen to trong ma tran:\n";
	for (int i = 0; i < sd; ++i)
	{
		for (int j = 0; j < sc; ++j)
		{
			if (KiemTraSoNguyenTo(p[i][j]))
				cout << p[i][j] << " ";
		}
	}
	cout << endl;
}

int MATRAN::DemSoChinhPhuong()
{
	int count = 0;
	for (int i = 0; i < sd; ++i)
	{
		for (int j = 0; j < sc; ++j)
		{
			if (KiemTraSoChinhPhuong(p[i][j]))
				count++;
		}
	}
	return count;
}

int MATRAN::TinhTongSoHoanThien(int k)
{
	int sum = 0;
	for (int j = 0; j < sc; j++)
		if (KiemTraSoHoanThien(p[k][j]))
			sum += p[k][j];
	return sum;
}

double MATRAN::TinhTrungBinhCongSoDoiXung(int k)
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < sd; i++)
	{
		if (KiemTraSoDoiXung(p[i][k]))
		{
			sum += p[i][k];
			count++;
		}
	}
	return (double)sum / count;
}

MATRAN MATRAN::SapXepTuBeDenLon(int k)
{
	MATRAN temp(*this);
	for (int i = 0; i < sc - 1; ++i)
	{
		for (int j = i + 1; j < sc; ++j)
		{
			if (temp.p[k][i] > temp.p[k][j])
			{
				int t = temp.p[k][i];
				temp.p[k][i] = temp.p[k][j];
				temp.p[k][j] = t;
			}
		}
	}
	return temp;
}


