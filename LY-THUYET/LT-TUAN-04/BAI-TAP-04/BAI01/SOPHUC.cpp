#include "SOPHUC.h"
#include<iostream>
#include<cmath>
using namespace std;

int SOPHUC::Dem = 0;

SOPHUC::~SOPHUC()
{
    Dem--;
}

SOPHUC::SOPHUC()
{
    phanThuc = 0;
    phanAo = 0;
    Dem++;
}

SOPHUC::SOPHUC(double t, double a)
{
    phanThuc = t;
    phanAo = a;
    Dem++;
}

void SOPHUC::Nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> phanThuc;

    cout << "Nhap phan ao: ";
    cin >> phanAo;
}

void SOPHUC::Xuat()
{
    cout << "(" << phanThuc;
    if (phanAo >= 0)
        cout << " + " << phanAo << "i)";
    else
        cout << phanAo << "i)";
}

double SOPHUC::GetphanThuc() const
{
    return phanThuc;
}

double SOPHUC::GetphanAo() const
{
    return phanAo;
}

int SOPHUC::GetDem()
{
    return Dem;
}

void SOPHUC::SetphanThuc(double phanThuc)
{
    this->phanThuc = phanThuc;
}

void SOPHUC::SetphanAo(double phanAo)
{
    this->phanAo = phanAo;
}

void SOPHUC::SetSoPhuc(double phanThuc, double phanAo)
{
    this->phanThuc = phanThuc;
    this->phanAo = phanAo;
}

SOPHUC SOPHUC::operator+(const SOPHUC& sp)
{
    return SOPHUC(this->phanThuc + sp.phanThuc, this->phanAo + sp.phanAo);
}

SOPHUC SOPHUC::operator-(const SOPHUC& sp)
{
    return SOPHUC(this->phanThuc - sp.phanThuc, this->phanAo - sp.phanAo);
}

SOPHUC SOPHUC::operator*(const SOPHUC& sp)
{
    return SOPHUC(this->phanThuc * sp.phanThuc - this->phanAo * sp.phanAo, this->phanThuc * sp.phanAo + this->phanAo * sp.phanAo);
}

SOPHUC SOPHUC::operator/(const SOPHUC& sp)
{
    return SOPHUC((this->phanThuc * sp.phanThuc + this->phanAo * sp.phanAo) / (sp.phanThuc * sp.phanThuc + sp.phanAo * sp.phanAo),
        (this->phanAo * sp.phanThuc - this->phanThuc * sp.phanAo) / (sp.phanThuc * sp.phanThuc + sp.phanAo * sp.phanAo));
}

bool SOPHUC::operator==(const SOPHUC& sp)
{
    return (this->phanThuc == sp.phanThuc) && (this->phanAo == sp.phanAo);
}

bool SOPHUC::operator!=(const SOPHUC& sp)
{
    return !(*this == sp);
}

bool SOPHUC::operator>(const SOPHUC& sp)
{
    double mag1 = sqrt(this->phanThuc * this->phanThuc + this->phanAo * this->phanAo);
    double mag2 = sqrt(sp.phanThuc * sp.phanThuc + sp.phanAo * sp.phanAo);
    return mag1 > mag2;
}

bool SOPHUC::operator<(const SOPHUC& sp)
{
    return !(*this > sp) && (*this != sp);
}

bool SOPHUC::operator>=(const SOPHUC& sp)
{
    return !(*this < sp);
}

bool SOPHUC::operator<=(const SOPHUC& sp)
{
    return !(*this > sp);
}

ostream& operator<<(ostream& os, const SOPHUC& sp)
{
    os << "(" << sp.phanThuc;
    if (sp.phanAo >= 0)
        os << " + " << sp.phanAo << "i)";
    else
        os << sp.phanAo << "i)";
    return os;
}

istream& operator>>(istream& is, SOPHUC& sp)
{
    cout << "Nhap phan thuc: ";
    is >> sp.phanThuc;

    cout << "Nhap phan ao: ";
    is >> sp.phanAo;

    return is;
}
