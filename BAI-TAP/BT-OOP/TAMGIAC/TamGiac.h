#pragma once

#ifndef TAMGIAC_H
#define TAMGIAC_H

#include <iostream>
using namespace std;

class TamGiac
{
private:
    double a, b, c;

public:
    TamGiac();
    void nhapTamGiac();
    void xuatTamGiac();
    bool kiemTraHopLe();
    void phanLoai();
    double tinhChuVi();
    double tinhDienTich();
};

#endif
