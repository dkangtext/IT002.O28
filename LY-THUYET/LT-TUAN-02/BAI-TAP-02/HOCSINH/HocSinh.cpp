#include "HocSinh.h"
#include <iostream>

using namespace std;

HocSinh::HocSinh() : hoTen(""), diemVan(0), diemToan(0) {}

HocSinh::HocSinh(string ten, double van, double toan) : hoTen(ten), diemVan(van), diemToan(toan) {}

void HocSinh::nhapHocSinh() 
{
    cout << "Nhap ho ten hoc sinh: ";
    getline(cin >> ws, hoTen);
    cout << "Nhap diem van: ";
    cin >> diemVan;
    cout << "Nhap diem toan: ";
    cin >> diemToan;
}

void HocSinh::xuatHocSinh() 
{
    cout << "Ho ten: " << hoTen << endl;
    cout << "Diem van: " << diemVan << endl;
    cout << "Diem toan: " << diemToan << endl;
}

double HocSinh::tinhDTB() 
{
    return (diemVan + diemToan) / 2;
}

std::string HocSinh::xepLoai() 
{
    double dtb = tinhDTB();
    if (dtb >= 8.0)
        return "Gioi";
    else if (dtb >= 6.5)
        return "Kha";
    else if (dtb >= 5.0)
        return "Trung binh";
    else
        return "Yeu";
}
