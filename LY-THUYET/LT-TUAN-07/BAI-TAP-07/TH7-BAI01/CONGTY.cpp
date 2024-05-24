#include "CONGTY.h"

CONGTY::~CONGTY()
{
	if (PDTNhanVien != NULL)
	{
		for (int i = 0; i < SoLuong; i++)
			delete PDTNhanVien[i];
		delete[]PDTNhanVien;
		PDTNhanVien = NULL;
		SoLuong = 0;
	}
}

CONGTY::CONGTY()
{
	PDTNhanVien = NULL;
	SoLuong = 0;
}

int CONGTY::GetSoLuong() const
{
	return SoLuong;
}

void CONGTY::Nhap()
{
	int Loai;
	do
	{
		cout << "Nhap so luong Doi tuong Nhan vien (DTNV): ";
		cin >> SoLuong;
	} while (SoLuong < 1);
	PDTNhanVien = new NHANVIEN * [SoLuong];

	for (int i = 0; i < SoLuong; i++)
	{
		cout << "-------------------------------------\n";
		cout << "Nhap thong tin DTNV thu " << i + 1 << ": \n";
		do
		{
			cout << "Nhap loai DTNV (1 - NhanvienBienche, 2 - NhanvienHopdong): ";
			cin >> Loai;
		} while (Loai < 1 || Loai > 2);

		if (Loai == 1)
			PDTNhanVien[i] = new NHANVIENBIENCHE;
		else if (Loai == 2)
			PDTNhanVien[i] = new NHANVIENHOPDONG;
		PDTNhanVien[i]->Nhap();
	}
}

void CONGTY::Xuat()
{
	if (PDTNhanVien == NULL)
		cout << "Danh sach DTNV rong.\n";
	else
		for (int i = 0; i < SoLuong; i++)
			PDTNhanVien[i]->Xuat();
}

NHANVIEN* CONGTY::Nhap1()
{
	int Loai;
	Loai = 0;
	NHANVIEN* PDT;
	do
	{
		cout << "Nhap loai DTNV (1 - NhanvienBienche, 2 - NhanvienHopdong): ";
		cin >> Loai;
	} while (Loai < 1 || Loai > 2);

	if (Loai == 1)
	{
		PDT = new NHANVIENBIENCHE;
		PDT->Nhap();
	}
	else 
	{
		PDT = new NHANVIENHOPDONG;
		PDT->Nhap();
	}
	
	return PDT;
}

void CONGTY::LietKeNhanVienCoHeSoLuongTu35TroLen()
{
	int Dem = 0;
	for (int i = 0; i < SoLuong; i++)
		if (PDTNhanVien[i]->getLoai() == "BC" && ((NHANVIENBIENCHE*)PDTNhanVien[i])->getHeSoLuong() >= 3.5)
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	if (Dem == 0)
		cout << "Khong co Nhan vien Bien che nao co he so luong tu 3.5 tro len.\n";
}

int CONGTY::DemNhanVienHopDongCoSoNgayCongLa26()
{
	int Dem = 0;
	for (int i = 0; i < SoLuong; i++)
	{
		if (PDTNhanVien[i]->getLoai() == "HD" && ((NHANVIENHOPDONG*)PDTNhanVien)->getSoNgayCong() == 26)
		{
			Dem++;
		}
	}
	return Dem;
}

long CONGTY::TinhTongTienLuongNhanVienPhongKeToan()
{
	double Sum=0;
	for (int i = 0; i < SoLuong; i++)
	{
		if (PDTNhanVien[i]->getPhongBan() == "Ke Toan")
			Sum += PDTNhanVien[i]->Luong();
	}
	return 0;
}

double CONGTY::TinhTienLuongTrungBinhCuaNhanVienBienChe()
{
	double Sum = 0;
	int Dem = 0;
	for (int i = 0; i < SoLuong; i++)
	{
		if (PDTNhanVien[i]->getLoai() == "BC")
		{
			Sum += PDTNhanVien[i]->Luong();
			Dem++;
		}
	}
	if (Dem == 0)
		return 0;
	return Sum / Dem;
}

bool CONGTY::KiemTraCongTyCoNhanVienHopDongKhongDiLamNgayNaoKhong()
{
	for (int i = 0; i < SoLuong; i++)
	{
		if (PDTNhanVien[i]->getLoai() == "HD" && ((NHANVIENHOPDONG*)PDTNhanVien[i])->getSoNgayCong() == 0)
			return true;
	}
	return false;
}

