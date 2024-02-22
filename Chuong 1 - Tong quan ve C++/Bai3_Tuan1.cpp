// Bài 3: Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất kết quả.

// Bước 1: Xác định Input, Output.
    // Input: Tử số, Mẫu số của hai phân số.
    // Output: Tổng, hiệu, tích, thương của hai phân số đã nhập.

// Bước 2: Giải quyết bài toán.

#include <iostream>
using namespace std;

struct PhanSo
{
    int tuSo;
    int mauSo;
};
typedef struct PhanSo PHANSO;

void Nhap(PHANSO&);
void Xuat(PHANSO);
PHANSO RutGon(PHANSO);
PHANSO Tong(PHANSO, PHANSO);
PHANSO Hieu(PHANSO, PHANSO);
PHANSO Tich(PHANSO, PHANSO);
PHANSO Thuong(PHANSO, PHANSO);

int main()
{
    PHANSO a,b,kq;
    cout << "\n Nhap phan so thu 1: ";
    Nhap(a);
    cout << "\n Nhap phan so thu 2: ";
    Nhap(b);

    kq = Tong(a,b);
    cout << "\n Tong hai phan so la (da rut gon): ";
    Xuat(kq);

    kq = Hieu(a,b);
    cout << "\n Hieu hai phan so la (da rut gon): ";
    Xuat(kq);

    kq = Tich(a,b);
    cout << "\n Tich hai phan so la (da rut gon): ";
    Xuat(kq);

    kq = Thuong(a,b);
    cout << "\n Thuong hai phan so la (da rut gon): ";
    Xuat(kq);

    return 0;
}

void Nhap(PHANSO &x)
{
    cout << "\n Nhap tu so: ";
    cin >> x.tuSo;

    do
    {
        cout << "\n Nhap mau so (khac 0): ";
        cin >> x.mauSo;
        if (x.mauSo != 0) 
            break;    
    } while (x.mauSo == 0);   
}

void Xuat(PHANSO x)
{
    if (x.mauSo < -1)
        cout << -x.tuSo << "/" << -x.mauSo;
    else if (x.mauSo == -1)
        cout << -x.tuSo;
    else if (x.mauSo == 0)
        cout << "Khong chia cho so 0";
    else if (x.mauSo == 1)
        cout << x.tuSo;
    else 
        cout << x.tuSo << "/" << x.mauSo;
}

PHANSO RutGon(PHANSO x)
{
    int a = x.tuSo, b = x.mauSo;
    a = abs(a);
    b = abs(b);

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    x.tuSo = x.tuSo / a;
    x.mauSo = x.mauSo / a;
    
    return x;
}
PHANSO Tong(PHANSO x, PHANSO y)
{
    PHANSO temp;
    temp.tuSo = x.tuSo*y.mauSo + y.tuSo*x.mauSo;
    temp.mauSo = x.mauSo*y.mauSo;
    return temp;
}

PHANSO Hieu(PHANSO x, PHANSO y)
{
    PHANSO temp;
    temp.tuSo = x.tuSo*y.mauSo- y.tuSo*x.mauSo;
    temp.mauSo = x.mauSo*y.mauSo;
    return temp;
}

PHANSO Tich(PHANSO x, PHANSO y)
{
    PHANSO temp;
    temp.tuSo = x.tuSo*y.tuSo;
    temp.mauSo = x.mauSo*y.mauSo;
    return temp;
}

PHANSO Thuong(PHANSO x, PHANSO y)
{
    PHANSO temp;
    if (y.tuSo == 0) 
    {
        cout << "\n Khong chia cho so 0"; 
        temp.tuSo = 0;
        temp.mauSo = 1;
    } 
    else 
    {
        temp.tuSo = x.tuSo * y.mauSo;
        temp.mauSo = x.mauSo * y.tuSo;
        temp = RutGon(temp);
    }
    return temp;
}






