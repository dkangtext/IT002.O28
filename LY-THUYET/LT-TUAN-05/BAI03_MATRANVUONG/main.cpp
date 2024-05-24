#include "MATRANVUONG.h"

int main()
{
	MATRANVUONG mtrv;
	int Chon;
	do
	{
		cout << "----------------------------------CHUONG TRINH XU LY MA TRAN VUONG-------------------------------------\n";
		cout << "1. Nhap gia tri cac phan tu ma tran--------------------------------------------------------------------\n";
		cout << "2. Xuat gia tri cac phan tu ma tran--------------------------------------------------------------------\n";
		cout << "3. Liet ke gia tri cac phan tu le nam tren duong cheo chinh cua ma tran--------------------------------\n";
		cout << "4. Dem so luong cac phan tu co ky so cuoi la 3 nam tren duong cheo phu cua ma tran---------------------\n";
		cout << "5. Kiem tra xem co ton tai phan tu am o nua mang vuong phia tren duong cheo chinh hay khong?-----------\n";
		cout << "6. Tim phan tu chan dau tien o nua mang vuong phia duoi duong cheo phu cua ma tran---------------------\n";
		cout << "7. Sap xep giam dan cac phan tu tren duong cheo phu cua ma tran----------------------------------------\n";
		cout << "0. Thoat chuong trinh----------------------------------------------------------------------------------\n";
		cout << "-------------------------------------------------------------------------------------------------------\n";
		cout << "Chuong trinh da san sang! Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh...\n";
			break;

		case 1:
			cin >> mtrv;
			break;

		case 2:
			cout << "Ma tran ban vua nhap la: \n";
			cout << mtrv;
			break;

		case 3:
			mtrv.LietKePhanTuLeNamTrenDuongCheoChinh();
			cout << "\n";
			break;

		case 4:
			if (mtrv.DemKyTu3NamTrenDuongCheoPhu() == -1)
				cout << "Khong co phan tu nao co ky tu 3 cuoi.\n";
			else
				cout << mtrv.DemKyTu3NamTrenDuongCheoPhu() << endl;
			break;

		case 5:
			if (mtrv.KiemTraAmNuaTrenDuongCheoChinh() == 0)
				cout << "Khong ton tai.\n";
			else
				cout << "Co ton tai.\n";
			break;

		case 6:
			if (mtrv.ChanDauTienNuaDuoiDuongCheoPhu() == -1)
				cout << "Khong ton tai.\n";
			else
				cout << mtrv.ChanDauTienNuaDuoiDuongCheoPhu() << endl;
			break;

		case 7:
			mtrv.SapXepGiamDanDuongCheoPhu();
			cout << "Ma tran sau khi sap xep giam dan cac phan tu tren duong cheo phu la:\n";
			cout << mtrv << endl;
			break;

		default:
			cout << "Ban da chon sai. Moi ban chon lai!";
			break;
		}
	} while (Chon != 0);
	return 0;
}