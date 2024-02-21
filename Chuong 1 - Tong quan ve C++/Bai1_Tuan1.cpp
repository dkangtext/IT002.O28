// Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.

// Bước 1: Xác định Input, Output.
    // Input: Tử số, Mẫu số.
    // Output: Tử số, Mẫu số (đã được rút gọn).

// Bước 2: Giải quyết bài toán.
    // Tìm USCLN => Tử sổ = Tử số / USCLN, Mẫu số = Mẫu số / USCLN.

#include <iostream>
using namespace std;

int main()
{
    // Khai báo biến
    int tuSo, mauSo;

    // Nhập liệu
    cout << "Nhap tu so: ";
    cin >> tuSo;

    cout << "Nhap mau so: ";
    cin >> mauSo;

    if (mauSo == 0)
        cout << "Mau so khong hop le";
    else
        cout << tuSo << "/" << mauSo;

    // Xử lý tính toán

    // Kết xuất

}