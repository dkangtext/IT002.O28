#pragma once
#ifndef _MANG1C
#define _MANG1C

#include <iostream>
#include <iomanip>

using namespace std;

class MANG1C
{
private:
	int* a;								// Con trỏ tới vùng nhớ động chứa các phần tử mảng.
	int n;								// Số phần tử mảng .
	bool KiemTraSoNguyenTo(int);		// Liệt kê giá trị các phần tử là số nguyên tố trong mảng.
	bool KiemTraSoChinhPhuong(int);		// Đếm số lượng các phần tử là số chính phương trong mảng.
	bool KiemTraSoHoanThien(int);		// Tính tổng giá trị các phần tử là số hoàn thiện trong mảng.
	bool KiemTraSoDoiXung(int);			// Tính trung bình cộng giá trị các phần tử là số đối xứng trong mảng.

public:
	// Các phương thức thiết lập và hủy
	~MANG1C();							// Hủy
	MANG1C(int = 0, int = 0);			// Thiết lập không tham số và thiết lập truyền tham số n
	MANG1C(const MANG1C&);				// Thiết lập sao chép
	MANG1C& operator = (const MANG1C&);	// Thiết lập gán

	int* GetA();
	int GetN();

	// Các phương thức nhập xuất
	friend istream& operator >> (istream&, MANG1C&);		// Nhập giá trị các phần tử mảng.
	friend ostream& operator << (ostream&, const MANG1C&);	// Xuất giá trị các phần tử mảng.

	void PhatSinh();						// Khởi tạo các giá trị ngẫu nhiên cho mảng.
	void LietKeSoNguyenTo();				// Liệt kê giá trị các phần tử là số nguyên tố trong mảng.
	
	int DemSoChinhPhuong();					// Đếm số lượng các phần tử là số chính phương trong mảng.
	int TinhTongSoHoanThien();				// Tính tổng giá trị các phần tử là số hoàn thiện trong mảng.
	double TinhTrungBinhCongSoDoiXung();	// Tính trung bình cộng giá trị các phần tử là số đối xứng trong mảng.

	bool KiemTraMangLe();					// Kiểm tra mảng có phần tử lẻ hay không?
	void TimChanBeNhat();					// Tìm giá trị phần tử chẵn bé nhất trong mảng.
	void SapXepMangTang();					// Sắp xếp mảng tăng dần.

	void XoaTaiViTri(int);					// Xóa phần tử tại vị trí bất kỳ
	void ThemTaiViTri(int, int);			// Thêm phần tử tại vị trí bất kỳ
	
	int TimKiemTuyenTinh(int);				// Tìm kiếm phần tử có giá trị bất kỳ (tìm kiếm tuyến tính).
	int TimKiemNhiPhan(int);				// Tìm kiếm phần tử có giá trị bất kỳ (tìm kiếm nhị phân)
};

#endif // !_MANG1C
