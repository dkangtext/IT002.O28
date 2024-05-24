// Bài 2: Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.

#include <iostream>
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
    cout << "\n Nhap tu so: ";
    cin >> ps.tuSo;
    
    do
    {
        cout << "\n Nhap mau so (khac 0): ";
        cin >> ps.mauSo; 
    } while (ps.mauSo == 0);
}

// Hàm so sánh hai phân số
int SoSanhPhanSo(PHANSO ps1, PHANSO ps2)
{
    float a = (float)ps1.tuSo/ps1.mauSo;
    float b = (float)ps2.tuSo/ps2.mauSo;
    if(a > b)
        return 1;
    if(a < b)
        return -1;
    return 0;
}

// Hàm rút gọn phân số và hiển thị kết quả
void XuatKetqua(PHANSO ps)
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

    // Rút gọn Phân số
    ps.tuSo = ps.tuSo / USCLN;
    ps.mauSo = ps.mauSo / USCLN;

    // Kết xuất Phân số tối giản
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
    PHANSO a,b;
    cout << "\n Nhap phan so thu 1: \n";
    NhapPhanSo(a);
    cout << "\n Phan so thu 1 sau khi rut gon la: ";
    XuatKetqua(a);
    cout << "\n\n";

    cout << "\n Nhap phan so thu 2: \n";
    NhapPhanSo(b);
    cout << "\n Phan so thu 2 sau khi rut gon la: ";
    XuatKetqua(b);
    cout << "\n\n";
    
    int kq = SoSanhPhanSo(a,b);
    if (kq > 0)
        {
        cout << "\n Phan so lon nhat la: ";
        XuatKetqua(a);
        }
    else if (kq < 0)
        {
        cout << "\n Phan so lon nhat la: ";
        XuatKetqua(b);
        }
    else    
        cout << "\n Hai phan so bang nhau. ";
    return 0;
}

