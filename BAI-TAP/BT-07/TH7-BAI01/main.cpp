#include "CONGTY.h"

int main()
{
	CONGTY tr;
	int Chon;
	do
	{
		cout << "------CHUONG TRINH QUAN LY DOI TUONG NHAN VIEN CUA CONG TY------\n";
        cout << "1. Nhap d/s DTNV\n";
        cout << "2. Xuat d/s DTNV\n";
        cout << "3. Liet ke cac NVBC co he so luong tu 3.5 tro len\n";
        cout << "4. Dem so luong NVHD co so ngay cong la 26\n";
        cout << "5. Tinh tong tien luong da tra cho cac NV phong ke toan\n";
        cout << "6. Tinh tien luong TB cua cac NVBC.\n";
        cout << "7. Kiem tra cong ty co NVHD khong di lam ngay nao khong\n";
        cout << "8. Tim cac NVBC co he so luong cao nhat\n";
        cout << "9. Sap xep d/s NV tang dan theo ma so\n";
        cout << "10. Them 1 NV moi.\n";
        cout << "11. Xoa 1 NV co ma so do nguoi dung nhap vao\n";
        cout << "12. Tim kiem NV theo thong tin ma nguoi dung cung cap\n";
        cout << "0. Thoat Chuong trinh\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Moi ban chon: ";
        cin >> Chon;

        switch (Chon)
        {
        case 0:
            if (tr.GetSoLuong() > 0)
                tr.~CONGTY();
            cout << "Dang thoat chuong trinh...";
            break;

        case 1:
                tr.Nhap();
            break;

        case 2:
            if (tr.GetSoLuong() > 0)
                tr.Xuat();
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 3:
            if (tr.GetSoLuong() > 0)
                tr.LietKeNhanVienCoHeSoLuongTu35TroLen();
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 4:
            if (tr.GetSoLuong() > 0)
            {
                int Dem = tr.DemNhanVienHopDongCoSoNgayCongLa26();

                if (Dem == 26)
                    cout << "Co " << Dem << " Nhan vien Hop dong co so nga cong la 26\n";
                else
                    cout << "Khong co Nhan vien Hop dong co so ngay cong la 26\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 5:
            if (tr.GetSoLuong() > 0)
            {
                int TongTien = tr.TinhTongTienLuongNhanVienPhongKeToan();

                if (TongTien > 0)
                    cout << "Tong tien luong Nhan vien phong Ke toan la: " << TongTien << endl;
                else
                    cout << "Khong co Nhan vien Ke toan nao co luong\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 6:
            if (tr.GetSoLuong() > 0)
            {
                double LuongTrungBinh = tr.TinhTienLuongTrungBinhCuaNhanVienBienChe();

                if (LuongTrungBinh > 0)
                    cout << "Tong tien luong Trung binh cua cac Nhan vien Bien che la: " << LuongTrungBinh << endl;
                else
                    cout << "Tat ca Nhan vien Bien che chua co thong tin luong" << endl;
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 7:
            if (tr.GetSoLuong() > 0)
            {
                if (tr.KiemTraCongTyCoNhanVienHopDongKhongDiLamNgayNaoKhong())
                    cout << "Cong ty co Nhan vien Hop dong khong di lam ngay nao ca\n";
                else
                    cout << "Cong ty khong co Nhan vien Hop dong khong di lam ngay nao ca\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 8:
            if (tr.GetSoLuong() > 0)
                tr.TimCacNhanVienBienCheCoHeSoLuongCaoNhat();
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 9:
            if (tr.GetSoLuong() > 0)
            {
                tr.SapXepDanhSachNhanVienTangDanTheoMaSo();
                tr.Xuat();
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 10:
            NHANVIEN * PDT;
            int VT;
            VT = 1;
            PDT = tr.Nhap1();

            if (tr.GetSoLuong() > 0)
            {
                do
                {
                    cout << "Nhap vi tri muon them DTNV tu 1 den " << tr.GetSoLuong() + 1 << ": ";
                    cin >> VT;
                } while (VT < 1 || VT > tr.GetSoLuong() + 1);
            }

            tr.Them(PDT, VT);
            cout << "D/s DTNV sau khi them DTNV moi tai vi tri thu " << VT << " la: \n";
            tr.Xuat();
            break;

        case 11:
            if (tr.GetSoLuong() > 0)
            {
                string MS;
                cout << "Nhap ma so DTNV muon xoa: ";
                cin >> MS;

                int KetQua = tr.Xoa(MS);
                if (KetQua != -1)
                {
                    if (tr.GetSoLuong() > 0)
                    {
                        cout << "D/s DTNV sau khi xoa DTNV co ma so " << MS << " la: ";
                        tr.Xuat();
                    }
                    else
                        cout << "D/s DTNV rong \n";
                }
            }
            else
                cout << "Chua nhap thong tin\n";
            break;

        case 12:
            if (tr.GetSoLuong() > 0)
            {
                int ChonSoLuong;
                do
                {
                    cout << "THONG TIN CAN TRUY VAN";
                    cout << "1.MaSo" << endl;
                    cout << "2.HoTen" << endl;
                    cout << "3.PhongBan" << endl;
                    cout << "4.HeSoLuong" << endl;
                    cout << "5.HeSoPhuCap" << endl;
                    cout << "6.TienCong" << endl;
                    cout << "7.SoNgayCong" << endl;
                    cout << "8.HeSoVuotGio" << endl;
                    cin >> ChonSoLuong;
                    if (ChonSoLuong < 1 || ChonSoLuong > 8)
                        cout << "Thong tin nhap khong hop le. Vui long nhap lai!" << endl;
                } while (ChonSoLuong < 1 || ChonSoLuong > 8);

                if (ChonSoLuong == 1)
                {
                    string MS;
                    cin.ignore();
                    cout << "Nhap ma so can tim: ";
                    getline(cin, MS);
                    tr.TimKiemNhanVienTheoThongTinChung(MS);
                    break;
                }
                else if (ChonSoLuong == 2)
                {
                    string HT;
                    cin.ignore();
                    cout << "Nhap ho ten can tim: ";
                    getline(cin, HT);
                    tr.TimKiemNhanVienTheoThongTinChung("-100000", HT);
                    break;
                }
                else if (ChonSoLuong == 3)
                {
                    string PB;
                    cin.ignore();
                    cout << "Nhap phong ban can tim: ";
                    getline(cin, PB);
                    tr.TimKiemNhanVienTheoThongTinChung("-100000", "-100000", PB);
                }
                else if (ChonSoLuong == 4)
                {
                    double HSL;
                    cout << "Nhap he so luong can tim: ";
                    cin >> HSL;
                    tr.TimKiemNhanVienTheoThongTinChung("-100000", "-100000", "-100000", HSL);
                }
                else if (ChonSoLuong == 5)
                {
                    double HSPCCV;
                    cout << "Nhap he so phu cap chuc vu can tim: ";
                    cin >> HSPCCV;
                    tr.TimKiemNhanVienTheoThongTinChung("-100000", "-100000", "-100000", -100000, HSPCCV);
                }
                else if (ChonSoLuong == 6)
                {
                    long TC;
                    cout << "Nhap tien cong can tim: ";
                    cin >> TC;
                    tr.TimKiemNhanVienTheoThongTinChung("-100000", "-100000", "-100000", -100000, -100000, TC);
                }
                else if (ChonSoLuong == 7)
                {
                    int SNC;
                    cout << "Nhap so ngay cong can tim: ";
                    cin >> SNC;
                    tr.TimKiemNhanVienTheoThongTinChung("-100000", "-100000", "-100000", -100000, -100000, -100000, SNC);
                }
                else if (ChonSoLuong == 8)
                {
                    double HSVG;
                    cout << "Nhap ma so can tim: ";
                    cin >> HSVG;
                    tr.TimKiemNhanVienTheoThongTinChung("-100000", "-100000", "-100000", -100000, -100000, -100000, -100000, HSVG);
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
