#include <iostream>
#include "TamGiac.h"

using namespace std;

int main()
{
    TamGiac tg;
    int Chon;
    do
    {
        cout << "--------CHUONG TRINH XU LY TAM GIAC---------\n";
        cout << "1. Nhap tam giac \n";
        cout << "2. Xuat tam giac \n";
        cout << "3. Kiem tra 3 canh tam giac hop le khong? \n";
        cout << "4. Phan loai tam giac \n";
        cout << "5. Tinh chu vi tam giac \n";
        cout << "6. Tinh dien tich tam giac \n";
        cout << "0. Thoat \n";
        cout << "--------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> Chon;
        switch (Chon)
        {
        case 0:
            cout << "Dang thoat chuong trinh... \n";
            break;
        case 1:
            cout << "Nhap do dai 3 canh cua tam giac \n";
            tg.nhapTamGiac();
            break;
        case 2:
            tg.xuatTamGiac();
            cout << endl;
            break;
        case 3:
            if (tg.kiemTraHopLe())
                cout << "Hop le!" << endl;
            else
                cout << "Khong hop le!" << endl;
            break;
        case 4:
            tg.phanLoai();
            cout << endl;
            break;
        case 5:
            cout << "Chu vi cua tam giac la: " << tg.tinhChuVi() << endl;
            break;
        case 6:
            cout << "Dien tich cua tam giac la: " << tg.tinhDienTich() << endl;
            break;
        default:
            cout << "Ban chon sai.Moi ban chon lai! \n";
            break;
        }
    } while (Chon != 0);
}
