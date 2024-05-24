#include "CDATE.h"
#include <iostream>
using namespace std;

int main()
{
    CDATE d1, d2;
    int Chon, a = 0;
    do
    {
        cout << "--------------CHUONG TRINH XU LY OVERLOAD NGAY--------------\n";
        cout << "1.Nhap ngay 1: \n";
        cout << "2.Nhap ngay 2: \n";
        cout << "3.Xuat ngay 1: \n";
        cout << "4.Xuat ngay 2: \n";
        cout << "5.Cong ngay 1 voi a ngay\n";
        cout << "6.Cong ngay 2 voi a ngay\n";
        cout << "7.Tru ngay 1 voi a ngay\n";
        cout << "8.Tru ngay 2 voi a ngay\n";
        cout << "9.Tru ngay 1 voi ngay 2\n";
        cout << "0.Thoat chuong trinh\n";
        cout << "------------------------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> Chon;

        switch (Chon)
        {
        case 0:
            cout << "Dang thoat chuong trinh ...\n";
            break;

        case 1:
            cout << "Nhap ngay 1: \n";
            cin >> d1;
            break;

        case 2:
            cout << "Nhap ngay 2: \n";
            cin >> d2;
            break;

        case 3:
            cout << "Ngay 1: " << d1;
            break;
        
        case 4:
            cout << "Ngay 2: " << d2;
            break;
        
        case 5:
            cout << "Nhap a ngay = ";
            cin >> a;
            cout << "Tong ngay 1 voi " << a << " ngay la: " << a + d1;
            break;
 
        case 6:
            cout << "Nhap a ngay = ";
            cin >> a;
            cout << "Tong ngay 2 voi " << a << " ngay la: " << a + d2;
            break;
        
        case 7:
            cout << "Nhap a ngay = ";
            cin >> a;
            cout << "Hieu ngay 1 voi " << a << " ngay la: " << d1 - a;
            break;
        
        case 8:
            cout << "Nhap a ngay = ";
            cin >> a;
            cout << "Hieu ngay 2 voi " << a << " ngay la: " << d2 - a;
            break;
        
        case 9:
            cout << "Hieu 2 ngay la: " << d1 - d2;
            break;
        
        default:
            cout << "Ban nhap sai. Moi ban nhap lai!\n";
            break;
        }
    } while (Chon != 0);
    return 0;
}
