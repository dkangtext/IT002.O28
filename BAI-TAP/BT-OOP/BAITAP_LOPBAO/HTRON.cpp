#include "HTRON.h"
#include <iostream>
#include <cmath>

using namespace std;

float M_PI = 3.14;

HTRON::HTRON() : O(0, 0), R(1) {}

HTRON::HTRON(const DIEM& O, double R) : O(O), R(R) {}

void HTRON::SetO(const DIEM& O) 
{
    this->O = O;
}

DIEM HTRON::GetO() const 
{
    return O;
}

void HTRON::SetR(double R) 
{
    this->R = R;
}

double HTRON::GetR() const 
{
    return R;
}

void HTRON::Nhap() {
    cout << "Nhap thong tin hinh tron:\n";
    cout << "Nhap toa do tam O:\n";
    O.Nhap();
    cout << "Nhap ban kinh R: ";
    cin >> R;
}

void HTRON::Xuat() const 
{
    cout << "Hinh tron co tam O: (";
    O.Xuat();
    cout << ")";
    cout << " va ban kinh R = " << R << endl;
}

void HTRON::DiChuyen(double dx, double dy) 
{
    O.DiChuyen(dx, dy);
}

double HTRON::TinhChuVi() const 
{
    return 2 * M_PI * R;
}

double HTRON::TinhDienTich() const 
{
    return M_PI * R * R;
}

bool HTRON::KiemTraHopLe() const 
{
    return R > 0;
}
