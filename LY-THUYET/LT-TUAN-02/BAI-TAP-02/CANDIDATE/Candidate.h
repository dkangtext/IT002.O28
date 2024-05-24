#pragma once
#include <iostream>
using namespace std;

class Candidate
{
private:
	char MaThiSinh[10];
	char TenThiSinh[10];
	int iNgay;
	int iThang;
	int iNam;
	double diemToan;
	double diemVan;
	double diemAnh;

public:
	void NhapThiSinh();
	void XuatThiSinh();
	double TinhTongDiem();
};

