//. Nhập điểm chuẩn và điểm 3 môn thi, mã khu vực (A, B, C), mã đối tượng (1, 2, 3) của thí sinh. Hiển thị 
// kết quả “Trúng tuyển” nếu tổng điểm thi 3 môn cộng với điểm ưu tiên khu vực và điểm ưu tiên đối tượng 
// lớn hơn hoặc bằng điểm chuẩn và không có môn nào bị điểm liệt (0 điểm). Trong đó, điểm ưu tiên khu vực 
// và điểm ưu tiên đối tượng được tình như sau:
    // • Khu vực A: cộng 1.5 điểm
    // • Khu vực B: cộng 1 điểm
    // • Khu vực C: cộng 0.5 điểm   
    // • Đối tượng 1: cộng 1.5 điểm
    // • Đối tượng 2: cộng 1 điểm
    // • Đối tượng 3: cộng .5 điểm 

#include <iostream>
#include <cstring>
using namespace std;

struct XetTuyen
{
    float diemChuan;
    float diemMon1;
    float diemMon2;
    float diemMon3;
    string maKhuVuc;
    int maDoiTuong;
    float tongDiem;
};

void NhapThongTin(XetTuyen &xt)
{
    cout << "Nhap diem chuan: \n";
    cin >> xt.diemChuan;

    cout << "Nhap diem mon thi 1: ";
    cin >> xt.diemMon1;
    cout << "Nhap diem mon thi 2: ";
    cin >> xt.diemMon2;
    cout << "Nhap diem mon thi 3: ";
    cin >> xt.diemMon3;

    do
    {
        cout << "Nhap ma khu vuc cua thi sinh: ";
        cin >> xt.maKhuVuc;
        if (xt.maKhuVuc == "A" || xt.maKhuVuc == "B" || xt.maKhuVuc == "C") 
            break;
        else 
            cout << "Ma khu vuc cua thi sinh khong hop le. \n";
    } while (xt.maKhuVuc != "A" && xt.maKhuVuc != "B" && xt.maKhuVuc != "C");
    
    do
    {
        cout << "Nhap ma doi tuong uu tien cua thi sinh: ";
        cin >> xt.maDoiTuong;
        if (xt.maDoiTuong == 1 || xt.maDoiTuong == 2 || xt.maDoiTuong == 3) 
            break;
        else
            cout << "Ma doi tuong uu tien cua thi sinh khong hop le. \n";
    } while (xt.maDoiTuong != 1 && xt.maDoiTuong != 2 && xt.maDoiTuong != 3); 
}

void XuatKetQua(XetTuyen &xt)
{
    xt.tongDiem = xt.diemMon1 + xt.diemMon2 + xt.diemMon3;

    if (xt.maKhuVuc == "A")
        xt.tongDiem = xt.tongDiem + 1.5;
    else if (xt.maKhuVuc == "B")
        xt.tongDiem = xt.tongDiem + 1.0;
    else if (xt.maKhuVuc == "C")
        xt.tongDiem = xt.tongDiem + 0.5;
    
    switch(xt.maDoiTuong)
    {
        case 1:
            xt.tongDiem = xt.tongDiem + 1.5;
            break;
        case 2:
            xt.tongDiem = xt.tongDiem + 1.0;
            break;
        case 3: 
            xt.tongDiem = xt.tongDiem + 0.5;
            break;
    }
    
    if (xt.tongDiem >= xt.diemChuan && xt.diemMon1 != 0 && xt.diemMon2 != 0 && xt.diemMon3 != 0)
        cout << "Trung tuyen";
    else
        cout << "Khong trung tuyen";
}

int main()
{
    XetTuyen hocSinh;
    NhapThongTin(hocSinh);
    XuatKetQua(hocSinh);
    return 0;
}
