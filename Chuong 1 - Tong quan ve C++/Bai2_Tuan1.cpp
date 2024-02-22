// Bài 2: Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.

// Bước 1: Xác định Input, Output.
    // Input: Tử số, Mẫu số của hai phân số.
    // Output: Tử số, Mẫu số của Phân số lớn nhất.

// Bước 2: Giải quyết bài toán.
    // So sánh và đưa ra phân số lớn hơn.

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
int SoSanh(PHANSO, PHANSO);

int main()
{
    PHANSO a,b;
    cout << "\n Nhap phan so thu 1: \n";
    Nhap(a);
    cout << "\n Nhap phan so thu 2: \n";
    Nhap(b);
    int kq = SoSanh(a,b);
    cout << "\n Phan so lon nhat la (da rut gon): ";
    if (kq >= 0)
        Xuat(a);
    else
        Xuat(b); 
    return 1;
}

int SoSanh(PHANSO x, PHANSO y)
{
    float a = (float)x.tuSo/x.mauSo;
    float b = (float)y.tuSo/y.mauSo;
    if(a > b)
        return 1;
    if(a < b)
        return -1;
    return 0;
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

void Nhap(PHANSO &x)
{
    cout << "\n Nhap tu so: ";
    cin >> x.tuSo;
    do
    {
        cout << "\n Nhap mau so (khac 0): ";
        cin >> x.mauSo; 
    } while (x.mauSo == 0);
}