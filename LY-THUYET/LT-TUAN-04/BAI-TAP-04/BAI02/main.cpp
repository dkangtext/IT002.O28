#include "PHANSO.h"

int main()
{
	PHANSO ps1, ps2;
	int Chon;
	PHANSO Cong, Tru, Nhan, Chia;
	do
	{
		cout << "----------CHUONG TRINH XU LY OVERLOADING PHANSO----------\n";
		cout << "1. Nhap hai phan so \n";
		cout << "2. Xuat hai phan so \n";
		cout << "3. Cong hai phan so \n";
		cout << "4. Tru hai phan so \n";
		cout << "5. Nhan hai phan so \n";
		cout << "6. Chia hai phan so \n";
		cout << "7. So sanh hai phan so \n";
		cout << "0. Thoat chuong trinh \n";
		cout << "---------------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ... \n";
			break;

		case 1:
			cout << "\nNhap hai phan so: ";
			cout << endl;
			
			cout << "\nPhan so thu nhat: \n";
			cin >> ps1;
			cout << endl;

			cout << "Phan so thu hai: \n";
			cin >> ps2;
			cout << endl;

			break;

		case 2:
			cout << "\nHai phan so vua nhap la: " << endl;
			
			cout << "\nPhan so thu nhat: ";
			ps1.Xuat();
			cout << endl;

			cout << "\nPhan so thu hai: ";
			ps2.Xuat();
			cout << endl;

			break;

		case 3:
			Cong = ps1 + ps2;
			cout << "Tong hai phan so la: " << ps1 << " + " << ps2 << " = " << Cong << endl;
			break;

		case 4:
			Tru = ps1 - ps2;
			cout << "Hieu hai phan so la: " << ps1 << " - " << ps2 << " = " << Tru << endl;
			break;

		case 5:
			Nhan = ps1 * ps2;
			cout << "Tich hai phan so la: " << ps1 << " * " << ps2 << " = " << Nhan << endl;
			break;

		case 6:
			Chia = ps1 / ps2;
			cout << "Thuong hai phan so la: " << ps1 << " / " << ps2 << " = " << Chia << endl;
			break;

		case 7:
			cout << "So sanh hai phan so: " << endl;
			cout << "ps1 == ps2 : " << ((ps1 == ps2) ? "Dung" : "Sai") << endl;
			cout << "ps1 != ps2 : " << ((ps1 != ps2) ? "Dung" : "Sai") << endl;
			cout << "ps1 > ps2 : " << ((ps1 > ps2) ? "Dung" : "Sai") << endl;
			cout << "ps1 < ps2 : " << ((ps1 < ps2) ? "Dung" : "Sai") << endl;
			cout << "ps1 >= ps2 : " << ((ps1 >= ps2) ? "Dung" : "Sai") << endl;
			cout << "ps1 <= ps2 : " << ((ps1 <= ps2) ? "Dung" : "Sai") << endl;
			break;

		default:
			cout << "Ban da nhap sai. Moi ban nhap lai ! \n";
			break;
		}
	} while (Chon != 0);
	return 0;
}