#include "TRUONGDAIHOC.h"
#include "SINHVIEN.h"
#include "SINHVIENCHINHQUY.h"
#include "SINHVIENLIENTHONG.h"

TRUONGDAIHOC::~TRUONGDAIHOC() 
{
	if (PDTSinhVien != NULL)
	{
		for (int i = 0; i < SoLuong; i++)
			delete PDTSinhVien[i];
		delete[]PDTSinhVien;
		PDTSinhVien = NULL;
		SoLuong = 0;
	}
}

TRUONGDAIHOC::TRUONGDAIHOC()
{
	PDTSinhVien = NULL;
	SoLuong = 0;
}

int TRUONGDAIHOC::getSoLuong() const
{
	return SoLuong;
}

void TRUONGDAIHOC::Nhap()
{
	int Loai;
	do
	{
		cout << "Nhap so luong DTSV: ";
		cin >> SoLuong;
	} while (SoLuong < 1);

	PDTSinhVien = new SINHVIEN * [SoLuong];

	for (int i = 0; i < SoLuong; i++)
	{
		cout << "-----------------------------------\n";
		cout << "Nhap thong tin DTSV thu " << i + 1 << ": \n";
		do
		{
			cout << "Nhap loai (1 - SinhVienChinhQuy, 2 - SinhVienLienThong): ";
			cin >> Loai;
		} while (Loai < 1 || Loai > 2);

		if (Loai == 1)
			PDTSinhVien[i] = new SINHVIENCHINHQUY;
		else if (Loai == 2)
			PDTSinhVien[i] = new SINHVIENLIENTHONG;
		PDTSinhVien[i]->Nhap();
	}
}

void TRUONGDAIHOC::Xuat()
{
	if (PDTSinhVien == NULL)
		cout << "Danh sach DTSV rong\n";
	else
		for (int i = 0; i < SoLuong; i++)
			PDTSinhVien[i]->Xuat();
}

SINHVIEN* TRUONGDAIHOC::Nhap1()
{
	int Loai;
	Loai = 0;
	SINHVIEN* PDT;
	
	do
	{
		cout << "Nhap loai (1 - SinhVienChinhQuy, 2 - SinhVienLienThong): ";
		cin >> Loai;
	} while (Loai < 1 || Loai > 2);

	if (Loai == 1)
	{
		PDT = new SINHVIENCHINHQUY;
		PDT->Nhap();
	}
	else 
	{
		PDT = new SINHVIENLIENTHONG;
		PDT->Nhap();
	}
	
	return PDT;
}

void TRUONGDAIHOC::LietKeCacSinhVienChinhQuyCoDiemRenLuyenLa100()
{
	int Dem = 0;
	for (int i = 0; i < SoLuong; i++)
		if (PDTSinhVien[i]->getLoai() == "CQ" && ((SINHVIENCHINHQUY*)PDTSinhVien[i])->getDiemRenLuyen() == 100)
		{
			PDTSinhVien[i]->Xuat();
			Dem++;
		}
	if (Dem == 0)
		cout << "Khong co Sinh vien Chinh quy nao co Diem ren luyen la 100\n";
}

int TRUONGDAIHOC::DemSoLuongSinhVienLienThongKhongNghiBuoiNao()
{
	int Dem = 0;
	for (int i = 0; i < SoLuong; i++)
	{
		if (PDTSinhVien[i]->getLoai() == "LT" && ((SINHVIENLIENTHONG*)PDTSinhVien[i])->getSoBuoiVang() == 0)
		{
			Dem++;
		}
	}
	return Dem;
}

long TRUONGDAIHOC::TinhTongHocBongCapChoCacSinhVien()
{
	double Sum;
	Sum = 0;

	for (int i = 0; i < SoLuong; i++)
	{
		Sum += PDTSinhVien[i]->TinhHocBong();
	}
	return 0;
}

double TRUONGDAIHOC::TinhDiemTrungBinhCuaCacSinhVienChinhQuyDuocCapHocBong()
{
	double Sum = 0;
	int Dem = 0;
	for (int i = 0; i < SoLuong; i++)
	{
		if (PDTSinhVien[i]->getLoai() == "CQ" && ((SINHVIENCHINHQUY*)PDTSinhVien[i])->TinhHocBong() > 0)
		{
			Sum += PDTSinhVien[i]->getDiemTrungBinh();
			Dem++;
		}
	}
	if (Dem == 0) 
		return 0;
	return Sum / Dem;
}

bool TRUONGDAIHOC::KiemTraTruongCoSinhVienLienThongCoDiemTrungBinhTu9TroLenVaKhongNghiBuoiNaoKhong()
{
	for (int i = 0; i < SoLuong; i++)
	{
		if (PDTSinhVien[i]->getLoai() == "LT" && ((SINHVIENLIENTHONG*)PDTSinhVien[i])->getSoBuoiVang() == 0 && PDTSinhVien[i]->getDiemTrungBinh() >= 9)
			return true;
	}
	return false;
}

