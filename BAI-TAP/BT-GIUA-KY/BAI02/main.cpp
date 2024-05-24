#include "FX.h"

int main()
{
	FX fx1, fx2, ketqua;
	int Chon;
	double x0;

	do
	{
		cout << "----------------KIEM TRA GIUA KY 2------------------\n";
		cout << "-------CHUONG TRINH XU LY PHUONG TRINH BAC 2--------\n";
		cout << "1. Nhap he so cho da thuc bac 2 thu nhat------------\n";
		cout << "2. Xuat da thuc bac 2 thu nhat----------------------\n";
		cout << "3. Nhap he so cho da thuc bac 2 thu hai-------------\n";
		cout << "4. Xuat da thuc bac 2 thu hai-----------------------\n";
		cout << "5. Tinh gia tri cua da thuc tai gia tri x0----------\n";
		cout << "6. Tinh nghiem cua hai da thuc tren-----------------\n";
		cout << "7. Cong hai da thuc---------------------------------\n";
		cout << "0. Thoat chuong trinh-------------------------------\n";
		cout << "----------------------------------------------------\n";
		cout << "Chuong trinh da san sang. Moi ban nhap: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ...\n";
			break;

		case 1:
			cout << "Nhap he so cho phuong trinh bac 2 thu nhat: \n";
			cin >> fx1;
			break;

		case 2:
			cout << "Phuong trinh bac 2 thu nhat vua nhap la: ";
			cout << fx1;
			cout << endl;
			break;

		case 3:
			cout << "Nhap he so cho phuong trinh bac 2 thu hai: \n";
			cin >> fx2;
			break;
		
		case 4:
			cout << "Phuong trinh bac 2 thu hai vua nhap la: ";
			cout << fx2;
			cout << endl;
			break;

		case 5:
			cout << "Nhap gia tri x0: ";
			cin >> x0;
			cout << "Gia tri cua da thuc bac 2 thu nhat tai x0 = " << x0 << " la: " << fx1.GiaTriDaThuc(x0);
			cout << endl;
			cout << "Gia tri cua da thuc bac 2 thu hai tai x0 = " << x0 << " la: " << fx2.GiaTriDaThuc(x0);
			cout << endl;
			break;

		case 6:
			cout << "Ket qua nghiem cua phuong trinh bac 2 thu nhat la: ";
			fx1.TinhNghiemDaThuc();
			cout << endl;
			
			cout << "Ket qua nghiem cua chuong trinh bac 2 thu hai la: ";
			fx2.TinhNghiemDaThuc();
			cout << endl;
			break;

		case 7: 
			ketqua = fx1 + fx2;
			cout << "Tong hai da thuc bac 2 la: " << ketqua << endl;
			break;

		default:
			cout << "Ban da chon sai. Moi ban chon lai!\n";
			break;
		}
	} while (Chon != 0);
	return 0;
}