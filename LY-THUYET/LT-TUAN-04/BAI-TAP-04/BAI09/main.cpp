#include"INTEGER.h"

int main() 
{
    INTEGER i1, i2;
    int Chon;

    do
    {
        cout << "------------CHUONG TRINH XU LY OVERLOAD LOP INTEGER---------\n";
        cout << "1. Nhap hai gia tri i\n";
        cout << "2. Xuat hai gia tri i\n";
        cout << "3. Tong hai gia tri i\n";
        cout << "4. Hieu hai gia tri i\n";
        cout << "5. Tich hai gia tri i\n";
        cout << "6. Thuong hai gia tri i\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "------------------------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> Chon;

        switch (Chon)
        {
        case 0: 
            cout << "Dang thoat chuong trinh ...\n";
            break;

        case 1:
            cout << "Nhap hai gia tri i: \n";

            cout << "Nhap so thu nhat: \n";
            cin >> i1;

            cout << "Nhap so thu hai: \n";
            cin >> i2;
            break;

        case 2:
            cout << "Hai gia tri vua nhap la: \n";

            cout << "So thu nhat: " << i1 << endl;
            cout << "So thu hai: " << i2 << endl;
            break;

        case 3:
            cout << "Tong cua hai gia tri i la: " << i1 << " + " << i2 << " = " << (i1 + i2) << endl;
            break;

        case 4:
            cout << "Hieu cua hai gia tri i la: " << i1 << " - " << i2 << " = " << (i1 - i2) << endl;
            break;

        case 5:
            cout << "Tich cua hai gia tri i la: " << i1 << " * " << i2 << " = " << (i1 * i2) << endl;
            break;

        case 6:
            cout << "Thuong cua hai gia tri i la: " << i1 << " / " << i2 << " = " << (i1 / i2) << endl;
            break;

        default:
            cout << "Ban da chon sai. Moi ban chon lai!\n";
            break;
        }
    } while (Chon != 0);
    return 0;
}

