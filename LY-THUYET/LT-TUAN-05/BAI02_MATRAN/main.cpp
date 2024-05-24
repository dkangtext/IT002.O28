#include "MATRAN.h"

int main()
{
	MATRAN mtr;
	int Chon;
	do
	{
		cout << "--------------------------------CHUONG TRINH XU LY MA TRAN------------------------------\n";
		cout << "1. Nhap gia tri cac phan tu ma tran-----------------------------------------------------\n";
		cout << "2. Xuat gia tri cac phan tu ma tran-----------------------------------------------------\n";
		cout << "3. Liet ke gia tri cac phan tu la so nguyen to cua ma tran------------------------------\n";
		cout << "4. Dem so luong cac phan tu la so chinh phuong cua ma tran------------------------------\n";
		cout << "5. Tinh tong gia tri cac phan tu la so hoan thien tren dong k cua ma tran---------------\n";
		cout << "6. Tinh trung binh cong gia tri cac phan tu la so doi xung tren cot k cua ma tran-------\n";
		cout << "7. Sap xep tang dan cac phan tu tren dong k cua ma tran---------------------------------\n";
		cout << "0. Thoat chuong trinh-------------------------------------------------------------------\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Chuong trinh da san sang! Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh...\n";
			break;

		case 1:
			cin >> mtr;
			break;

		case 2:
			cout << mtr;
			break;

		case 3:
			mtr.LietKeSoNguyenTo();
			cout << endl;
			break;

		case 4:
			cout << "So luong phan tu chinh phuong: " << mtr.DemSoChinhPhuong() << endl;
			break;

		case 5:
			int dong;
			cout << "Nhap dong can tinh tong so hoan thien: ";
			cin >> dong;
			cout << "Tong cac so hoan thien tren dong " << dong << ": " << mtr.TinhTongSoHoanThien(dong) << endl;
			break;

		case 6:
			int cot;
			cout << "Nhap cot can tinh trung binh cong so doi xung: ";
			cin >> cot;
			cout << "Trung binh cong cac so doi xung tren cot " << cot << ": " << mtr.TinhTrungBinhCongSoDoiXung(cot) << endl;
			break;

		case 7:
			int dongSapXep;
			cout << "Nhap dong k muon sap xep tang dan: ";
			cin >> dongSapXep;
			cout << "Ma tran sau khi sap xep tang dan tren dong " << dongSapXep << ":\n";
			cout << mtr.SapXepTuBeDenLon(dongSapXep) << endl;
			break;

		default:
			cout << "Ban da chon sai. Moi ban chon lai!\n";
			break;
		}
	} while (Chon != 0);
	return 0;
}	
