#include "DIEM.h"
#include <iostream>

using namespace std;

int main()
{
	DIEM d1, d2, d3;
	int Chon;
	do
	{
		cout << "--------------CHUONG TRINH XU LY 3 DIEM--------------\n";
		cout << "1. Nhap toa do 3 diem \n";
		cout << "2. Xuat toa do 3 diem \n";
		cout << "3. Di chuyen 1 diem \n";
		cout << "4. Kiem tra cac diem trung nhau \n";
		cout << "5. Tim khoang cach 2 diem \n";
		cout << "6. Tim doi doi xung cua 1 diem \n";
		cout << "7. Tinh chu vi tam giac qua 3 diem \n";
		cout << "8. Tinh dien tich tam giac qua 3 diem \n";
		cout << "9. Phan loai tam giac qua 3 diem \n";
		cout << "0. Thoat chuong trinh \n";
		cout << "-------------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;

		switch (Chon)
		{
		case 0: 
			cout << "Dang thoat chuong trinh ... \n";
			break;

		case 1:
			cout << "Nhap toa do diem d1: \n";
			d1.Nhap();

			cout << "Nhap toa do diem d2: \n";
			d2.Nhap();

			cout << "Nhap toa do diem d3: \n";
			d3.Nhap();
			break;

		case 2:
			cout << "Toa do ba 3 diem la: \n";
			cout << "d1("; d1.Xuat(); cout << ") \n";
			cout << "d2("; d2.Xuat(); cout << ") \n";
			cout << "d3("; d3.Xuat(); cout << ") \n";
			break;

		case 3:
			int DiemChon;
			double dx, dy;
			do
			{
				cout << "Chon diem can di chuyen (1-d1, 2-d2, 3-d3): ";
				cin >> DiemChon;
			} while (DiemChon < 1 || DiemChon > 3);

			cout << "Nhap khoang cach ngang - doc can di chuyen diem: ";
			cin >> dx >> dy;

			if (DiemChon == 1)
			{
				d1.DiChuyen(dx, dy);
				cout << "Diem d1 sau khi di chuyen la d1_new("; d1.Xuat(); cout << ") \n";
			}
			else if (DiemChon == 2)
			{
				d2.DiChuyen(dx, dy);
				cout << "Diem d2 sau khi di chuyen la d2_new("; d2.Xuat(); cout << ") \n";
			}
			else 
			{
				d3.DiChuyen(dx, dy);
				cout << "Diem d3 sau khi di chuyen la d3_new("; d3.Xuat(); cout << ") \n";
			}
			break;

		case 4:
			if (d1.KiemTraTrung(d2))
				if (d1.KiemTraTrung(d3))
					cout << "3 diem d1, d2, d3 trung nhau \n";
				else
					cout << "3 diem trung nhau \n";

			else if (d1.KiemTraTrung(d3))
				cout << "d1 trung d3 \n";

			else if (d2.KiemTraTrung(d3))
				cout << "d2 trung d3 \n";

			else
				cout << "3 diem d1, d2, d3 khong trung nhau \n";
			break;

		case 5:
			cout << "Khoang cach tu d1 den d2 la: " << d1.TinhKhoangCach(d2) << endl;
			cout << "Khoang cach tu d2 den d3 la: " << d2.TinhKhoangCach(d3) << endl;
			cout << "Khoang cach tu d3 den d1 la: " << d3.TinhKhoangCach(d1) << endl;
			break;

		case 6:
		{
			DIEM ddx;
			int DiemChon;
			do
			{
				cout << "Chon diem can tim diem doi xung (1-d1, 2-d2, 3-d3): ";
				cin >> DiemChon;
			} while (DiemChon < 1 || DiemChon > 3);

			if (DiemChon == 1)
			{
				ddx = d1.TimDoiXung();
				cout << "Diem doi xung cua d1 la d1'("; ddx.Xuat(); cout << ")\n";
			}
			else if (DiemChon == 2)
			{
				ddx = d2.TimDoiXung();
				cout << "Diem doi xung cua d2 la d2'("; ddx.Xuat(); cout << ")\n";
			}
			else 
			{
				ddx = d3.TimDoiXung();
				cout << "Diem doi xung cua d3 la d3'("; ddx.Xuat(); cout << ")\n";
			}
			break;
		}

		case 7:
			if (d1.KiemTraTamGiacHopLe(d2, d3))
				cout << "Chu vi tam giac qua 3 diem d1, d2,d3 la: " << d1.TinhChuViTamGiac(d2, d3) << endl;
			else
				cout << "d1,d2,d3 khong tao thanh tam giac hop le ! \n";
			break;

		case 8:
			if (d1.KiemTraTamGiacHopLe(d2, d3))
				cout << "Dien tich tam giac qua 3 diem d1, d2,d3 la: " << d1.TinhDienTichTamGiac(d2, d3) << endl;
			else
				cout << "d1,d2,d3 khong tao thanh tam giac hop le ! \n";
			break;

		case 9:
			if (d1.KiemTraTamGiacHopLe(d2, d3))
				cout << "Tam giac qua 3 diem d1, d2,d3 la: " << d1.PhanLoaiTamGiac(d2, d3) << endl;
			else
				cout << "d1,d2,d3 khong tao thanh tam giac hop le ! \n";
			break;

		default:
			cout << "Ban chon sai roi. Moi ban chon lai \n";
			break;
		}
	} while (Chon != 0);
}