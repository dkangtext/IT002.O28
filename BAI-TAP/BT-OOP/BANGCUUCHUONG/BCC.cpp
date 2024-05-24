#include "BCC.h"
#include <iomanip>

BCC::BCC(int m, int n)
{
	if (m < 2 || m > 9 || n < 2 || n > 9)
		Nhap();
	else
	{
		this->m = m;
		this->n = n;
	}
}

int BCC::GetM()
{
	return m;
}

int BCC::GetN()
{
	return n;
}

void BCC::SetM(int m)
{
	while (m < 2 || m > 9)
	{
		cout << "Nhap m tu 2 den 9: ";
		cin >> m;
	}
	this->m = m;
}

void BCC::SetN(int n)
{
	while (n < 2 || n > 9)
	{
		cout << "Nhap n tu 2 den 9: ";
		cin >> n;
	}
	this->n = n;
}

void BCC::SetMN(int m, int n)
{
	//SetM(m);
	//SetN(n);
	*this = BCC(m, n);
}

void BCC::Nhap()
{
	do
	{
		cout << "Nhap BCC m, n tu 2 den 9: ";
		cin >> m >> n;
	} while (m < 2 || m > 9 || n < 2 || n > 9);
}

void BCC::Xuat()
{
	cout << "-------------- In BCC thu " << m << " --------------:\n";
	InBCCm();
	cout << "-------------- In BCC tu " << m << " den " << n << " --------------:\n";
	InBCCmn();
	cout << "-------------- In BCC tong hop --------------:\n";
	InBCCth();
}

void BCC::InBCCm()
{
	for (int i = 1; i <= 10; i++)
		cout << m << " x " << setw(2) << i << " = " << setw(2) << m * i << endl;
}

void BCC::InBCCmn()
{
	int mi = min(m, n), ma = max(m, n);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = mi; j <= ma; j++)
		{
			cout << j << " x " << setw(2) << i << " = " << setw(2) << j * i << "\t";
		}
		cout << endl;
	}
}

void BCC::InBCCth()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << setw(3) << j * i << "\t";
		}
		cout << "\n\n";
	}
}