#include "PHANSO.h"
#include <iostream>

using namespace std;

int PHANSO::Dem = 0;

PHANSO::PHANSO() : tuSo(0), mauSo(1) 
{
    Dem++;
}

PHANSO::PHANSO(int tuSo) : tuSo(tuSo), mauSo(1) 
{
    Dem++;
}

PHANSO::PHANSO(int tuSo, int mauSo) : tuSo(tuSo), mauSo(mauSo) 
{
    Dem++;
}

PHANSO::~PHANSO()
{
    Dem--;
}

int PHANSO::GetTuSo() const
{
    return tuSo;
}

int PHANSO::GetMauSo() const
{
    return mauSo;
}

int PHANSO::GetDem()
{
    return Dem;
}

void PHANSO::SetTuSo(int tuSo)
{
    this->tuSo = tuSo;
}

void PHANSO::SetMauSo(int mauSo)
{
    this->mauSo = mauSo;
}

void PHANSO::SetPhanSo(int tuSo, int mauSo)
{
    SetTuSo(tuSo);
    SetMauSo(mauSo);
}

void PHANSO::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> tuSo;

    do
    {
        cout << "Nhap mau so (khac 0): ";
        cin >> mauSo;
    } while (mauSo == 0);
}

int PHANSO::TimUSCLN(int a, int b)
{
    int USCLN = 1;

    a = abs(a);
    b = abs(b);

    if (a == 0 && b == 0)
        USCLN = 1;
    else if (a == 0 || b == 0)
        USCLN = a + b;
    else
    {
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        USCLN = a;
    }
    return USCLN;
}

void PHANSO::RutGon()
{
    int USCLN = TimUSCLN(tuSo, mauSo);
    tuSo = tuSo / USCLN;
    mauSo = mauSo / USCLN;
}

void PHANSO::Xuat() const
{
    if (mauSo < -1)
        cout << -tuSo << "/" << -mauSo;
    else if (mauSo == -1)
        cout << -tuSo;
    else if (mauSo == 0)
        cout << "Khong chia cho so 0";
    else if (mauSo == 1)
        cout << tuSo;
    else
        cout << tuSo << "/" << mauSo;
}

PHANSO PHANSO::Cong(const PHANSO& ps)
{
    /*
        PHANSO Tong;
        Tong.tuSo = tuSo * ps.mauSo + ps.tuSo * mauSo;
        Tong.mauSo = mauSo * ps.mauSo;
        return Tong;
    */
    return PHANSO(tuSo * ps.mauSo + ps.tuSo * mauSo, mauSo * ps.mauSo);
}

/* 
    PHANSO PHANSO::operator+(const PHANSO& ps)
    {
        return PHANSO(tuSo * ps.mauSo + ps.tuSo * mauSo, mauSo * ps.mauSo);
    }
*/

PHANSO operator+(const PHANSO& ps1, const PHANSO& ps2)
{
    return PHANSO(ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo, ps1.mauSo * ps2.mauSo);
}


