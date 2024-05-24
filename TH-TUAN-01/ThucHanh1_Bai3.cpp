// Bài 3: Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất kết quả.

#include <iostream>
using namespace std;

struct PhanSo
{
    int tuSo;
    int mauSo;
};
typedef struct PhanSo PHANSO;

void Nhap(PHANSO &ps)
{
    cout << "\n Nhap tu so: ";
    cin >> ps.tuSo;

    do
    {
        cout << "\n Nhap mau so (khac 0): ";
        cin >> ps.mauSo;
        if (ps.mauSo != 0) 
            break;    
    } while (ps.mauSo == 0);   
}

void Xuat(PHANSO ps)
{
    int a = ps.tuSo, b = ps.mauSo;
    a = abs(a);
    b = abs(b);

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    ps.tuSo = ps.tuSo / a;
    ps.mauSo = ps.mauSo / a;

    if (ps.mauSo < -1)
        cout << -ps.tuSo << "/" << -ps.mauSo;
    else if (ps.mauSo == -1)
        cout << -ps.tuSo;
    else if (ps.mauSo == 0)
        cout << "Khong chia cho so 0";
    else if (ps.mauSo == 1)
        cout << ps.tuSo;
    else 
        cout << ps.tuSo << "/" << ps.mauSo;
}

PHANSO Tong(PHANSO ps1, PHANSO ps2)
{
    PHANSO temp;
    temp.tuSo = ps1.tuSo*ps2.mauSo + ps2.tuSo*ps1.mauSo;
    temp.mauSo = ps1.mauSo*ps2.mauSo;
    return temp;
}

PHANSO Hieu(PHANSO ps1, PHANSO ps2)
{
    PHANSO temp;
    temp.tuSo = ps1.tuSo*ps2.mauSo- ps2.tuSo*ps1.mauSo;
    temp.mauSo = ps1.mauSo*ps2.mauSo;
    return temp;
}

PHANSO Tich(PHANSO ps1, PHANSO ps2)
{
    PHANSO temp;
    temp.tuSo = ps1.tuSo*ps2.tuSo;
    temp.mauSo = ps1.mauSo*ps2.mauSo;
    return temp;
}

PHANSO Thuong(PHANSO ps1, PHANSO ps2)
{
    PHANSO temp;
    if (ps2.tuSo == 0) 
    {
        cout << "\n Khong chia cho so 0"; 
        temp.tuSo = 0;
        temp.mauSo = 1;
    } 
    else 
    {
        temp.tuSo = ps1.tuSo * ps2.mauSo;
        temp.mauSo = ps1.mauSo * ps2.tuSo;
    }
    return temp;
}

int main()
{
    PHANSO a,b,kq;
    cout << "\n Nhap phan so thu 1: ";
    Nhap(a);
    cout << "\n Nhap phan so thu 2: ";
    Nhap(b);

    kq = Tong(a,b);
    cout << "\n Tong hai phan so (sau khi rut gon) la: ";
    Xuat(kq);

    kq = Hieu(a,b);
    cout << "\n Hieu hai phan so (sau khi rut gon) la: ";
    Xuat(kq);

    kq = Tich(a,b);
    cout << "\n Tich hai phan so (sau khi rut gon) la: ";
    Xuat(kq);

    kq = Thuong(a,b);
    cout << "\n Thuong hai phan so (sau khi rut gon) la: ";
    Xuat(kq);

    return 0;
}








