#include "DIEM3C.h"

int main()
{
	DIEM3C d1, d2, d3;
	int Chon;
	do
	{
		cout << "=======CHUONG TRINH XU LY DIEM 3 CHIEU========\n";
		cout << "1 - Nhap toa do diem 3 chieu\n";
		cout << "2 - Xuat toa do diem 3 chieu\n";
		cout << "3 - Di chuyen diem\n";
		cout << "4 - Tinh khoang cach giua hai diem\n";
		cout << "5 - Kiem tra hai diem co trung nhau khong\n";
		cout << "6 - Tim diem doi xung\n";
		cout << "7 - Tinh chu vi tam giac qua 3 diem\n";
		cout << "8 - Tinh dien tich tam giac qua 3 diem\n";
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
			cout << "Nhap toa do diem d1: \n";
			cin >> d1;
			cout << "Nhap toa do diem d2: \n";
			cin >> d2;
			cout << "Nhap toa do diem d3: \n";
			cin >> d3;
			break;

		case 2:
			cout << "Toa do diem d1: " << d1 << endl;
			cout << "Toa do diem d2: " << d2 << endl;
			cout << "Toa do diem d3: " << d3 << endl;
			break;

		case 3:
			double dx, dy, dz;
			cout << "Nhap vector di chuyen (dx, dy, dz): ";
			cin >> dx >> dy >> dz;
			d1.DiChuyen(dx, dy, dz);
			cout << "Diem d1 sau khi di chuyen: " << d1 << endl;
			break;

		case 4:
			cout << "Khoang cach giua d1 va d2: " << d1.TinhKhoangCach(d2) << endl;
			break;

		case 5:
			if (d1.KiemTraTrung(d2))
			{
				cout << "d1 va d2 trung nhau\n";
			}
			else
			{
				cout << "d1 va d2 khong trung nhau\n";
			}
			break;

		case 6:
			cout << "Diem doi xung cua d1: " << d1.TimDoiXung() << endl;
			break;

		case 7:
			if (d1.KiemTraTamGiacHopLe(d2, d3))
			{
				cout << "Chu vi tam giac d1, d2, d3: " << d1.TinhChuViTamGiac(d2, d3) << endl;
			}
			else
			{
				cout << "Ba diem khong tao thanh tam giac hop le\n";
			}
			break;

		case 8:
			if (d1.KiemTraTamGiacHopLe(d2, d3))
			{
				cout << "Dien tich tam giac d1, d2, d3: " << d1.TinhDienTichTamGiac(d2, d3) << endl;
			}
			else
			{
				cout << "Ba diem khong tao thanh tam giac hop le\n";
			}

		default:
			cout << "Ban da chon sai. Vui long chon lai!\n";
			break;
		}
	} while (Chon != 0);
	return 0;
}