void TRUONGDAIHOC::TimCacSinhVienChinhQuyCoDiemTrungBinhCaoNhat()
{
	double DiemTrungBinhMax = -1;
	int VT = -1;
	for (int i = 0; i < SoLuong; ++i)
	{
		if (PDTSinhVien[i]->getLoai() == "CQ")
		{
			VT = i;
			DiemTrungBinhMax = ((SINHVIENCHINHQUY*)PDTSinhVien)->getDiemTrungBinh();
			break;
		}
	}

	if (VT != -1)
	{
		for (int i = VT + 1; i < SoLuong; ++i)
		{
			if (PDTSinhVien[i]->getLoai() == "CQ" && ((SINHVIENCHINHQUY*)PDTSinhVien[i])->getDiemTrungBinh() > DiemTrungBinhMax)
				DiemTrungBinhMax = ((SINHVIENCHINHQUY*)PDTSinhVien[i])->getDiemTrungBinh();
		}

		for (int i = 0; i < SoLuong; ++i)
		{
			if (PDTSinhVien[i]->getLoai() == "CQ" && ((SINHVIENCHINHQUY*)PDTSinhVien[i])->getDiemTrungBinh() > DiemTrungBinhMax)
				PDTSinhVien[i]->Xuat();
		}
	}
	else
		cout << "Truong khong co Sinh vien Chinh quy\n";
}

string TRUONGDAIHOC::DoiChuoiInHoa(string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

string TRUONGDAIHOC::DoiChuoiInThuong(string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

void TRUONGDAIHOC::SapXepSinhVienTangDanTheoMaSo()
{
	for (int i = 0; i < SoLuong - 1; ++i)
	{
		for (int j = 0; j < SoLuong; ++j) {
			if (PDTSinhVien[i]->getMaSo() > PDTSinhVien[j]->getMaSo())
			{
				SINHVIEN* PTAM = PDTSinhVien[i];
				PDTSinhVien[i] = PDTSinhVien[j];
				PDTSinhVien[j] = PTAM;
			}
		}
	}
}

void TRUONGDAIHOC::Them(SINHVIEN* PDT, int VT)
{
	SINHVIEN** PNEW = new SINHVIEN * [SoLuong + 1];

	for (int i = 0; i < VT - 1; i++)
		PNEW[i] = PDTSinhVien[i];
	PNEW[VT - 1] = PDT;

	for (int i = VT; i < SoLuong + 1; ++i)
		PNEW[i] = PDTSinhVien[i - 1];

	delete[]PDTSinhVien;
	PDTSinhVien = PNEW;
	SoLuong++;
}

int TRUONGDAIHOC::Xoa(string MS)
{
	int VT = -1;
	for (int i = 0; i < SoLuong; i++)
		if (DoiChuoiInHoa(PDTSinhVien[i]->getMaSo()) == DoiChuoiInHoa(MS))
		{
			VT = i;
			break;
		}

	if (VT != -1)
	{
		SINHVIEN** PNEW = new SINHVIEN * [SoLuong - 1];

		for (int i = 0; i < VT; i++)
			PNEW[i] = PDTSinhVien[i];

		for (int i = VT; i < SoLuong - 1; i++)
			PNEW[i] = PDTSinhVien[i + 1];

		delete[]PDTSinhVien;
		PDTSinhVien = PNEW;
		SoLuong--;
	}
	else
		cout << "Khong tim thay DTSV co ma so " << MS << endl;
	return VT;
}

void TRUONGDAIHOC::TimKiemSinhVienTheoThongTinChung(string maso, string hoten, string khoa, double diemtrungbinh, int diemrenluyen, int sobuoivang)
{
	int Dem = 0;

	for (int i = 0; i < SoLuong; ++i)
	{
		if (DoiChuoiInHoa(PDTSinhVien[i]->getMaSo()) == DoiChuoiInHoa(maso))
		{
			PDTSinhVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (DoiChuoiInHoa(PDTSinhVien[i]->getHoTen()) == DoiChuoiInHoa(hoten))
		{
			PDTSinhVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (DoiChuoiInHoa(PDTSinhVien[i]->getKhoa()) == DoiChuoiInHoa(khoa))
		{
			PDTSinhVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (PDTSinhVien[i]->getDiemTrungBinh() == diemtrungbinh)
		{
			PDTSinhVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (((SINHVIENCHINHQUY*)PDTSinhVien[i])->getDiemRenLuyen() == diemrenluyen)
		{
			PDTSinhVien[i]->Xuat();
			Dem++;
		}
	}

	for (int i = 0; i < SoLuong; ++i)
	{
		if (((SINHVIENLIENTHONG*)PDTSinhVien[i])->getSoBuoiVang() == sobuoivang)
		{
			PDTSinhVien[i]->Xuat();
			Dem++;
		}
	}

	if (Dem == 0)
		cout << "Khong co DTSV nao co thong tin ma ban cung cap" << endl;
}