#include "CTIME.h"

int main()
{
    CTIME t1, t2;
    int a, Chon;
    do
    {
        cout << "--------------CHUONG TRINH XU LY THOI GIAN --------------\n";
        cout << "1.Nhap thoi gian 1: \n";
        cout << "2.Nhap thoi gian 2: \n";
        cout << "3.Xuat thoi gian 1: \n";
        cout << "4.Xuat thoi gian 2: \n";
        cout << "5.Cong thoi gian 1 voi a giay\n";
        cout << "6.Cong thoi gian 2 voi a giay\n";
        cout << "7.Tru thoi gian 1 voi a giay\n";
        cout << "8.Tru thoi gian 2 voi a giay\n";
        cout << "9.Tru thoi gian 1 voi thoi gian 2\n";
        cout << "0.Thoat chuong trinh\n";
        cout << "----------------------------------------------------------\n";
        cout << "Moi ban chon: ";

        cin >> Chon;
        
        switch (Chon)
        {
        case 1:
            cout << "Nhap thoi gian 1: \n";
            cin >> t1;
            break;

        case 2:
            cout << "Nhap thoi gian 2: \n";
            cin >> t2;
            break;

        case 3:
            cout << "Thoi gian 1: " << t1;
            break;

        case 4:
            cout << "Thoi gian 2: " << t2;
            break;

        case 5:
            cout << "Nhap a giay = ";
            cin >> a;
            cout << "Tong thoi gian 1 voi " << a << " giay la: " << a + t1;
            break;

        case 6:
            cout << "Nhap a giay = ";
            cin >> a;
            cout << "Tong thoi gian 2 voi " << a << " giay la: " << a + t2;
            break;

        case 7:
            cout << "Nhap a giay = ";
            cin >> a;
            cout << "Hieu thoi gian 1 voi " << a << " giay la: " << t1 - a;
            break;

        case 8:
            cout << "Nhap a giay = ";
            cin >> a;
            cout << "Hieu thoi gian 2 voi " << a << " giay la: " << t2 - a;
            break;

        case 9:
            cout << "Hieu 2 thoi gian la: " << t1 - t2;
            break;
        
        default:
            cout << "Ban da chon sai. Vui long chon lai!\n";
            break;\
        }
    } while (Chon != 0);
    return 0;
}
