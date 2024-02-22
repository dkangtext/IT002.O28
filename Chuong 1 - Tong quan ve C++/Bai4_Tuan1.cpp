// Viết 4: Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.

// Xác định Input và Output của bài toán.
    // Input: Ngày, tháng, năm.
    // Output: Ngày, tháng, năm của ngày kế tiếp.

#include <iostream>
using namespace std;

struct Date
{
    int Ngay;
    int Thang;
    int Nam;
};
typedef struct Date DATE;

// Hàm kiểm tra năm nhuận
bool NamNhuan(int year);

// Hàm để tìm ngày kế tiếp
DATE TimNgayKeTiep(const DATE& NgayHienTai);

int main() 
{
    // Khối khai báo
    DATE NgayHienTai;

    // Nhập thông tin ngày
    do 
    {
        cout << "Nhap ngay: ";
        cin >> NgayHienTai.Ngay;
        cout << "Nhap thang: ";
        cin >> NgayHienTai.Thang;
        cout << "Nhap nam: ";
        cin >> NgayHienTai.Nam;

        // Kiểm tra tính hợp lệ của ngày tháng năm nhập vào
        if (NgayHienTai.Thang < 1 || NgayHienTai.Thang > 12 || NgayHienTai.Ngay < 1) 
        {
            cout << "Ngay thang nam khong hop le! Vui long nhap lai.\n";
        } 
        else 
        {
            int NgayCuoiCuaThang;
            switch (NgayHienTai.Thang) 
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    NgayCuoiCuaThang = 31;
                    break;
                case 4: case 6: case 9: case 11:
                    NgayCuoiCuaThang = 30;
                    break;
                case 2:
                    NgayCuoiCuaThang = (NamNhuan(NgayHienTai.Nam)) ? 29 : 28;
                    break;
                default:
                    NgayCuoiCuaThang = -1; // Tháng không hợp lệ
            }

            if (NgayHienTai.Ngay > NgayCuoiCuaThang || NgayHienTai.Ngay < 1) 
            {
                cout << "Ngay khong hop le cho thang " << NgayHienTai.Thang << " nam " << NgayHienTai.Nam << "! Vui long nhap lai.\n";
            } 
            else 
            {
                break; // Thoát khỏi vòng lặp nếu ngày tháng năm hợp lệ
            }
        }
    } while (true);

    // Tìm ngày kế tiếp
    DATE NgayKeTiep = TimNgayKeTiep(NgayHienTai);

    // Xuất kết quả
    cout << "Ngay ke tiep la: " << NgayKeTiep.Ngay << "/" << NgayKeTiep.Thang << "/" << NgayKeTiep.Nam << endl;

    return 0;
}

// Hàm kiểm tra năm nhuận
bool NamNhuan(int Nam) 
{
    return (Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0);
}

// Hàm để tìm ngày kế tiếp
DATE TimNgayKeTiep(const DATE& NgayHienTai) 
{
    DATE NgayKeTiep = NgayHienTai;

    // Kiểm tra ngày cuối tháng
    int NgayCuoiCuaThang;
    switch (NgayKeTiep.Thang) 
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            NgayCuoiCuaThang = 31;
            break;
        case 4: case 6: case 9: case 11:
            NgayCuoiCuaThang = 30;
            break;
        case 2:
            NgayCuoiCuaThang = (NamNhuan(NgayKeTiep.Nam)) ? 29 : 28;
            break;
        default:
            NgayCuoiCuaThang = -1; // Tháng không hợp lệ
    }

    // Kiểm tra và cập nhật ngày kế tiếp
    if (NgayKeTiep.Ngay < NgayCuoiCuaThang) 
    {
        NgayKeTiep.Ngay++;
    } 
    else 
    {
        NgayKeTiep.Ngay = 1;
        if (NgayKeTiep.Thang < 12) 
        {
            NgayKeTiep.Thang++;
        } 
        else 
        {
            NgayKeTiep.Thang = 1;
            NgayKeTiep.Nam++;
        }
    }

    return NgayKeTiep;
}
