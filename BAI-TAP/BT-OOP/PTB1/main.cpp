#include "PTB1.h"
#include "PTB2.h"

void main()
{
	PTB1 pt1;
	PTB2 pt2;
	int Chon;
	do
	{
		cout << "------------CHUONG TRINH GIAI PHUONG TRINH-----------\n";
		cout << "1. Giai phuong trinh bac 1.\n";
		cout << "2. Giai phuong trinh bac 2.\n";
		cout << "0. Thoat chuong trinh.\n";
		cout << "------------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat CT...\n";
			break;

		case 1:
			pt1.Nhap();
			pt1.Xuat();
			break;

		case 2:
			pt2.Nhap();
			pt2.Xuat();
			break;

		default:
			cout << "Ban chon sai. Moi ban chon lai. \n";
		}

	} while (Chon != 0);
}