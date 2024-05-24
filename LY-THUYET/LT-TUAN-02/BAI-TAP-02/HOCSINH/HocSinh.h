#pragma once

#ifndef HOCSINH_H
#define HOCSINH_H

#include <iostream>
#include <string>

using namespace std;

class HocSinh 
{
private:
    string hoTen;
    double diemVan;
    double diemToan;

public:
    HocSinh(); // Khởi tạo học sinh tên rỗng và điểm văn, toán đều bằng 0
    HocSinh(string ten, double van, double toan); // Khởi tạo học sinh với tên, điểm văn, điểm toán tùy ý
    void nhapHocSinh(); // Nhập thông tin học sinh từ bàn phím
    void xuatHocSinh(); // Xuất thông tin học sinh ra màn hình
    double tinhDTB(); // Tính điểm trung bình của học sinh
    string xepLoai(); // Xếp loại học sinh
};

#endif 

