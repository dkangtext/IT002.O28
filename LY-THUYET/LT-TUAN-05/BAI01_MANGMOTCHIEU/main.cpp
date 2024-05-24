#include "MANG1C.h"

int main()
{
	MANG1C M1C;
	int Chon;
	do
	{
		cout << "-----------------CHUONG TRINH XU LY MANG MOT CHIEU---------------\n";
		cout << "1. Nhap Mang-----------------------------------------------------\n";
		cout << "2. Phat sinh Mang------------------------------------------------\n";
		cout << "3. Xuat Mang-----------------------------------------------------\n";
		cout << "4. Liet ke cac phan tu la So Nguyen to---------------------------\n";
		cout << "5. Dem so luong cac phan tu la So Chinh phuong-------------------\n";
		cout << "6. Tinh tong gia tri cac phan tu la So Hoan thien----------------\n";
		cout << "7. Tinh Trung binh cong gia tri cac phan tu la So Doi xung-------\n";
		cout << "8. Kiem trang mang toan phan tu le-------------------------------\n";
		cout << "9. Tim phan tu chan be nhat--------------------------------------\n";
		cout << "10. Sap xep mang tang dan----------------------------------------\n";
		cout << "11. Xoa phan tu tai vi tri---------------------------------------\n";
		cout << "12. Them phan tu tai vi tri--------------------------------------\n";
		cout << "13. Xoa Mang-----------------------------------------------------\n";
		cout << "14. Tim kiem tuyen tinh------------------------------------------\n";
		cout << "15. Tim kiem nhi phan--------------------------------------------\n";
		cout << "0. Thoat chuong trinh--------------------------------------------\n";
		cout << "-----------------------------------------------------------------\n";
		cout << "Chuong trinh da san sang! Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh...\n";
			break;

		case 1:
			cin >> M1C;
			break;

		case 2:
			M1C.PhatSinh();
			break;

		case 3:
			cout << M1C;
			break;

		case 4:
			if (M1C.GetN() > 0)
				M1C.LietKeSoNguyenTo();
			else
				cout << "Mang rong.\n";
			break;

		case 5:
		{
			if (M1C.GetN() > 0)
			{
				int DemSoChinhPhuong = M1C.DemSoChinhPhuong();
				if (DemSoChinhPhuong > 0)
					cout << "Co " << DemSoChinhPhuong << " phan tu la So Chinh phuong trong mang.\n";
				else
					cout << "Mang khong co phan tu la So Chinh phuong.\n";
			}
			else
				cout << "Mang rong.\n";
		}
		break;

		case 6:
		{
			if (M1C.GetN() > 0)
			{
				int TongSoHoanThien = M1C.TinhTongSoHoanThien();
				if (TongSoHoanThien > 0)
					cout << "Tong gia tri cac phan tu la So Hoan thien trong mang la: " << TongSoHoanThien << endl;
				else
					cout << "Mang khong co phan tu la So Hoan thien.\n";
			}
			else
				cout << "Mang rong\n";
		}
		break;

		case 7:
		{
			if (M1C.GetN() > 0)
			{
				double TrungBinhCongSoDoiXung = M1C.TinhTrungBinhCongSoDoiXung();
				if (TrungBinhCongSoDoiXung > 0)
					cout << "Trung binh cong gia tri cac phan tu la So Doi xung trong mang la: "
					<< setprecision(6) << fixed << TrungBinhCongSoDoiXung << endl;
				else
					cout << "Mang khong co phan tu la So Doi xung.\n";
			}
			else
				cout << "Mang rong.\n";
		}
		break;

		case 8:
			if (M1C.GetN() > 0)
			{
				if (M1C.KiemTraMangLe())
					cout << "Mang toan phan tu le.\n";
				else
					cout << "Mang co chua phan tu chan.\n";
			}
			else
				cout << "Mang rong.\n";
			break;

		case 9:
			if (M1C.GetN() > 0)
				M1C.TimChanBeNhat();
			else
				cout << "Mang rong.\n";
			break;

		case 10:
			if (M1C.GetN() > 0)
			{
				M1C.SapXepMangTang();
				cout << "Mang sau khi sap xep tang dan la:\n" << M1C;
			}
			else
				cout << "Mang rong.\n";
			break;

		case 11:
		{
			if (M1C.GetN() > 0)
			{
				int vtXoa;
				do
				{
					cout << "Nhap vi tri phan tu muon xoa tu 0 den " << M1C.GetN() - 1 << ": ";
					cin >> vtXoa;
				} while (vtXoa < 0 || vtXoa >= M1C.GetN());
				M1C.XoaTaiViTri(vtXoa);
				cout << "Mang sau khi xoa phan tu tai vi tri thu " << vtXoa << " la:\n" << M1C;
			}
			else
				cout << "Mang rong.\n";
		}
		break;

		case 12:
		{
			int vtThem, gtThem;
			do
			{
				cout << "Nhap vi tri phan tu muon them tu 0 den " << M1C.GetN() << ": ";
				cin >> vtThem;
			} while (vtThem < 0 || vtThem > M1C.GetN());
			cout << "Nhap gia tro phan tu muon them: ";
			cin >> gtThem;
			M1C.ThemTaiViTri(vtThem, gtThem);
			cout << "Mang sau khi them phan tu a[" << vtThem << "] = " << gtThem << " la:\n" << M1C;
		}
		break;

		case 13:
			M1C.~MANG1C();
			cout << "Mang sau khi xoa la: " << M1C;
			break;

		case 14:
		{
			if (M1C.GetN() > 0)
			{
				int gtTim, vtTim;
				cout << "Nhap gia tri phan tu can tim: ";
				cin >> gtTim;
				vtTim = M1C.TimKiemTuyenTinh(gtTim);

				if (vtTim != -1)
					cout << "Tim thay phan tu co gia tri " << gtTim << " tai vi tri thu " << vtTim << endl;
				else
					cout << "Khong tim thay phan tu co gia tri " << gtTim << " trong mang.\n";
			}
			else
				cout << "Mang rong.\n";
		}
		break;

		case 15:
		{
			if (M1C.GetN() > 0)
			{
				M1C.SapXepMangTang();
				cout << "Mang sap xep tang dan la:\n" << M1C;
				int gtTim, vtTim;
				cout << "Nhap gia tro phan tu can tim: ";
				cin >> gtTim;
				vtTim = M1C.TimKiemNhiPhan(gtTim);

				if(vtTim != -1)
					cout << "Tim thay phan tu co gia tri " << gtTim << " tai vi tri thu " << vtTim << endl;
				else
					cout << "Khong tim thay phan tu co gia tri " << gtTim << " trong mang.\n";
			}
			else
				cout << "Mang rong.\n";
		}
		break;

		default:
			cout << "Ban da chon sai. Moi ban chon lai!\n";
			break;
		} 
	} while (Chon != 0);
}