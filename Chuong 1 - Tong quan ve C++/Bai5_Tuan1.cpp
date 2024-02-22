// Bài 5: Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung bình và xuất kết quả.

// Xác định Input, Output của bài toán.
    // Input: Họ tên, điểm toán, điểm văn của một học sinh.
    // Output: Điểm trung bình của điểm toán và văn vừa nhập.

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

void Nhap(HOCSINH&);
void XuLy(HOCSINH&);
void Xuat(HOCSINH);

int main()
{
    HOCSINH hs;
    Nhap(hs);
    XuLy(hs);
    Xuat(hs);
    return 1;
}

void Nhap(HOCSINH &x)
{
    cout << "Nhap ho va ten hoc sinh: ";
    getline (cin, x.hoTen);

    cout << "Nhap diem Toan: ";
    cin >> x.diemToan;

    cout << "Nhap diem Van: ";
    cin >> x.diemVan;
}

void XuLy(HOCSINH &x)
{
    x.diemTrungBinh = (float)(x.diemToan + x.diemVan)/2;
}

void Xuat(HOCSINH x)
{
    cout << "\n Ho va ten Hoc sinh: " << x.hoTen;
    cout << "\n Diem Toan: " << x.diemToan;
    cout << "\n Diem Van: " << x.diemVan;
    cout << "\n Diem Trung Binh cua Hoc sinh la: " << x.diemTrungBinh;
}