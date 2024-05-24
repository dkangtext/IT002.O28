#pragma once
#ifndef _DIEMMAU
#define _DIEMMAU
#include "DIEM.h"
#include "MAU.h"

class DIEMMAU: public DIEM, public MAU
{
private:
	static int dem;

public:
	~DIEMMAU();
	DIEMMAU(double = 0, double = 0, int = 0, int = 0, int = 0);
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEMMAU&) const;
	friend istream& operator>>(istream&, DIEMMAU&);
	friend ostream& operator<<(ostream&, const DIEMMAU&);
};
#endif // !_DIEMMAU