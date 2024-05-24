#pragma once
#ifndef _DIEMMAU3C
#define _DIEMMAU3C
#include "DIEM3C.h"

class DIEMMAU3C: public DIEM3C
{
protected:
	int r, g, b; // [0, 255]
	static int dem;

public:
	~DIEMMAU3C();
	DIEMMAU3C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
	int GetR() const;
	int GetG() const;
	int GetB() const;
	void SetR(int);
	void SetG(int);
	void SetB(int);
	void SetRGB(int, int, int);
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEMMAU3C&) const;
	friend istream& operator>>(istream&, DIEMMAU3C&);
	friend ostream& operator<<(ostream&, const DIEMMAU3C&);
};
#endif // !_DIEMMAU3C