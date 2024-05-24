#include <iostream>
#include "CONGTY.h"
using namespace std;

int main() {
    CONGTY congTy;
    int Chon;
    string tenFile, maNhanVien;

    do
    {
        cout << "=============================CHUONG TRINH XU LY================================\n";
        cout << "1. Nhap danh sach nhan vien\n";
        cout << "2. Xuat danh sach nhan vien\n";
        cout << "3. Liet ke danh sach lap trinh vien co luong thap hon muc luong trung binh\n";
        cout << "4. Kiem tra kiem chung vien phat hien duoi 5 loi\n";
        cout << "5. Cap nhat thong tin nhan vien\n";
        cout << "6. Xoa toan bo danh sach nhan vien\n";
        cout << "7. Doc danh sach nhan vien tu file\n";
        cout << "8. Luu danh sach nhan vien vao file\n";
        cout << "0. Thoat\n";
        cout << "===============================================================================\n";
        cout << "Chuong trinh da san sang. Moi ban chon: ";
        cin >> Chon;
        cout << endl;

        switch (Chon)
        {
        case 0:
            cout << "Thoat chuong trinh...\n";
            break;

        case 1:
            congTy.nhapDanhSachNhanVien();
            cout << endl;
            break;
        
        case 2:
            congTy.xuatDanhSachNhanVien();
            cout << endl;
            break;
        
        case 3:
            congTy.LietKeDanhSachLapTrinhVienCoLuongThapHonMucLuongTrungBinh();
            cout << endl;
            break;
        
        case 4:
            congTy.KiemTraCoKiemChungVienNaoChiPhatHienDuocDuoi5LoiKhong();
            cout << endl;
            break;
        
        case 5:
            cout << "Nhap ma nhan vien can cap nhat: ";
            cin >> ws;
            getline(cin, maNhanVien);
            congTy.CapNhatThongTinNhanVien(maNhanVien);
            cout << endl;
            break;
        
        case 6:
            congTy.XoaDanhSachNhanVien();
            cout << endl;
            break;
        
        case 7:
            cout << "Nhap ten file de doc: ";
            cin >> tenFile;
            congTy.DocFile(tenFile);
            cout << endl;
            break;
        
        case 8:
            cout << "Nhap ten file de luu: ";
            cin >> tenFile;
            congTy.LuuFile(tenFile);
            cout << endl;
            break;
        
        default:
            cout << "Ban da chon sai. Vui long chon lai!\n";
            break;
        }
    } while (Chon != 0);
    return 0;
}