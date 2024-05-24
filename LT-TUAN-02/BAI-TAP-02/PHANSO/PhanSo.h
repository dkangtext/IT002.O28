#pragma once

class PhanSo
{
private:
	int tuSo;
	int mauSo;

public:
	PhanSo();
	PhanSo(int tu, int mau);
	void Nhap();
	void Xuat();
	PhanSo Cong(PhanSo ps);
	PhanSo Tru(PhanSo ps);
	PhanSo Nhan(PhanSo ps);
	PhanSo Chia(PhanSo ps);
};

