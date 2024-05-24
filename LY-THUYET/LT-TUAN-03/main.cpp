#include "DIEM.h"
#include "TAMGIAC.h"
#include "HCN.h"
#include "HTRON.h"
#include <iostream>

using namespace std;

int main()
{
	int Chon;
	do
	{
		cout << "-----------------CHUONG TRINH XU LY-----------------\n";
		cout << "1. Chuong trinh xu ly Tam giac\n";
		cout << "2. Chuong trinh xu ly Hinh chu nhat\n";
		cout << "3. Chuong trinh xu ly Hinh tron\n";
		cout << "0. Thoat chuong trinh xu ly\n";
		cout << "-----------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ... \n";
			break;

		case 1:
		{
			TAMGIAC tg;
			int Chon1;
			do
			{
				cout << "-----------------CHUONG TRINH XU LY TAM GIAC-----------------\n";
				cout << "1. Nhap 3 dinh cua Tam giac\n";
				cout << "2. Xuat 3 dinh cua Tam giac\n";
				cout << "3. Tinh Chu vi cua Tam giac\n";
				cout << "4. Tinh Dien tich cua Tam giac\n";
				cout << "5. Kiem tra Tam giac hop le\n";
				cout << "6. Phan loai Tam giac\n";
				cout << "0. Thoat chuong trinh\n";
				cout << "--------------------------------------------------------------\n";
				cout << "Moi ban chon: ";
				cin >> Chon1;

				switch (Chon1)
				{
				case 0:
					cout << "Dang thoat chuong trinh ... \n";
					break;

				case 1:
					tg.Nhap();
					break;

				case 2:
					tg.Xuat();
					break;

				case 3:
					cout << "Chu vi cua Tam giac: " << tg.TinhChuVi() << endl;
					break;

				case 4:
					cout << "Dien tich cua Tam giac: " << tg.TinhDienTich() << endl;
					break;

				case 5:
					if (tg.KiemTraHopLe())
						cout << "Tam giac hop le.\n";
					else
						cout << "Tam giac khong hop le.\n";
					break;
				
				case 6:
					cout << "Phan loai Tam giac: " << tg.PhanLoai() << endl;
					break;

				default:
					cout << "Ban chon sai. Moi chon lai!\n";
					break;

				}
			} while (Chon1 != 0);
			return 0;
		}

		case 2:
		{
			HCN hcn;
			int Chon2;
			do
			{
				cout << "--------------CHUONG TRINH XU LY HINH CHU NHAT-----------------\n";
				cout << "1. Nhap 2 diem cua Hinh chu nhat\n";
				cout << "2. Xuat 2 diem cua Hinh chu nhat\n";
				cout << "3. Tinh Chu vi cua Hinh chu nhat\n";
				cout << "4. Tinh Dien tich cua Hinh chu nhat\n";
				cout << "5. Kiem tra Hinh chu nhat hop le\n";
				cout << "0. Thoat chuong trinh\n";
				cout << "----------------------------------------------------------------\n";
				cout << "Moi ban chon: ";
				cin >> Chon2;

				switch (Chon2)
				{
				case 0:
					cout << "Dang thoat chuong trinh .....\n";
					break;

				case 1:
					hcn.Nhap();
					break;

				case 2:
					hcn.Xuat();
					break;

				case 3:
					cout << "Chu vi Hinh chu nhat: " << hcn.TinhChuVi() << endl;
					break;

				case 4:
					cout << "Dien tich Hinh chu nhat: " << hcn.TinhDienTich() << endl;
					break;

				case 5:
					if (hcn.KiemTraHopLe())
						cout << "Hinh chu nhat hop le\n";
					else
						cout << "Hinh chu nhat khong hop le\n";
					break;

				default:
					cout << "Ban chon sai. Moi ban chon lai! \n";
					break;
				}
			} while (Chon2 != 0);
			return 0;
		}
				

		case 3:
		{
			HTRON O;
			double R;
			int Chon3;
			do
			{
				cout << "-----------------CHUONG TRINH XU LY HINH TRON-----------------\n";
				cout << "1. Nhap Tam va Ban kinh R cua Hinh tron\n";
				cout << "2. Xuat Tam va Ban kinh R cua Hinh tron\n";
				cout << "3. Tinh Chu vi cua Hinh tron\n";
				cout << "4. Tinh Dien tich cua Hinh tron\n";
				cout << "5. Kiem tra Hinh tron hop le\n";
				cout << "0. Thoat chuong trinh\n";
				cout << "--------------------------------------------------------------\n";
				cout << "Moi ban chon: ";
				cin >> Chon3;

				switch (Chon3)
				{
				case 0:
					cout << "Dang thoat chuong trinh ....\n";
					break;

				case 1:
					O.Nhap();
					break;

				case 2:
					O.Xuat();
					break;

				case 3:
					cout << "Chu vi cua Hinh tron: " << O.TinhChuVi() << endl;
					break;

				case 4:
					cout << "Dien tich cua Hinh tron: " << O.TinhDienTich() << endl;
					break;

				case 5:
					if (O.KiemTraHopLe())
						cout << "Hinh tron hop le\n";
					else
						cout << "Hinh tron khong hop le\n";
					break;

				default:
					cout << "Ban chon sai. Moi ban chon lai! \n";
					break;
				}
			} while (Chon3 != 0);
			return 0;
		}

		default:
			cout << "Ban chon sai. Moi ban chon lai! \n";
			break;
		}
	} while (Chon != 0);
	return 0;
}