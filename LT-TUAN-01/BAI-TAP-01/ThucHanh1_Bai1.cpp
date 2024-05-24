// Bài 1: Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.

#include <iostream>
#include <cmath> // Thư viện để sử dụng hàm abs()
using namespace std;

// Khai báo cấu trúc PhanSo
struct PhanSo 
{
    int tuSo;
    int mauSo;
};
typedef struct PhanSo PHANSO;

// Định nghĩa hàm nhập phân số
void NhapPhanSo(PHANSO &ps)
{
    cout << "Nhap tu so: ";
    cin >> ps.tuSo;

    do 
    {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mauSo;
        if (ps.mauSo != 0) break;    
    } while (ps.mauSo == 0); 
}

// Hàm rút gọn phân số và hiển thị kết quả
void RutGonvaXuat(PHANSO &ps)
{
    // Tìm ước số chung lớn nhất
    int USCLN = 1, a = ps.tuSo, b = ps.mauSo;
    a = abs(a); // |a|: absolute
    b = abs(b); // |b|: absolute

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
        USCLN = a; // USCLN = b;
    }

    // Rút gọn phân số
    ps.tuSo = ps.tuSo / USCLN;
    ps.mauSo = ps.mauSo / USCLN;

    // Xuất kết quả
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

int main()
{
    PHANSO phanSo;
    cout << "Nhap phan so: \n";
    NhapPhanSo(phanSo);
    cout << "Phan so sau khi rut gon la: ";
    RutGonvaXuat(phanSo);
    return 0;
}