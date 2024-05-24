#include <iostream>
#include "HocSinh.h"

using namespace std;

int main()
{
    HocSinh hs;
    int Chon;
    do
    {
        cout << "-----------CHUONG TRINH XU LY THONG TIN HOC SINH------------\n";
        cout << "1. Nhap thong tin hoc sinh\n";
        cout << "2. Xuat thong tin hoc sinh\n";
        cout << "3. Tinh Diem trung binh cua hoc sinh\n";
        cout << "4. Xep loai hoc sinh\n";
        cout << "0. Thoat\n";
        cout << "-------------------------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> Chon;
        switch (Chon)
        {
        case 0:
            cout << "Dang thoat chuong trinh.... \n" << endl;
            break;
        case 1:
            cout << "Moi ban nhap thong tin:\n" << endl;
            hs.nhapHocSinh();
            break;
        case 2:
            cout << "Thong tin hoc sinh:\n" << endl;
            hs.xuatHocSinh();
            break;
        case 3:
            cout << "Diem trung binh cua hoc sinh: \n" << hs.tinhDTB() << endl;
            break;
        case 4:
            cout << "Xep loai hoc sinh: \n" << hs.xepLoai() << endl;
            break;
        default:
            cout << "Ban da chon sai. Moi chon lai!";
            break; 
        }
    } while (Chon != 0);
    return 0; 
}
