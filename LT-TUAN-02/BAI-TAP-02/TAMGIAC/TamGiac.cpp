#include "TamGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

TamGiac::TamGiac() : a(0), b(0), c(0) {}

void TamGiac::nhapTamGiac()
{
    do {
        cout << "Nhap do dai canh a: ";
        cin >> a;
        cout << "Nhap do dai canh b: ";
        cin >> b;
        cout << "Nhap do dai canh c: ";
        cin >> c;

        if ((a + b > c) && (b + c > a) && (a + c > b))
            break;
        else
            cout << "Ba canh vua nhap khong tao thanh tam giac. Vui long nhap lai.\n";
    } while ((a + b > c) || (b + c > a) || (a + c > b));
}

void TamGiac::xuatTamGiac()
{
    cout << "Tam giac co 3 canh: a = " << a << ", b = " << b << ", c = " << c << endl;
}

bool TamGiac::kiemTraHopLe()
{
    return ((a + b > c) && (b + c > a) && (a + c > b));
}

void TamGiac::phanLoai()
{
    if (a == b && b == c)
        cout << "Tam giac deu";
    else if (a == b || b == c || c == a)
    {
        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
            cout << "Tam giac vuong can";
        else
            cout << "Tam giac can";
    }
    else
    {
        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
            cout << "Tam giac vuong";
        else
            cout << "Tam giac thuong";
    }
}

double TamGiac::tinhChuVi()
{
    return a + b + c;
}

double TamGiac::tinhDienTich()
{
    double p = tinhChuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
