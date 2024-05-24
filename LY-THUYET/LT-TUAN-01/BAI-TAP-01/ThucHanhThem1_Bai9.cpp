// Bài 9: Tính số ngày trong tháng ứng với tháng và năm được nhập vào

#include <iostream>
using namespace std;

struct Date 
{
    int Thang;
    int Nam;
};

int KiemTraSoNgay(const Date &d) 
{
    switch(d.Thang) 
    {
        case 2:
            if ((d.Nam % 4 == 0 && d.Nam % 100 != 0) || (d.Nam % 400 == 0))
                return 29;
            else
                return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void Nhap(Date &d) 
{
    do 
    {
        cout << "Nhap thang: ";
        cin >> d.Thang;
        if (d.Thang >= 1 && d.Thang <= 12) break;
        cout << "Thang khong hop le. Vui long nhap lai." << endl;
    } while (d.Thang < 1 || d.Thang > 12);
    
    cout << "Nhap nam: ";
    cin >> d.Nam;
}

void Xuat(const Date &d) 
{
    cout << "So ngay cua thang " << d.Thang << " nam " << d.Nam << " la: " << KiemTraSoNgay(d) << " ngay" << endl; 
}

int main() {
    Date A;
    Nhap(A);
    Xuat(A);
    return 0;
}
