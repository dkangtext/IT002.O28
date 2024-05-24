#pragma once

class SoPhuc
{
private:
	int phanThuc;
	int phanAo;

public:
	SoPhuc();
	SoPhuc(float t, float a);
	void Nhap();
	void Xuat();
	double Module() const;
	void Cong(SoPhuc sp);
	void Tru(SoPhuc sp);
	void Nhan(SoPhuc sp);
	void Chia(SoPhuc sp);
	~SoPhuc();
};

