#include<iostream>
#include "SOPHUC.h"
using namespace std;

int main()
{
	SOPHUC sp1, sp2;
	SOPHUC Cong, Tru, Nhan, Chia;
	int Chon;

	do
	{
		cout << "------------CHUONG TRINH XU LY OVERLOAD SO PHUC------------\n";
		cout << "1. Nhap hai so phuc \n";
		cout << "2. Xuat hai so phuc \n";
		cout << "3. Cong hai so phuc \n";
		cout << "4. Tru hai so phuc \n";
		cout << "5. Nhan hai so phuc \n";
		cout << "6. Chia hai so phuc \n";
		cout << "7. So sanh hai so phuc \n";
		cout << "0. Thoat chuong trinh \n";
		cout << "-----------------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ...\n";
			break;

		case 1:
			cout << "\nNhap hai so phuc: ";
			cout << endl;

			cout << "\nSo phuc thu nhat: \n";
			cin >> sp1;
			cout << endl;

			cout << "So phuc thu hai: \n";
			cin >> sp2;
			cout << endl;

			break;

		case 2:
			cout << "\nHai so phuc vua nhap la: " << endl;

			cout << "\nSo phuc thu nhat: ";
			sp1.Xuat();
			cout << endl;

			cout << "\nSo phuc thu hai: ";
			sp2.Xuat();
			cout << endl;

			break;

		case 3:
			Cong = sp1 + sp2;
			cout << "Tong hai so phuc la: " << sp1 << " + " << sp2 << " = " << Cong << endl;
			break;

		case 4:
			Tru = sp1 - sp2;
			cout << "Hieu hai phan so la: " << sp1 << " - " << sp2 << " = " << Tru << endl;
			break;

		case 5:
			Nhan = sp1 * sp2;
			cout << "Tich hai phan so la: " << sp1 << " * " << sp2 << " = " << Nhan << endl;
			break;

		case 6:
			Chia = sp1 / sp2;
			cout << "Thuong hai phan so la: " << sp1 << " / " << sp2 << " = " << Chia << endl;
			break;

		case 7:
			cout << "So sanh hai so phuc: " << endl;
			cout << "ps1 == ps2 : " << ((bool)(sp1 == sp2) ? "Dung" : "Sai") << endl;
			cout << "ps1 != ps2 : " << ((bool)(sp1 != sp2) ? "Dung" : "Sai") << endl;
			cout << "ps1 > ps2 : " << ((bool)(sp1 > sp2) ? "Dung" : "Sai") << endl;
			cout << "ps1 < ps2 : " << ((bool)(sp1 < sp2) ? "Dung" : "Sai") << endl;
			cout << "ps1 >= ps2 : " << ((bool)(sp1 >= sp2) ? "Dung" : "Sai") << endl;
			cout << "ps1 <= ps2 : " << ((bool)(sp1 <= sp2) ? "Dung" : "Sai") << endl;
			break;

		default:
			cout << "Ban da nhap sai. Moi ban nhap lai ! \n";
			break;
		}
	} while (Chon != 0);
	return 0;
}
