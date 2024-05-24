// Bài 5: Nhập vào username và password. Nếu nhập sai quá 3 lần thì in thông báo lỗi, ngược lại hiển thị câu chào username.

#include <iostream>
#include <string>
using namespace std;

struct TaiKhoan 
{
    string username;
    string password;
    int soLanSai;
};

void NhapThongTin(TaiKhoan &tk) 
{
    cout << "Nhap username: ";
    cin >> tk.username;
    cout << "Nhap password: ";
    cin >> tk.password;
}

bool KiemTraDangNhap(const TaiKhoan &tk) 
{
    if (tk.username == "username" && tk.password == "password") 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

bool DaVuotQuaSoLanSai(const TaiKhoan &tk) 
{
    return tk.soLanSai >= 3;
}

void XuatChao(const TaiKhoan &tk) 
{
    cout << "Chao " << tk.username << endl;
}

int main() 
{
    TaiKhoan taiKhoan = {"", "", 0};
    
    for (int i = 0; i < 3; i++) 
    {
        cout << "Nhap thong tin cua ban." << endl;
        NhapThongTin(taiKhoan);
        if (KiemTraDangNhap(taiKhoan)) 
        {
            XuatChao(taiKhoan);
            return 0; // Đăng nhập thành công, kết thúc chương trình.
        } 
        else 
        {
            cout << "Ban da nhap sai username hoac password. Vui long nhap lai." << endl;
            taiKhoan.soLanSai++;
            if (DaVuotQuaSoLanSai(taiKhoan)) 
            {
                cout << "Ban da vuot qua so lan sai toi da. Vui long thu lai sau." << endl;
                return 0; // Đăng nhập thất bại và đã vượt quá số lần cho phép tối đa, kết thúc chương trình.
            }
        }
    }
    cout << "Ban da nhap sai username hoac password qua 3 lan. Vui long thu lai sau." << endl;
    return 0;
}
