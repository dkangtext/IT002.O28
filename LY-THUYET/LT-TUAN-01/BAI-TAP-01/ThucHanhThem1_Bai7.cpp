// Bài 7: Nhập vào số tiền. Hãy tính và in ra số tờ tiền tương ứng với các mệnh giá giảm dần: 500k,200k,100k,50k. (giả sử đổi hết mệnh giá lớn, phần dư mới đổi sang mệnh giá nhỏ hơn).

#include <iostream>
using namespace std;

struct Tien 
{
    int soTien;
    int soTo500k;
    int soTo200k;
    int soTo100k;
    int soTo50k;
    int soTienDu;
};

void Nhap(Tien &t) 
{
    cout << "Nhap so tien: ";
    cin >> t.soTien;
}

void Xuat(const Tien &t) 
{
    cout << "So luong to tien ung voi cac menh gia giam dan lan luot la: \n";
    cout << "500k: " << t.soTo500k << " to" << endl;
    cout << "200k: " << t.soTo200k << " to" << endl;
    cout << "100k: " << t.soTo100k << " to" << endl;
    cout << "50k: " << t.soTo50k << " to" << endl;

    cout << "So tien con du cuoi cung la: " << t.soTienDu << " dong" << endl;
}

void XuLy(Tien &t) 
{
    // Số tờ 500k
    t.soTo500k = t.soTien / 500000;
    int soDu500k = t.soTien % 500000;

    // Số tờ 200k
    t.soTo200k = soDu500k / 200000;
    int soDu200k = soDu500k % 200000;

    // Số tờ 100k
    t.soTo100k = soDu200k / 100000;
    int soDu100k = soDu200k % 100000;

    // Số tờ 50k
    t.soTo50k = soDu100k / 50000;
    int soDu50k = soDu100k % 50000;

    // Số tiền còn dư cuối cùng
    t.soTienDu = soDu50k; 
}

int main() 
{
    Tien A;
    Nhap(A);
    XuLy(A);
    Xuat(A);
    return 0;
}
