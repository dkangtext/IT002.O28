#include<iostream>
#include"DATHUC.h"
#include<cmath>
using namespace std;

DATHUC::DATHUC()
{
    this->NumberOfElement = 0;
    this->x = new double[0 + 1];
    for (int i = 0; i <= this->NumberOfElement; i++)
    {
        this->x[i] = 0;
    }
}

DATHUC::DATHUC(int n)
{
    this->NumberOfElement = n;
    this->x = new double[NumberOfElement + 1];
    for (int i = 0; i <= this->NumberOfElement; i++)
    {
        this->x[i] = 0;
    }
}
DATHUC::DATHUC(const DATHUC& DT)
{
    this->NumberOfElement = DT.NumberOfElement;
    delete[] this->x;
    this->x = new double[NumberOfElement + 1];
    for (int i = 0; i <= this->NumberOfElement; i++)
    {
        this->x[i] = DT.x[i];
    }
}
DATHUC& DATHUC::operator=(const DATHUC& DT)
{
    if (&DT == this)
    {
        return *this;
    }
    this->NumberOfElement = DT.NumberOfElement;
    delete[] this->x;
    this->x = new double[NumberOfElement + 1];
    for (int i = 0; i <= this->NumberOfElement; i++)
    {
        this->x[i] = DT.x[i];
    }
    return *this;
}
DATHUC operator+(const DATHUC& DT1, const DATHUC& DT2)
{
    DATHUC DT((DT1.NumberOfElement > DT2.NumberOfElement) ? DT1.NumberOfElement : DT2.NumberOfElement);
    for (int i = 0; i <= DT.NumberOfElement; i++)
    {
        if (i <= DT1.NumberOfElement && i <= DT2.NumberOfElement)
        {
            DT.x[i] = DT1.x[i] + DT2.x[i];
        }
        else
        {
            if (i > DT1.NumberOfElement)
            {
                DT.x[i] = DT2.x[i];
            }
            else if (i > DT2.NumberOfElement)
            {
                DT.x[i] = DT1.x[i];
            }
            else {}
        }
    }
    return DT;
}
DATHUC operator-(const DATHUC& DT1, const DATHUC& DT2)
{
    DATHUC DT((DT1.NumberOfElement > DT2.NumberOfElement) ? DT1.NumberOfElement : DT2.NumberOfElement);
    for (int i = 0; i <= DT.NumberOfElement; i++)
    {
        if (i <= DT1.NumberOfElement && i <= DT2.NumberOfElement)
        {
            DT.x[i] = DT1.x[i] - DT2.x[i];
        }
        else
        {
            if (i > DT1.NumberOfElement)
            {
                DT.x[i] = -DT2.x[i];
            }
            else if (i > DT2.NumberOfElement)
            {
                DT.x[i] = DT1.x[i];
            }
            else {}
        }
    }
    return DT;
}
DATHUC operator*(const DATHUC& DT1, const DATHUC& DT2)
{
    DATHUC DT(DT1.NumberOfElement + DT2.NumberOfElement);
    for (int i = 0; i <= DT1.NumberOfElement; i++)
    {
        for (int j = 0; j <= DT2.NumberOfElement; j++)
        {
            DT.x[i + j] += DT1.x[i] * DT2.x[j];
        }
    }
    return DT;
}

ostream& operator<<(ostream& os, const DATHUC& DT)
{
    bool isFirstTerm = true; // Biến để kiểm tra xem đây có phải là mục đầu tiên không
    for (int i = DT.getNumberOfElement(); i >= 0; i--)
    {
        if (DT.getX(i) != 0)
        {
            if (!isFirstTerm && DT.getX(i) > 0) // Kiểm tra nếu không phải là mục đầu tiên và hệ số dương
            {
                os << " + ";
            }
            isFirstTerm = false; // Đặt isFirstTerm = false sau khi đã kiểm tra mục đầu tiên

            if (DT.getX(i) < 0)
            {
                os << " - ";
            }
            if (abs(DT.getX(i)) != 1 || i == 0) // Kiểm tra nếu hệ số khác 1 hoặc là hằng số
            {
                os << abs(DT.getX(i));
            }
            if (i == 1)
            {
                os << "X";
            }
            else if (i > 1)
            {
                os << "X^" << i;
            }
        }
    }
    return os;
}


istream& operator>>(istream& is, DATHUC& DT)
{
    delete[] DT.x;
    cout << "Nhap so mu toi da: ";
    is >> DT.NumberOfElement;
    cout << "Gia tri dau vao cua moi cach tiep can so mu tu cao den thap: ";
    DT.x = new double[DT.NumberOfElement + 1];
    for (int i = DT.NumberOfElement; i >= 0; i--)
    {
        is >> DT.x[i];
    }
    return is;
}
DATHUC::~DATHUC()
{
    delete[] this->x;
}

bool DATHUC::PreAllZero(int k)
{
    for (int i = NumberOfElement; i >= 0; i--)
    {
        if (i > k && x[i] != 0) {
            return false;
        }
    }
    return true;
}

