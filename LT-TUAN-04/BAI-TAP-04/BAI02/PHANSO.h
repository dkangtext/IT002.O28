#pragma once
#ifndef _ClassPHANSO
#include <iostream>
using namespace std;

class PHANSO
{
private:
	int tuSo;
	int mauSo;
	static int Dem;

public:
	~PHANSO();
	PHANSO();
	PHANSO(int);
	PHANSO(int, int);
	PHANSO(const PHANSO&);

	//PHANSO(int = 0, int = 1);

	void Nhap();
	void Xuat();

	int TimUSCLN(int, int);
	void RutGon();

	int GetTuSo() const;
	int GetMauSo() const;
	static int GetDem();

	void SetTuSo(int);
	void SetMauSo(int);
	void SetPhanSo(int, int);

	//PHANSO Cong(const PHANSO&);
	//PHANSO operator+(const PHANSO&);
	//friend PHANSO Cong(const PHANSO&, const PHANSO&);

	friend PHANSO operator+(const PHANSO&, const PHANSO&);
	friend PHANSO operator-(const PHANSO&, const PHANSO&);
	friend PHANSO operator*(const PHANSO&, const PHANSO&);
	friend PHANSO operator/(const PHANSO&, const PHANSO&);

	PHANSO operator++(); //++ps_this
	PHANSO operator++(int); //ps_this++
	PHANSO operator--(); //--ps_this
	PHANSO operator--(int); //ps_this--

	operator double() const; //(double)ps_this

	friend bool operator==(const PHANSO&, const PHANSO&);
	friend bool operator!=(const PHANSO&, const PHANSO&);
	friend bool operator<(const PHANSO&, const PHANSO&);
	friend bool operator<=(const PHANSO&, const PHANSO&);
	friend bool operator>(const PHANSO&, const PHANSO&);
	friend bool operator>=(const PHANSO&, const PHANSO&);

	friend istream& operator>>(istream&, PHANSO&);
	friend ostream& operator<<(ostream&, PHANSO&);
};
#endif // !_ClassPHANSO