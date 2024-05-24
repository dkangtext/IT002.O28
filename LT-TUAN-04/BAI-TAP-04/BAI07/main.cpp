#include<iostream>
#include"DATHUC.h"
using namespace std;

int main()
{
    DATHUC DT1, DT2;
    int Chon;
    DATHUC CongDT, TruDT, NhanDT;

    do
    {
        cout << "--------CHUONG TRINH XU LY DA THUC--------\n";
        cout << "1. Nhap hai da thuc \n";
        cout << "2. Xuat hai da thuc \n";
        cout << "3. Cong hai da thuc \n";
        cout << "4. Tru hai da thuc \n";
        cout << "5. Nhan hai da thuc \n";
        cout << "0. Thoat chuong trinh \n";
        cout << "------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> Chon;

        switch (Chon)
        {
        case 0:
            cout << "Dang thoat chuong trinh ...\n";
            break;

        case 1:
            cout << "Nhap hai da thuc \n";

            cout << "Nhap da thuc DT1: \n";
            cin >> DT1;

            cout << "Nhap da thuc DT2: \n";
            cin >> DT2;
            break;

        case 2:
            cout << "Da thuc DT1: " << DT1 << endl;
            cout << "Da thuc DT2: " << DT2 << endl;
            break;

        case 3:
            CongDT = DT1 + DT2;
            cout << "Tong cua hai da thuc la: ";
            cout << CongDT;
            cout << endl;
            break;

        case 4:
            TruDT = DT1 - DT2;
            cout << "Hieu cua hai da thuc la: ";
            cout << TruDT;
            cout << endl;
            break;

        case 5:
            NhanDT = DT1 * DT2;
            cout << "Tich cua hai da thuc la: ";
            cout << NhanDT;
            cout << endl;
            break;

        default:
            cout << "Ban da nhap sai. Moi nhap lai: \n";
            break;
        }
    } while (Chon != 0);
    return 0;
}