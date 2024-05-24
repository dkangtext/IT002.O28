#pragma once
#ifndef _MATRANVUONG
#define _MATRANVUONG

#include <iostream>

using namespace std;

class MATRANVUONG
{
private:
	int n;									// Số cấp ma trận.
	int** p;								// Con trỏ tới vùng nhớ động chứa các phần tử ma trận.

public:
	// Các phương thức thiết lập
	MATRANVUONG();							// Thiết lập không tham số.
	MATRANVUONG(int, int);					// Thiết lập truyền tham số n.
	MATRANVUONG(const MATRANVUONG&);		// Thiết lập sao chép.
	~MATRANVUONG();							// Hủy.

	void SetN();
	int GetN();
	MATRANVUONG GetMaTran();

	// Các phương thức nhập và xuất giá trị các phần tử ma trận
	friend istream& operator >> (istream&, MATRANVUONG&);
	friend ostream& operator << (ostream&, const MATRANVUONG&);

	// Các phương thức khác
	void LietKePhanTuLeNamTrenDuongCheoChinh();		// Liệt kê giá trị các phần tử lẻ nằm trên đường chéo chính của ma trận.
	int DemKyTu3NamTrenDuongCheoPhu();				// Đếm số lượng các phần tử có ký số cuối là 3 nằm trên đường chéo phụ của ma trận.
	int KiemTraAmNuaTrenDuongCheoChinh();			// Kiểm tra xem có tồn tại phần tử âm ở nửa mảng vuông phía trên đường chéo chính hay không?
	int ChanDauTienNuaDuoiDuongCheoPhu();			// Tìm phần tử chẵn đầu tiên ở nửa mảng vuông phía dưới dòng đường chéo phụ của ma trận.
	void SapXepGiamDanDuongCheoPhu();				// Sắp xếp giảm dần các phần tử trên đường chéo phụ của ma trận.
};

#endif // !_MATRANVUONG