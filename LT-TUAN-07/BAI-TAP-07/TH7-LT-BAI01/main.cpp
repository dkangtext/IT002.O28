#include "NHANVIEN.h"
#include "NHANVIENSANXUAT.h"
#include "NHANVIENVANPHONG.h"
#include "QUANLYNHANVIEN.h"

int main()
{
    QUANLYNHANVIEN qlnv;
    int Chon;

    do {
        cout << "---CHUONG TRINH QUAN LY NHAN VIEN---\n";
        cout << "1. Nhap thong tin nhan vien\n";
        cout << "2. Xuat thong tin nhan vien va tinh luong\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "-------------------------------------\n";
        cout << "Chuong trinh da san sang. Moi ban chon: ";
        cin >> Chon;

        switch (Chon) 
        {
        case 0:
            cout << "Dang thoat chuong trinh...\n";
            break;

        case 1:
            qlnv.Nhap();
            break;
        
        case 2:
            qlnv.Xuat();
            break;
        
        default:
            cout << "Ban da chon sai. Vui long chon lai!\n";
            break;
        }
    } while (Chon != 0);

    return 0;
}