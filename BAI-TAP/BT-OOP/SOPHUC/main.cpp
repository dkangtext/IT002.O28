#include "SoPhuc.h"
#include <iostream>

using namespace std;

int main()
{
	SoPhuc sp1, sp2, ketQua;
	int Chon;
	do
	{
		cout << "--------------CHUONG TRINH XU LY SO PHUC--------------\n";
		cout << "1. Nhap hai so phuc \n";
		cout << "2. Xuat hai so phuc \n";
		cout << "3. Dinh gia tri cho so phuc (Module) \n";
		cout << "4. Cong hai so phuc \n";
		cout << "5. Tru hai so phuc \n";
		cout << "6. Nhan hai so phuc \n";
		cout << "7. Chia hai so phuc \n";
		cout << "0. Thoat chuong trinh \n";
		cout << "-------------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ....";
			break;

		case 1:
			cout << "Nhap hai so phuc: \n";

			cout << "Nhap so phuc thu nhat: \n";
			sp1.Nhap();

			cout << "Nhap so phuc thu hai: \n";
			sp2.Nhap();
			break;

		case 2:
			cout << "So phuc thu nhat la: ";
			sp1.Xuat();
			cout << endl;

			cout << "So phuc thu hai la: ";
			sp2.Xuat();
			cout << endl;
			break;

		case 3:
			cout << "Module cua so phuc thu nhat la: ";
			sp1.Module();
			cout << endl;

			cout << "Module cua so phuc thu hai la: ";
			sp2.Module();
			cout << endl;
			break;

		case 4:
			ketQua = sp1;
			ketQua.Cong(sp2);
			sp1.Xuat(); cout << " + "; sp2.Xuat(); cout << " = "; ketQua.Xuat(); cout << endl;
			break;

		case 5:
			ketQua = sp1;
			ketQua.Tru(sp2);
			sp1.Xuat(); cout << " - "; sp2.Xuat(); cout << " = "; ketQua.Xuat(); cout << endl;
			break;

		case 6:
			ketQua = sp1;
			ketQua.Nhan(sp2);
			sp1.Xuat(); cout << " * "; sp2.Xuat(); cout << " = "; ketQua.Xuat(); cout << endl;
			break;

		case 7:
			ketQua = sp1;
			ketQua.Chia(sp2);
			sp1.Xuat(); cout << " / "; sp2.Xuat(); cout << " = "; ketQua.Xuat(); cout << endl;
			break;

		default:
			cout << "Ban da chon sai. Moi chon lai! \n";
			break;
		}
	} while (Chon != 0);
	return 0;
}
