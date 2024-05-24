#include "CONGTY.h"
#include <fstream>

CONGTY::~CONGTY()
{
	for (auto NhanVien : danhSachNhanVien)
	{
		delete NhanVien;
	}
}

void CONGTY::nhapDanhSachNhanVien()
{
	int Loai;
	do
	{
		cout << "Nhap loai nhan vien (1: Lap trinh vien, 2: Kiem chung vien, 0: Thoat): " << endl;
		cin >> Loai;
		NHANVIEN* NhanVien = nullptr;
		
		if (Loai == 1)
		{
			NhanVien = new LAPTRINHVIEN();
		}
		else if (Loai == 2)
		{
			NhanVien = new KIEMCHUNGVIEN();
		}
		else if (Loai == 0)
		{
			break;
		}
		else
		{
			cout << "Loai nhan vien khong hop le!" << endl;
			continue;
		}
		NhanVien->Nhap();
		danhSachNhanVien.push_back(NhanVien);
	} while (Loai != 0);
}

void CONGTY::xuatDanhSachNhanVien()
{
	for (auto NhanVien : danhSachNhanVien)
	{
		NhanVien->Xuat();
		cout << "-----------------------------" << endl;
	}
}

void CONGTY::LietKeDanhSachLapTrinhVienCoLuongThapHonMucLuongTrungBinh()
{
	double luongTrungBinh = TinhLuongTrungBinh();
	cout << "Danh sach lap trinh vien co luong thap hon trung binh:" << endl;
	for (auto NhanVien : danhSachNhanVien) 
	{
		if (NhanVien->getLoai() == "LTV" && NhanVien->Luong() < luongTrungBinh) 
		{
			NhanVien->Xuat();
			cout << "-----------------------------" << endl;
		}
	}
}

void CONGTY::KiemTraCoKiemChungVienNaoChiPhatHienDuocDuoi5LoiKhong()
{
	bool CoKCVPhatHienDuoi5Loi = false;
	for (auto NhanVien : danhSachNhanVien) 
	{
		if (NhanVien->getLoai() == "KCV" && static_cast<KIEMCHUNGVIEN*>(NhanVien)->getSoLoi() < 5) 
		{
			CoKCVPhatHienDuoi5Loi = true;
			break;
		}
	}
	if (CoKCVPhatHienDuoi5Loi) 
	{
		cout << "Co kiem chung vien phat hien duoi 5 loi." << endl;
	}
	else 
	{
		cout << "Khong co kiem chung vien nao phat hien duoi 5 loi." << endl;
	}
}

void CONGTY::CapNhatThongTinNhanVien(string maNhanVien)
{
	for (auto NhanVien : danhSachNhanVien) 
	{
		if (NhanVien->getMaNhanVien() == maNhanVien) 
		{
			NhanVien->Nhap();
			break;
		}
	}
}

void CONGTY::XoaDanhSachNhanVien()
{
	for (auto NhanVien : danhSachNhanVien) 
	{
		delete NhanVien;
	}
	danhSachNhanVien.clear();
}

void CONGTY::DocFile(string tenFile)
{
	ifstream file(tenFile);
	if (!file.is_open()) 
	{
		cout << "Khong the mo file!" << endl;
		return;
	}
		
	int Loai;
	while (file >> Loai) 
	{
		NHANVIEN* NhanVien = nullptr;
		if (Loai == 1) 
		{
			NhanVien = new LAPTRINHVIEN();
		}
		else if (Loai == 2) 
		{
			NhanVien = new KIEMCHUNGVIEN();
		}
		else 
		{
			continue;
		}

		file.ignore();
		string maNhanVien, hoTen, soDienThoai, Email;
		int Tuoi;
		file >> ws;
		getline(file, maNhanVien);
		getline(file, hoTen);
		file >> Tuoi;
		file.ignore();
		getline(file, soDienThoai);
		getline(file, Email);
			
		NhanVien->setMaNhanVien(maNhanVien);
		NhanVien->setHoTen(hoTen);
		NhanVien->setTuoi(Tuoi);
		NhanVien->setSoDienThoai(soDienThoai);
		NhanVien->setEmail(Email);
			
		if (Loai == 1) 
		{
			float soGioLamThem;
			file >> soGioLamThem;
			static_cast<LAPTRINHVIEN*>(NhanVien)->setSoGioLamThem(soGioLamThem);
		}
		else if (Loai == 2) 
		{
			float soLoi;
			file >> soLoi;
			static_cast<KIEMCHUNGVIEN*>(NhanVien)->setSoLoi(soLoi);
		}
		danhSachNhanVien.push_back(NhanVien);
	}
	file.close();
}

void CONGTY::LuuFile(string tenFile)
{
	ofstream file(tenFile);
	if (!file.is_open()) 
	{
		cout << "Khong the mo file!" << endl;
		return;
	}

	for (auto NhanVien : danhSachNhanVien) 
	{
		if (NhanVien->getLoai() == "LTV") 
		{
			file << 1 << endl;
		}
		else if (NhanVien->getLoai() == "KCV") 
		{
			file << 2 << endl;
		}

		file << NhanVien->getMaNhanVien() << endl;
		file << NhanVien->getHoTen() << endl;
		file << NhanVien->getTuoi() << endl;
		file << NhanVien->getSoDienThoai() << endl;
		file << NhanVien->getEmail() << endl;
		
		if (NhanVien->getLoai() == "LTV") 
		{
			file << static_cast<LAPTRINHVIEN*>(NhanVien)->getSoGioLamThem() << endl;
		}
		else if (NhanVien->getLoai() == "KCV") 
		{
			file << static_cast<KIEMCHUNGVIEN*>(NhanVien)->getSoLoi() << endl;
		}
	}
	file.close();
}

double CONGTY::TinhLuongTrungBinh()
{
	double tongLuong = 0;
	for (auto NhanVien : danhSachNhanVien)
	{
		tongLuong += NhanVien->Luong();
	}
	return tongLuong / danhSachNhanVien.size();
}