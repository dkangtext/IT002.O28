#include "DIEM.h"
#include "TAMGIAC.h"
#include <iostream>

using namespace std;

int main()
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
		cout << "6. Phan loai Tam giac\n";\
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

	