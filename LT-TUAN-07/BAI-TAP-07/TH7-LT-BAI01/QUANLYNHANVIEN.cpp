#include "QUANLYNHANVIEN.h"
#include "NHANVIENSANXUAT.h"
#include "NHANVIENVANPHONG.h"

QUANLYNHANVIEN::~QUANLYNHANVIEN()
{
	delete[]DuLieu;
}

QUANLYNHANVIEN::QUANLYNHANVIEN()
{
	SoLuongNhanVien = 0;
	DuLieu = new NHANVIEN * [SoLuongNhanVien];
	TongSoLuongPhaiTra = 0;
	LuongCaoNhat = 0; Max = 0;
	LuongThapNhat = 0; Min = 0;
}

void QUANLYNHANVIEN::Nhap()
{
	cout << "Nhap so luong nhan vien: ";
	cin >> SoLuongNhanVien;

	int Chon = 0;
	
	for (int i = 0; i < SoLuongNhanVien; i++)
	{
		do
		{
			cout << "---CHUONG TRINH QUAN LY NHAN VIEN---\n";
			cout << "Nhap Thong tin Nhan vien thu: " << i + 1 << endl;
			cout << "MENU Nhap Du lieu: " << endl;
			cout << "1 - Nhan vien San xuat " << endl;
			cout << "2 - Nhan vien Van phong " << endl;
			cout << "0 - Thoat chuong trinh " << endl;
			cout << "-------------------------------------\n";
			cout << "Chuong trinh da san sang. Moi ban chon: ";
			cin >> Chon;

			if (Chon != 1 && Chon != 2 && Chon != 0)
			{
				cout << "Nhap sai lua chon, vui long nhap lai!" << endl;
			}
		} while (Chon != 1 && Chon != 2 && Chon != 0);

		if (Chon == 1)
		{
			DuLieu[i] = new NHANVIENSANXUAT;
		}
		else if (Chon == 2)
		{
			DuLieu[i] = new NHANVIENVANPHONG;
		}
		else
		{
			cout << "Dang thoat chuong trinh ...\n" << endl;
		}

		DuLieu[i]->Nhap();
		TongSoLuongPhaiTra = TongSoLuongPhaiTra + DuLieu[i]->Luong();
	}
}

void QUANLYNHANVIEN::Xuat()
{
	cout << "So luong nhan vien cua Cong ty: " << SoLuongNhanVien << endl;

	for (int i = 0; i < SoLuongNhanVien; i++)
	{
		cout << "Thong tin Nhan vien thu: " << i + 1 << endl;
		DuLieu[i]->Xuat();
		cout << "Tien luong nhan duoc: " << DuLieu[i]->Luong() << endl;
	}

	cout << "Tong so tien luong ma Cong ty phai tra cho Nhan vien: " << TongSoLuongPhaiTra << endl;
	LuongCaoNhat = DuLieu[0]->Luong();
	LuongThapNhat = DuLieu[0]->Luong();

	for (int i = 0; i < SoLuongNhanVien; i++)
	{
		if (DuLieu[i]->Luong() > LuongCaoNhat)
		{
			LuongCaoNhat = DuLieu[i]->Luong();
			Max = i;
		}
		if (DuLieu[i]->Luong() < LuongThapNhat)
		{
			LuongThapNhat = DuLieu[i]->Luong();
			Min = i;
		}
	}

	cout << "Nhan vien co muc luong cao nhat la: " << endl;
	DuLieu[Max]->Xuat();
	cout << endl;

	cout << "Nhan vien co muc luong thap nhat la: " << endl;
	DuLieu[Min]->Xuat();
	cout << endl;
}