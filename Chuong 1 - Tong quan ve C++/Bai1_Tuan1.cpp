// Bài 1: Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.

// Bước 1: Xác định Input, Output.
    // Input: Tử số, Mẫu số.
    // Output: Tử số, Mẫu số (đã được rút gọn).

// Bước 2: Giải quyết bài toán.
    // Tìm USCLN => Tử sổ = Tử số / USCLN, Mẫu số = Mẫu số / USCLN.

#include <iostream>
using namespace std;

int main()
{
    // Khai báo biến lưu Phân số
    int tuSo, mauSo;

    // Nhập liệu biến lưu Phân số
    cout << "Nhap tu so: ";
    cin >> tuSo;

    do
    {
        cout << "Nhap mau so (khac 0): ";
        cin >> mauSo;
        if (mauSo != 0) break;    /* code */
    } while (mauSo == 0);
    
    // Xử lý tính toán rút gọn Phân số
        // 1. Tìm USCLN

    int USCLN = 1, a = tuSo, b = mauSo;
    a = abs(a); // |a|: absolute
    b = abs(b); // |b|: absolute

    if (a == 0 && b == 0)
        USCLN = 1;
    else if (a == 0 || b == 0)
        USCLN = a + b;
    else
    {
        while (a != b)
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        USCLN = a; // USCLN = b;
    }

        // 2. Rút gọn Phân số
    tuSo = tuSo / USCLN;
    mauSo = mauSo / USCLN;

    // Kết xuất Phân số tối giản
    if (mauSo < -1)
        cout << -tuSo << "/" << -mauSo;
    else if (mauSo == -1)
        cout << -tuSo;
    else if (mauSo == 0)
        cout << "Khong chia cho so 0";
    else if (mauSo == 1)
        cout << tuSo;
    else
        cout << tuSo << "/" << mauSo;
}