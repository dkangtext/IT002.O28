#include "MATRANVUONG.h"

MATRANVUONG::MATRANVUONG()
{
	n = 0;
	p = nullptr;
}

MATRANVUONG::MATRANVUONG(int n, int m)
{
	if (n == 0)
	{
		this->n = n;
		p = NULL;
	}
	else
	{
		this->n = n;
		while (n <= 0)
		{
			cout << "Nhap lai n (n > 0): ";
			cin >> n;
		}
		p = new int* [n];
		for (int i = 0; i < n; i++)
		{
			p[i] = new int[n];
			for (int j = 0; j < n; ++j)
				p[i][j] = m;
		}
	}
}

MATRANVUONG::MATRANVUONG(const MATRANVUONG& m)
{
	p = new int*[m.n];
	for (int i = 0; i < m.n; ++i)
	{
		p[i] = new int[m.n];
		for (int j = 0; j < m.n; ++j)
			p[i][j] = m.p[i][j];
	}
}

MATRANVUONG::~MATRANVUONG()
{
	if (p != NULL)
	{
		delete[] p;
		p = NULL;
		n = 0;
	}
}

void MATRANVUONG::SetN()
{
	this->n = n;
}

int MATRANVUONG::GetN()
{
	return n;
}

MATRANVUONG MATRANVUONG::GetMaTran()
{
	return *this;
}

istream& operator >> (istream& is, MATRANVUONG &m)
{
	if (m.p != NULL)
		m.~MATRANVUONG();
	cout << "Nhap n cho ma tran vuong: ";
	is >> m.n;
	
	while (m.n == 0)
	{
		cout << "Nhap khong hop le. Nhap n > 0: ";
		is >> m.n;
	}
	
	cout << "Nhap gia tri cho tung phan tu cua mang: ";
	m.p = new int* [m.n];
	
	for (int i = 0; i < m.n; ++i)
	{
		m.p[i] = new int[m.n];
		for (int j = 0; j < m.n; ++j)
			is >> m.p[i][j];
	}
	return is;
}

ostream& operator << (ostream& os, const MATRANVUONG& m)
{
	for (int i = 0; i < m.n; ++i)
	{
		for (int j = 0; j < m.n; ++j)
			os << m.p[i][j] << "\t";
		os << "\n";
	}
	return os;
}

void MATRANVUONG::LietKePhanTuLeNamTrenDuongCheoChinh()
{
	int S = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((p[i][j] % 2 == 1) && i == j)
			{
				cout << p[i][j] << "\t";
				S++;
			}
		}
	}

	if (S == 0)
		cout << "Khong co phan tu le tren duong cheo chinh.";
}

int MATRANVUONG::DemKyTu3NamTrenDuongCheoPhu()
{
	int Count = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i + j == n - 1)
			{
				int x = p[i][j];
				while (x / 10 > 0)
				{
					x /= 10;
				}
				if (x == 3)
					Count++;
			}
		}
	}

	if (Count == 0) return -1;
	return Count;
}

int MATRANVUONG::KiemTraAmNuaTrenDuongCheoChinh()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j > i)
			{
				if (p[i][j] < 0)
					return 1;
			}
		}
	}
	return 0;
}

int MATRANVUONG::ChanDauTienNuaDuoiDuongCheoPhu()
{
	for (int i = 1; i < n; ++i)
		for (int j = n - i; j < n; ++j)
			if (p[i][j] % 2 == 0)
				return p[i][j];
	return -1;
}

void MATRANVUONG::SapXepGiamDanDuongCheoPhu()
{
	int a[100];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i + j == n - 1)
			{
				a[i] = p[i][j];
			}
		}
	}

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (a[i] < a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i + j == n - 1)
			{
				p[i][j] = a[i];
			}
		}
	}
}