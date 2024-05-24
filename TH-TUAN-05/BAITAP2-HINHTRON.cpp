#include <iostream>
#include <math.h>
using namespace std;
#define epsilon  0.00000001
#define PI 3.14

class DIEM 
{
protected:
    double x, y;
public:
    ~DIEM();
    DIEM(double = 0, double = 0);
    DIEM(const DIEM&);
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    double GetX() const;
    double GetY() const;
    void Nhap();
    void Xuat() const;
    void DiChuyen(double, double);
    bool KiemTraTrung(const DIEM&) const;
    double TinhKhoangCach(const DIEM&) const;
    DIEM TimDiemDoiXung() const;
    bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
    double TinhChuViTamGiac(const DIEM&, const DIEM&) const;
    double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
    string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
};

DIEM::~DIEM() {}

DIEM::DIEM(double x, double y) : x(x), y(y) {}

DIEM::DIEM(const DIEM& d) : x(d.x), y(d.y) {}

void DIEM::SetX(double x)
{
    this->x = x;
}

void DIEM::SetY(double y)
{
    this->y = y;
}

void DIEM::SetXY(double x, double y)
{
    this->x = x;
    this->y = y;
}

double DIEM::GetX() const
{
    return x;
}

double DIEM::GetY() const
{
    return y;
}

void DIEM::Nhap()
{
    cout << "Nhap hoanh do:";
    cin >> x;
    cout << "Nhap tung do:";
    cin >> y;
}

void DIEM::Xuat() const
{
    cout << x << ", " << y;
}

void DIEM::DiChuyen(double dx, double dy)
{
    x += dx;
    y += dy;
}

bool DIEM::KiemTraTrung(const DIEM& d) const
{
    return this->x == d.x && this->y == d.y;
}

double DIEM::TinhKhoangCach(const DIEM& d) const
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

DIEM DIEM::TimDiemDoiXung() const
{
    return DIEM(-x == 0 ? x : -x, -y == 0 ? y : -y);
}

bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && c + b > a;
}

double DIEM::TinhChuViTamGiac(const DIEM& d1, const DIEM& d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return a + b + c;
}

double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = TinhKhoangCach(d2);
    double c = TinhKhoangCach(*this);
    string chuoikq = "";
    if (!KiemTraTamGiacHopLe(d1, d2))
        chuoikq = "TG khong hop le";
    else if (a == b && b == c)
        chuoikq = "TG deu";
    else if (a == b || b == c || c == a)
        if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(c * c + b * b - a * a) <= epsilon)
            chuoikq = "TG vuong can";
        else
            chuoikq = "TG cam";

    else if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(c * c + b * b - a * a) <= epsilon)
        chuoikq = "TG vuong";
    else
        chuoikq = "TG thuong";
    return chuoikq;
}

class HinhTron : public DIEM
{
protected:
    double R;
public:
    ~HinhTron();
    HinhTron(double = 0, double = 0, double = 1);
    double GetR() const;
    void SetR(double);
    void SetOR(double, double, double);
    void Nhap();
    void Xuat() const;
    bool KiemTraHopLe() const;
    double TinhChuVi() const;
    double TinhDienTich() const;
    friend istream& operator>>(istream&, HinhTron&);
    friend ostream& operator<<(ostream&, const HinhTron&);
};

HinhTron::~HinhTron() {}

HinhTron::HinhTron(double x, double y, double R) : DIEM(x, y), R(R)
{
    if (!KiemTraHopLe())
        Nhap();
}

double HinhTron::GetR() const
{
    return R;
}

void HinhTron::SetR(double R)
{
    this->R = R;
    while (!KiemTraHopLe())
    {
        cout << "Nhap lai R > 0:";
        cin >> R;
    }

}

void HinhTron::SetOR(double x, double y, double R)
{
    DIEM::SetXY(x, y);
    SetR(R);
}

void HinhTron::Nhap()
{
    DIEM::Nhap();
    do {
        cout << "Nhap Ban kinh R:";
        cin >> R;
    } while (!KiemTraHopLe());
}

void HinhTron::Xuat() const
{
    cout << "Hinh tron di qua Tam O( ";
    DIEM::Xuat(); cout << ") ";
    cout << "co Ban kinh R = " << R;
    cout << "\tDien tich: " << TinhDienTich();
    cout << "\tChu vi: " << TinhChuVi() << endl;
}

bool HinhTron::KiemTraHopLe() const
{
    return (R < 1 ? 0 : 1);
}

double HinhTron::TinhDienTich() const
{
    return PI * R * R;
}
double HinhTron::TinhChuVi() const
{
    return 2 * PI * R;
}
istream& operator>>(istream& is, HinhTron& d)
{
    d.Nhap();
    return is;
}
ostream& operator<<(ostream& os, const HinhTron& d)
{
    d.Xuat();
    return os;
}

int main()
{
    HinhTron c;
    int Chon;
    do 
    {
        cout << "-----------CHUONG TRINH XU LY HINH TRON----------------" << endl;
        cout << "1. Nhap toa do Tam O va Ban kinh R" << endl;
        cout << "2. Xuat" << endl;
        cout << "3. Di chuyen toa do" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Moi ban chon: ";
        cin >> Chon;

        switch (Chon) 
        {
        case 0:
            cout << "Dang thoat chuong trinh...\n";
            break;
            
        case 1:
            cin >> c;
            break;
        
        case 2:
            cout << c;
            break;

        case 3:
            int dx = 0, dy = 0;
            cout << "Nhap dX:";
            cin >> dx;
            cout << "Nhap dY:";
            cin >> dy;
            c.DiChuyen(dx, dy);
            break;
        
        default:
            cout << "Ban chon sai. Vui long chon lai!";
            break;
        }
    } while (Chon != 0);
}