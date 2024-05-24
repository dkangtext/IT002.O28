// Bài 5: Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung bình và xuất kết quả.

#include <iostream>
#include <string>
using namespace std;

struct HocSinh
{
    string hoTen;
    float diemToan;
    float diemVan;
    float diemTrungBinh;
};
typedef struct HocSinh HOCSINH;

void Nhap(HOCSINH &hs)
{
    cout << "Nhap ho va ten hoc sinh: ";
    getline (cin, hs.hoTen);

    cout << "Nhap diem Toan: ";
    cin >> hs.diemToan;

    cout << "Nhap diem Van: ";
    cin >> hs.diemVan;
}

void XuLy(HOCSINH &hs)
{
    hs.diemTrungBinh = (float)(hs.diemToan + hs.diemVan)/2;
}

void Xuat(HOCSINH hs)
{
    cout << "\n Ho va ten Hoc sinh: " << hs.hoTen;
    cout << "\n Diem Toan: " << hs.diemToan;
    cout << "\n Diem Van: " << hs.diemVan;
    cout << "\n Diem Trung Binh cua Hoc sinh la: " << hs.diemTrungBinh;
}

int main()
{
    HOCSINH hs;
    Nhap(hs);
    XuLy(hs);
    Xuat(hs);
    return 1;
}

