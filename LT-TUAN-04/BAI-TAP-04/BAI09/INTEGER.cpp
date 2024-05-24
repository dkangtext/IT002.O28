#include"INTEGER.h"

INTEGER::INTEGER() 
{
    i_Value = 0;
}

INTEGER::~INTEGER() 
{
}

INTEGER::INTEGER(int value) 
{
    i_Value = value;
}

void INTEGER::Nhap()
{
    cout << "Nhap gia tri: ";
    cin >> i_Value;
}

void INTEGER::Xuat()
{
    cout << "Gia tri: " << i_Value << endl;
}

INTEGER INTEGER::operator+(const INTEGER i) 
{
    return(this->i_Value + i.i_Value);
}

INTEGER INTEGER::operator-(const INTEGER i) 
{
    return(this->i_Value - i.i_Value);
}

INTEGER INTEGER::operator*(const INTEGER i) 
{
    return(this->i_Value * i.i_Value);
}

INTEGER INTEGER::operator/(const INTEGER i) 
{
    return(this->i_Value / i.i_Value);
}

ostream& operator<<(ostream& os, const INTEGER& i) 
{
    os << i.i_Value;
    return os;
}

istream& operator>>(istream& is, INTEGER& i) 
{
    is >> i.i_Value;
    return is;
}