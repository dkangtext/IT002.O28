// Bài 15: Viết chương trình mô phỏng trò chơi đoán số mà máy phát sinh. Nếu đoán đúng thì hiển thị
// chúc mừng, nếu nhỏ hơn hoặc lớn hơn thì thông báo cho người dùng biết mà đoán lại.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TroChoiDoanSo 
{
    int soMayPhatSinh;

    TroChoiDoanSo() 
    {
        srand(time(0));
        soMayPhatSinh = rand() % 100 + 1;
    }

    void Choi() 
    {
        int Doan;
        cout << "Chao mung den voi tro choi doan so!" << endl;
        cout << "May da phat sinh mot so tu 1 den 100. Hay doan no!" << endl;

        do 
        {
            cout << "Nhap so doan cua ban: ";
            cin >> Doan;

            if (Doan < soMayPhatSinh) 
            {
                cout << "So doan cua ban nho hon so may phat sinh. Hay doan lai!" << endl;
            } 
            else if (Doan > soMayPhatSinh) 
            {
                cout << "So doan cua ban lon hon so may phat sinh. Hay doan lai!" << endl;
            } 
            else 
            {
                cout << "Chuc mung! Ban da doan dung!" << endl;
            }
        } while (Doan != soMayPhatSinh);
    }
};

int main() 
{
    TroChoiDoanSo troChoi;
    troChoi.Choi();
    return 0;
}
