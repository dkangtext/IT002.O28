#include "MONEY.h"

int main()
{
	MONEY Money;
	int Chon;
	double TyGia;
	do
	{
		cout << "----------------KIEM TRA GIUA KY 2------------------\n";
		cout << "-------------CHUONG TRINH XU LY MONEY---------------\n";
		cout << "1. Nhap so tien-------------------------------------\n";
		cout << "2. Xuat so tien vua nhap----------------------------\n";
		cout << "3. Doi sang tien VND voi ty gia truyen ao-----------\n";
		cout << "4. Tien tang them-----------------------------------\n";
		cout << "0. Thoat chuong trinh-------------------------------\n";
		cout << "----------------------------------------------------\n";
		cout << "Chuong trinh da san sang. Moi ban nhap: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh...\n";
			break;

		case 1:
			cout << "Moi ban nhap: \n";
			cin >> Money;
			break;

		case 2:
			cout << "So tien ban vua nhap la: ";
			cout << Money;
			cout << endl;
			break;

		case 3:
			cout << "Nhap ty gia (VND sang 1 USD):";
			cin >> TyGia;

			cout << "So tien doi sang VND la:";
			cout << Money << " = " << Money.convertToVND(TyGia) << " VND";
			cout << endl;
			
			break;

		case 4:
			++Money;
			cout << "So tien tang them: " << Money << endl;
			break;

		default:
			cout << "Ban da chon sai. Moi ban chon lai!\n";
			break;
		}
	} while (Chon != 0);
	return 0;
}