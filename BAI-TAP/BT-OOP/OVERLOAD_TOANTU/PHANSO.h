#pragma once
#ifndef _PHANSO

class PHANSO
{
private:
	int tuSo, mauSo;
	static int Dem;

public:

	// Hàm thiết lập

	PHANSO();
	PHANSO(int);
	PHANSO(int, int);

	// PHANSO(int = 0, int i = 1);

	~PHANSO();

	// Bo Truy van va Cap nhat du lieu

	int GetTuSo() const; // Ham hang la bao toan gia tri cua doi tuong dang xet (khong duoc thay doi)
	int GetMauSo() const;
	static int GetDem();
	void SetTuSo(int);
	void SetMauSo(int);
	void SetPhanSo(int, int);
	void Nhap();
	void Xuat() const;
	void RutGon();
	int TimUSCLN(int, int);
	PHANSO Cong(const PHANSO&);
	// PHANSO operator+(const PHANSO&);
	friend PHANSO operator+(const PHANSO&, const PHANSO&);
};
#endif // !_PHANSO
