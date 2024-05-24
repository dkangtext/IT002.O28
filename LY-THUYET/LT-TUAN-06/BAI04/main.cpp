#include "DIEM3CMAU.h"

int main()
{
	DIEM3CMAU a, b, c;
	int Chon;
	double dx, dy, dz;
	do
	{
		cout << "=======CHUONG TRINH XU LY DIEM 3 CHIEU CO MAU=====\n";
		cout << "1. Nhap 1 DIEM3CMAU\n";
		cout << "2. Nhap 2 DIEM3CMAU\n";
		cout << "3. Nhap 3 DIEM3CMAU\n";
		cout << "4. Kiem Tra Trung\n";
		cout << "5. Tinh Chu vi\n";
		cout << "6. Tinh Dien tich\n";
		cout << "7. Tim Doi xung\n";
		cout << "8. Di chuyen\n";
		cout << "9. Xuat 1 DIEM3CMAU\n";
		cout << "10. Xuat 3 DIEM3CMAU\n";
		cout << "0. Thoat Chuong trinh\n";
		cout << "==================================================\n";
		cout << "Chuong trinh da san sang. Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ...\n";
			break;

		case 1:
			cin >> a;
			break;

		case 2:
			cin >> b;
			break;

		case 3:
			cin >> c;
			break;

		case 4:
			if (a.KiemTraTrung(b))
				cout << "Diem A trung Diem B\n";
			if (a.KiemTraTrung(c))
				cout << "Diem A trung Diem C\n";
			if (c.KiemTraTrung(b))
				cout << "Diem B trung Diem C\n";
			if (!a.KiemTraTrung(b) && b.KiemTraTrung(c))
				cout << "Diem A, B, C khong trung nhau \n";
			break;

		case 5:
			cout << "Chu vi cua tam giac la: ";
			cout << a.TinhChuViTamGiac(b, c);
			break;

		case 6:
			cout << "Dien tich cua tam giac la: ";
			cout << a.TinhDienTichTamGiac(b, c);
			break;

		case 7:
			cout << "Diem doi xung voi A" << a << " la A'(" << a.TimDoiXung() << ")";
			cout << "Diem doi xung voi B" << b << " la B'(" << b.TimDoiXung() << ")";
			cout << "Diem doi xung voi C" << c << " la C'(" << c.TimDoiXung() << ")";
			break;

		case 8:
			cout << "Nhap dx: ";
			cin >> dx;
			cout << "Nhap dy: ";
			cin >> dy;
			cout << "Nhap dz: ";
			cin >> dz;

			a.DiChuyen(dx, dy, dz);
			b.DiChuyen(dx, dy, dz);
			c.DiChuyen(dx, dy, dz);
			break;

		case 9:
			cout << "A" << a << endl;
			break;

		case 10:
			cout << "A" << a << endl;
			cout << "B" << b << endl;
			cout << "C" << c << endl;
			break;

		default:
			cout << "Ban da nhap sai. Moi ban chon lai!";
			break;
		}
	} while (Chon != 0);
	return 0;
}