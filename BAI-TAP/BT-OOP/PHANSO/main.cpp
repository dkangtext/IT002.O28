#include "PhanSo.h"
#include <iostream>
using namespace std;

int main()
{
	PhanSo ps1, ps2, ketQua;
	int Chon;
	do
	{
		cout << "---------CHUONG TRINH PHAN SO------------\n";
		cout << "1. Nhap hai phan so \n";
		cout << "2. Xuat hai phan so \n";
		cout << "3. Tong hai phan so \n";
		cout << "4. Hieu hai phan so \n";
		cout << "5. Tich hai phan so \n";
		cout << "6. Thuong hai phan so \n";
		cout << "0. Thoat chuong trinh \n";
		cout << "------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ....";
			break;

		case 1:
			cout << "Moi ban nhap hai phan so: \n";

			cout << "Nhap phan so thu nhat: \n";
			ps1.Nhap();

			cout << "Nhap phan so thu hai: \n";
			ps2.Nhap();
			break;

		case 2:
			cout << "Hai phan so la: \n";

			cout << "Phan so thu nhat la: ";
			ps1.Xuat();
			cout << endl;

			cout << "Phan so thu hai la: ";
			ps2.Xuat();
			cout << endl;
			break;

		case 3:
			ketQua = ps1.Cong(ps2);
			cout << "\n Tong hai phan so: ";
			ketQua.Xuat();
			cout << endl;
			break;

		case 4:
			ketQua = ps1.Tru(ps2);
			cout << "\n Hieu hai phan so: ";
			ketQua.Xuat();
			cout << endl;
			break;

		case 5:
			ketQua = ps1.Nhan(ps2);
			cout << "\n Tich hai phan so: ";
			ketQua.Xuat();
			cout << endl;
			break;

		case 6:
			ketQua = ps1.Chia(ps2);
			cout << "\n Thuong hai phan so: ";
			ketQua.Xuat();
			cout << endl;
			break;

		default:
			cout << "Ban da chon sai. Moi ban nhap lai: \n";
			break;
		}
	} while (Chon != 0);
	return 0;
}