#include "DIEMMAU.h"

int main()
{
	DIEMMAU diem1, diem2;
	int Chon;

	do
	{
		cout << "======CHUONG TRINH XU LY DIEM MAU 3 CHIEU=====\n";
		cout << "1 - Nhap diem mau 2 chieu\n";
		cout << "2 - Xuat diem mau 2 chieu\n";
		cout << "3 - Kiem tra diem mau trung nhau\n";
		cout << "0 - Thoat\n";
		cout << "==============================================\n";
		cout << "Chuong trinh da san sang. Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh...\n";
			break;

		case 1:
			cout << "Nhap thong tin cho diem 1: \n";
			cin >> diem1;
			cout << "Nhap thong tin cho diem 2: \n";
			cin >> diem2;
			break;

		case 2:
			cout << "Thong tin diem 1: \n" << diem1 << endl;
			cout << "Thong tin diem 2: \n" << diem2 << endl;
			break;

		case 3:
			if (diem1.KiemTraTrung(diem2))
			{
				cout << "Hai diem mau trung nhau.\n";
			}
			else
			{
				cout << "Hai diem mau khong trung nhau.\n";
			}
			break;

		default:
			cout << "Ban da chon sai. Vui long chon lai!\n";
			break;
		}
	} while (Chon != 0);
	return 0;
}
	