void CONGTY::TimCacNhanVienBienCheCoHeSoLuongCaoNhat()
{
	double HeSoLuongMax = -1;
	int VT = -1;
	for (int i = 0; i < SoLuong; ++i)
	{
		if (PDTNhanVien[i]->getLoai() == "BC")
		{
			VT = i;
			HeSoLuongMax = ((NHANVIENBIENCHE*)PDTNhanVien[i])->getHeSoLuong();
			break;
		}
	}

	if (VT != -1)
	{
		for (int i = VT + 1; i < SoLuong; ++i)
		{
			if (PDTNhanVien[i]->getLoai() == "BC" && ((NHANVIENBIENCHE*)PDTNhanVien[i])->getHeSoLuong() > HeSoLuongMax)
				HeSoLuongMax = ((NHANVIENBIENCHE*)PDTNhanVien[i])->getHeSoLuong();
		}

		for (int i = 0; i < SoLuong; ++i)
		{
			if (PDTNhanVien[i]->getLoai() == "BC" && ((NHANVIENBIENCHE*)PDTNhanVien[i])->getHeSoLuong() == HeSoLuongMax)
				PDTNhanVien[i]->Xuat();
		}
	}
	else
		cout << "Cong ty khong co Nhan vien Bien che.";
}

string CONGTY::DoiChuoiInHoa(string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

string CONGTY::DoiChuoiInThuong(string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

void CONGTY::SapXepDanhSachNhanVienTangDanTheoMaSo()
{
	for (int i = 0; i < SoLuong - 1; ++i)
	{
		for (int j = 0; j < SoLuong; ++j) {
			if (PDTNhanVien[i]->getMaSo() > PDTNhanVien[j]->getMaSo())
			{
				NHANVIEN* PTAM = PDTNhanVien[i];
				PDTNhanVien[i] = PDTNhanVien[j];
				PDTNhanVien[j] = PTAM;
			}
		}
	}
}

void CONGTY::Them(NHANVIEN* PDT, int VT)
{
	NHANVIEN** PNEW = new NHANVIEN * [SoLuong + 1];
	
	for (int i = 0; i < VT - 1; i++)
		PNEW[i] = PDTNhanVien[i];
	PNEW[VT - 1] = PDT;
	
	for (int i = VT; i < SoLuong + 1; ++i)
		PNEW[i] = PDTNhanVien[i - 1];

	delete[]PDTNhanVien;
	PDTNhanVien = PNEW;
	SoLuong++;
}

int CONGTY::Xoa(string MS)
{
	int VT = -1;
	for (int i = 0; i < SoLuong; i++)
		if (DoiChuoiInHoa(PDTNhanVien[i]->getMaSo()) == DoiChuoiInHoa(MS))
		{
			VT = i;
			break;
		}
	
	if (VT != -1)
	{
		NHANVIEN** PNEW = new NHANVIEN * [SoLuong - 1];

		for (int i = 0; i < VT; i++)
			PNEW[i] = PDTNhanVien[i];

		for (int i = VT; i < SoLuong - 1; i++)
			PNEW[i] = PDTNhanVien[i + 1];

		delete[]PDTNhanVien;
		PDTNhanVien = PNEW;
		SoLuong--;
	}
	else
		cout << "Khong tim thay DTNV co ma so " << MS << endl;
	return VT;
}

void CONGTY::TimKiemNhanVienTheoThongTinChung(string maso, string hoten, string phongban, double hsl, double hspccv, long tc, int snc, double hsvg)
{
	int Dem = 0;
	
	for (int i = 0; i < SoLuong; ++i)
	{
		if (DoiChuoiInHoa(PDTNhanVien[i]->getMaSo()) == DoiChuoiInHoa(maso))
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (DoiChuoiInHoa(PDTNhanVien[i]->getHoTen()) == DoiChuoiInHoa(hoten))
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (DoiChuoiInHoa(PDTNhanVien[i]->getPhongBan()) == DoiChuoiInHoa(phongban))
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (((NHANVIENBIENCHE*)PDTNhanVien[i])->getHeSoLuong() == hsl)
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (((NHANVIENBIENCHE*)PDTNhanVien[i])->getHeSoPhuCapChucVu() == hspccv)
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (((NHANVIENHOPDONG*)PDTNhanVien[i])->getSoNgayCong() == snc)
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (((NHANVIENHOPDONG*)PDTNhanVien[i])->getTienCong() == tc)
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (((NHANVIENHOPDONG*)PDTNhanVien[i])->getHeSoVuotGio() == hsvg)
		{
			PDTNhanVien[i]->Xuat();
			Dem++;
		}
	}

	if (Dem == 0)
		cout << "Khong co DTNV nao co thong tin ma ban cung cap" << endl;
}