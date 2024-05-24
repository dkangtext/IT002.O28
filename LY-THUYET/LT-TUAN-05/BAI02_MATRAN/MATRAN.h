#pragma once
#ifndef _MATRAN
#define _MATRAN

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class MATRAN
{
private:
	int** p;							// Con trỏ tới vùng nhớ động chứa các phần tử ma trận.
	int sd;								// Số dòng của ma trận.
	int sc;								// Số cột của ma trận.
	bool KiemTraSoNguyenTo(int);
	bool KiemTraSoChinhPhuong(int);
	bool KiemTraSoHoanThien(int);
	bool KiemTraSoDoiXung(int);

public:
	// Các phương thức thiết lập và hủy
	MATRAN();								// Thiết lập không tham số.
	MATRAN(int, int);
	MATRAN(int, int, int);					// Thiết lập truyền tham số n.
	MATRAN& operator = (const MATRAN&);		// Thiết lập sao chép.
	~MATRAN();								// Hủy.

	void SetSD(int);
	void SetSC(int);
	MATRAN SetMaTran(int**, int, int);

	int** GetP();
	int GetSD();
	int GetSC();

	// Các phương thức nhập xuất
	friend istream& operator >> (istream&, MATRAN&);		// Nhập giá trị các phần tử ma trận.
	friend ostream& operator << (ostream&, const MATRAN&);	// Xuất giá trị các phần tử ma trận.

	// Các phương thức khác
	void LietKeSoNguyenTo();				// Liệt kê giá trị các phần tử là số nguyên tố của ma trận.
	int DemSoChinhPhuong();					// Đếm số lượng các phần tử là số chính phương của ma trận.
	int TinhTongSoHoanThien(int);			// Tính tổng giá trị các phần tử là số hoàn thiện trên dòng k của ma trận.
	double TinhTrungBinhCongSoDoiXung(int);	// Tính trung bình cộng giá trị các phần tử là số đối xứng trên cột k của ma trận.
	MATRAN SapXepTuBeDenLon(int);			// Sắp xếp tăng dần các phần tử trên dòng k của ma trận.
};

#endif // !_MATRAN


