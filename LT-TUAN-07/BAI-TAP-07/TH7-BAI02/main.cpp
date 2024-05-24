#include "SINHVIEN.h"
#include "SINHVIENCHINHQUY.h"
#include "SINHVIENLIENTHONG.h"
#include "TRUONGDAIHOC.h"

int main()
{
    TRUONGDAIHOC tr;
    int Chon;
    do
    {
        cout << "------CHUONG TRINH QUAN LY DOI TUONG SINH VIEN CUA TRUONG DAI HOC------\n";
        cout << "1. Nhap d/s DTSV\n";
        cout << "2. Xuat d/s DTSV\n";
        cout << "3. Liet ke cac SVCQ co DRL la 100\n";
        cout << "4. Dem so luong SVLT khong nghi buoi nao\n";
        cout << "5. Tinh tong tien hoc bong cap cho cac SV\n";
        cout << "6. Tinh DTB cua SVCQ duoc cap hoc bong\n";
        cout << "7. Kiem tra truong co SVLT co DTB tu 9 tro len va khong nghi buoi nao khong\n";
        cout << "8. Tim cac SVCQ co DTB cao nhat\n";
        cout << "9. Sap xep d/s SV tang dan theo ma so\n";
        cout << "10. Them 1 SV moi.\n";
        cout << "11. Xoa 1 SV co ma so do nguoi dung nhap vao\n";
        cout << "12. Tim kiem NV theo thong tin ma nguoi dung cung cap\n";
        cout << "0. Thoat Chuong trinh\n";
        cout << "-----------------------------------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> Chon;

        switch (Chon)
        {
        case 0:
            if (tr.getSoLuong() > 0)
                tr.~TRUONGDAIHOC();
            cout << "Dang thoat chuong trinh...";
            break;

        case 1:
            tr.Nhap();
            break;

        case 2:
            if (tr.getSoLuong() > 0)
                tr.Xuat();
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 3:
            if (tr.getSoLuong() > 0)
                tr.LietKeCacSinhVienChinhQuyCoDiemRenLuyenLa100();
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 4:
            if (tr.getSoLuong() > 0)
            {
                int Dem = tr.DemSoLuongSinhVienLienThongKhongNghiBuoiNao();

                if (Dem > 0)
                    cout << "Co " << Dem << " Sinh vien Lien thong khong nghi buoi nao\n";
                else
                    cout << "Khong co Sinh vien Lien thong khong nghi buoi nao\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 5:
            if (tr.getSoLuong() > 0)
            {
                int TongTien = tr.TinhTongHocBongCapChoCacSinhVien();

                if (TongTien > 0)
                    cout << "Tong tien hoc bong cho cac Sinh vien la: " << TongTien << endl;
                else
                    cout << "Khong co Sinh vien nao co hoc bong\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 6:
            if (tr.getSoLuong() > 0)
            {
                double DiemTrungBinh = tr.TinhDiemTrungBinhCuaCacSinhVienChinhQuyDuocCapHocBong();

                if (DiemTrungBinh > 0)
                    cout << "Diem trung binh cua cac Sinh vien Chinh quy duoc cap hoc bong la: " << DiemTrungBinh << endl;
                else
                    cout << "Khong co thong tin Diem trung binh cua cac Sinh vien Chinh quy duoc cap hoc bong" << endl;
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 7:
            if (tr.getSoLuong() > 0)
            {
                if (tr.KiemTraTruongCoSinhVienLienThongCoDiemTrungBinhTu9TroLenVaKhongNghiBuoiNaoKhong())
                    cout << "Truong co Sinh vien Lien Thong co DTB tu 0 tro len va khong nghi buoi nao ca\n";
                else
                    cout << "Truong khong co Sinh vien Lien Thong nao co DTB tu 0 tro len va khong nghi buoi nao ca\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 8:
            if (tr.getSoLuong() > 0)
                tr.TimCacSinhVienChinhQuyCoDiemTrungBinhCaoNhat();
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 9:
            if (tr.getSoLuong() > 0)
            {
                tr.SapXepSinhVienTangDanTheoMaSo();
                tr.Xuat();
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 10:
            SINHVIEN * PDT;
            int VT;
            VT = 1;
            PDT = tr.Nhap1();

            if (tr.getSoLuong() > 0)
            {
                do
                {
                    cout << "Nhap vi tri muon them DTSV tu 1 den " << tr.getSoLuong() + 1 << ": ";
                    cin >> VT;
                } while (VT < 1 || VT > tr.getSoLuong() + 1);
            }

            tr.Them(PDT, VT);
            cout << "D/s DTSV sau khi them DTSV moi tai vi tri thu " << VT << " la: \n";
            tr.Xuat();
            break;

        case 11:
            if (tr.getSoLuong() > 0)
            {
                string MS;
                cout << "Nhap ma so DTSV muon xoa: ";
                cin >> MS;

                int KetQua = tr.Xoa(MS);
                if (KetQua != -1)
                {
                    if (tr.getSoLuong() > 0)
                    {
                        cout << "D/s DTSV sau khi xoa DTSV co ma so " << MS << " la: ";
                        tr.Xuat();
                    }
                    else
                        cout << "D/s DTSV rong \n";
                }
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 12:
            if (tr.getSoLuong() > 0)
            {
                int ChonSoLuong;
                do
                {
                    cout << "THONG TIN CAN TRUY VAN";
                    cout << "1.MaSo" << endl;
                    cout << "2.HoTen" << endl;
                    cout << "3.PhongBan" << endl;
                    cout << "4.DiemTrungBinh" << endl;
                    cout << "5.DiemRenLuyen" << endl;
                    cout << "6.SoBuoiVang" << endl;
                    cin >> ChonSoLuong;
                    if (ChonSoLuong < 1 || ChonSoLuong > 6)
                        cout << "Thong tin nhap khong hop le. Vui long nhap lai!" << endl;
                } while (ChonSoLuong < 1 || ChonSoLuong > 6);

                if (ChonSoLuong == 1)
                {
                    string MS;
                    cin.ignore();
                    cout << "Nhap ma so can tim: ";
                    getline(cin, MS);
                    tr.TimKiemSinhVienTheoThongTinChung(MS);
                    break;
                }
                else if (ChonSoLuong == 2)
                {
                    string HT;
                    cin.ignore();
                    cout << "Nhap ho ten can tim: ";
                    getline(cin, HT);
                    tr.TimKiemSinhVienTheoThongTinChung("-100000", HT);
                    break;
                }
                else if (ChonSoLuong == 3)
                {
                    string KHOA;
                    cin.ignore();
                    cout << "Nhap khoa can tim: ";
                    getline(cin, KHOA);
                    tr.TimKiemSinhVienTheoThongTinChung("-100000", "-100000", KHOA);
                }
                else if (ChonSoLuong == 4)
                {
                    double DTB;
                    cout << "Nhap diem trung binh can tim: ";
                    cin >> DTB;
                    tr.TimKiemSinhVienTheoThongTinChung("-100000", "-100000", "-100000", DTB);
                }
                else if (ChonSoLuong == 5)
                {
                    double DRL;
                    cout << "Nhap diem ren luyen can tim: ";
                    cin >> DRL;
                    tr.TimKiemSinhVienTheoThongTinChung("-100000", "-100000", "-100000", -100000, DRL);
                }
                else if (ChonSoLuong == 6)
                {
                    long SBV;
                    cout << "Nhap so buoi vang can tim: ";
                    cin >> SBV;
                    tr.TimKiemSinhVienTheoThongTinChung("-100000", "-100000", "-100000", -100000, -100000, SBV);
                }
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        default:
            cout << "Ban da nhap sai. Vui long nhap lai!";
            break;
        }
    } while (Chon != 0);
    return 0;
}