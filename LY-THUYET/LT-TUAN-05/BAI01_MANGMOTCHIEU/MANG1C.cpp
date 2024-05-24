#include "MANG1C.h"

bool MANG1C::KiemTraSoNguyenTo(int n)
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

bool MANG1C::KiemTraSoChinhPhuong(int n)
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

bool MANG1C::KiemTraSoHoanThien(int n)
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

bool MANG1C::KiemTraSoDoiXung(int n)
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

MANG1C::~MANG1C()
{
	if (a != NULL)
	{
		delete[]a;
		a = NULL;
		n = 0;
		// cout << "Da huy Mang 1 chieu \n";
	}
}

MANG1C::MANG1C(int n, int m)
{
	if (n == 0)
	{
		this->n = 0;
		a = NULL;
	}
	else
	{
		while (n <= 0)
		{
			cout << "Nhap lai so phan tu mang > 0: ";
			cin >> n;
		}
		this->n = n;
		a = new int[this->n];
		for (int i = 0; i < this->n; i++)
			a[i] = m;
	}
}

MANG1C::MANG1C(const MANG1C& m)
{
	if (m.n == 0)
	{
		this->n = 0;
		a = NULL;
	}
	else
	{
		n = m.n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = m.a[i];
	}
}

MANG1C& MANG1C::operator=(const MANG1C& m)
{
	if (m.n == 0)
	{
		this->n = 0;
		a = NULL;
	}
	else
	{

		n = m.n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = m.a[i];
	}
	return *this;
}

int* MANG1C::GetA()
{
	return a;
}

int MANG1C::GetN()
{
	return n;
}

istream& operator >> (istream& is, MANG1C& m)
{
	if (m.a != NULL)
		m.~MANG1C();
	do
	{
		cout << "Nhap so phan tu mang > 0: ";
		is >> m.n;
	} while (m.n <= 0);

	m.a = new int[m.n];

	for (int i = 0; i < m.n; i++)
	{
		cout << "a[" << i << "] = ";
		is >> m.a[i];
	}
	return is;
}

ostream& operator << (ostream& os, const MANG1C& m)
{
	if (m.a == NULL)
		os << "Mang rong.\n";
	else
	{
		for (int i = 0; i < m.n; i++)
			os << m.a[i] << "\t";
		os << endl;
	}
	return os;
}

void MANG1C::PhatSinh()
{
	if (a != NULL)
		this->~MANG1C();
	do
	{
		cout << "Nhap so phan tu mang > 0: ";
		cin >> n;
	} while (n <= 0);
	
	a = new int[n];
	
	int mi, ma;
	cout << "Nhap mien gia tri phat sinh: ";
	cin >> mi >> ma;

	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = mi + rand() % (ma - mi + 1); // [mi, ma]
}

void MANG1C::LietKeSoNguyenTo()
{
	int DemSoNguyenTo = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraSoNguyenTo(a[i]))
		{
			cout << a[i] << "\t";
			DemSoNguyenTo++;
		}
	cout << endl;
	if (DemSoNguyenTo == 0)
		cout << "Mang khong chua phan tu la So Nguyen to\n";
}

int MANG1C::DemSoChinhPhuong()
{
	int DemSoChinhPhuong = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraSoChinhPhuong(a[i]))
			DemSoChinhPhuong++;
	return DemSoChinhPhuong;
}

int MANG1C::TinhTongSoHoanThien()
{
	int TongSoHoanThien = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraSoHoanThien(a[i]))
			TongSoHoanThien += a[i];
	return TongSoHoanThien;
}

double MANG1C::TinhTrungBinhCongSoDoiXung()
{
	double TongSoDoiXung = 0, DemSoDoiXung = 0;
	for (int i = 0; i < n; i++)
		if (KiemTraSoDoiXung(a[i]))
		{
			TongSoDoiXung += a[i];
			DemSoDoiXung++;
		}
	return DemSoDoiXung > 0 ? TongSoDoiXung / DemSoDoiXung : 0;
}

bool MANG1C::KiemTraMangLe()
{
	bool MangLe = true;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
		{
			MangLe = false;
			break;
		}
	return MangLe;
}

void MANG1C::TimChanBeNhat()
{
	int vtChanDau = -1;
	int gtChanBeNhat;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
		{
			vtChanDau = i;
			gtChanBeNhat = a[i];
			break;
		}

	if (vtChanDau != -1)
	{
		for (int i = vtChanDau + 1; i < n; i++)
			if (a[i] % 2 == 0 && a[i] < gtChanBeNhat)
			{
				vtChanDau = i;
				gtChanBeNhat = a[i];
			}
		cout << "Phan tu chan be nhat trong mang la a[" << vtChanDau << "] = " << gtChanBeNhat << endl;
	}
	else
		cout << "Mang khong co phan tu chan\n";
}

void MANG1C::SapXepMangTang()
{
	int Tam;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] > a[j])
			{
				Tam = a[i];
				a[i] = a[j];
				a[j] = Tam;
			}
}

void MANG1C::XoaTaiViTri(int vt)
{
	MANG1C MangMoi(n - 1);	 // Gọi phương thức thiết lập MangMoi có n - 1 phần tử 0.

	for (int i = 0; i < vt; i++)
		MangMoi.a[i] = a[i];

	for (int i = vt; i < n - 1; i++)
		MangMoi.a[i] = a[i + 1];

	this->~MANG1C();
	*this = MangMoi;		// Gọi hàm nạp chồng toán tử gán
	MangMoi.~MANG1C();
}

void MANG1C::ThemTaiViTri(int vt, int gt)
{
	MANG1C MangMoi(n + 1);	 // Gọi phương thức thiết lập MangMoi có n + 1 phần tử 0.

	for (int i = 0; i < vt; i++)
		MangMoi.a[i] = a[i];

	for (int i = vt; i < n - 1; i++)
		MangMoi.a[i] = a[i - 1];

	this->~MANG1C();
	*this = MangMoi;		// Gọi hàm nạp chồng toán tử gán
	MangMoi.~MANG1C();
}

int MANG1C::TimKiemTuyenTinh(int gt)
{
	int TimThay = -1;		// Chưa tìm thấy.
	for (int i = 0; i < n; i++)
		if (a[i] == gt)
		{
			TimThay = i;	// Tìm thấy tại vị trí i.
			break;
		}
	return TimThay;
}

int MANG1C::TimKiemNhiPhan(int gt)
{
	int Dau = 0; 
	int Cuoi = n - 1;
	int Giua;
	int TimThay = -1;		// Chưa tìm thấy.
	while (Dau <= Cuoi)
	{
		Giua = (Dau + Cuoi) / 2;
		if (a[Giua] == gt)
		{
			TimThay = Giua;	// Tìm thấy tại ví trị giữa.
			break;
		}

		if (gt < a[Giua])
			Cuoi = Giua - 1;
		else
			Dau = Giua + 1;
	}
	return TimThay;
}