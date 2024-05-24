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
    friend istream& operator >>(istream&, DIEM&);
    friend ostream& operator <<(ostream&, const DIEM&);
};

DIEM::~DIEM()
{}

DIEM::DIEM(double x, double y) : x(x), y(y)
{}

DIEM::DIEM(const DIEM& d) : x(d.x), y(d.y)
{}

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

istream& operator >>(istream& is, DIEM& d)
{
    d.Nhap();
    return is;
}

ostream& operator <<(ostream& os, DIEM& d)
{
    d.Xuat();
    return os;
}

class DIEM3C : public DIEM
{
protected:
    double z;
public:
    ~DIEM3C();
    DIEM3C(double = 0, double = 0, double = 0);
    DIEM3C(const DIEM3C&);
    double GetZ() const;
    void SetZ(double);
    void SetXYZ(double, double, double);
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const DIEM3C&) const;
    void DiChuyen(double, double, double);
    double TinhKhoangCach(const DIEM3C&) const;
    DIEM3C TimDiemDoiXung() const;
    friend istream& operator>>(istream&, DIEM3C&);
    friend ostream& operator<<(ostream&, const DIEM3C&);
    double TinhChuViTamGiac(const DIEM3C&, const DIEM3C&) const;
    double TinhDienTichTamGiac(const DIEM3C&, const DIEM3C&) const;
};

DIEM3C::~DIEM3C()
{}

DIEM3C::DIEM3C(double x, double y, double z) : DIEM(x, y), z(z)
{}

DIEM3C::DIEM3C(const DIEM3C& d) : DIEM(d.x, d.y), z(d.z)
{}

double DIEM3C::GetZ() const
{
    return z;
}

void DIEM3C::SetZ(double z)
{
    this->z = z;
}

void DIEM3C::SetXYZ(double x, double y, double z)
{
    SetXY(x, y);
    this->z = z;
}

void DIEM3C::Nhap()
{
    DIEM::Nhap();
    cout << "Nhap cao do:";
    cin >> z;
}

void DIEM3C::Xuat() const
{
    DIEM::Xuat();
    cout << ", " << z;
}

bool DIEM3C::KiemTraTrung(const DIEM3C& d) const
{
    return DIEM::KiemTraTrung(d) && z == d.z;
}

void DIEM3C::DiChuyen(double dx, double dy, double dz)
{
    DIEM::DiChuyen(dx, dy);
    z += dz;
}

double DIEM3C::TinhKhoangCach(const DIEM3C& d) const
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2) + pow(z - d.z, 2));
}

DIEM3C DIEM3C::TimDiemDoiXung() const
{
    return DIEM3C(-x == 0 ? x : -x, -y == 0 ? y : -y, -z == 0 ? z : -z);
}

double DIEM3C::TinhChuViTamGiac(const DIEM3C& d1, const DIEM3C& d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return a + b + c;
}

double DIEM3C::TinhDienTichTamGiac(const DIEM3C& d1, const DIEM3C& d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

istream& operator>>(istream& is, DIEM3C& d)
{
    d.Nhap();
    cout << "Nhap cao do:";
    is >> d.z;
    return is;
}

ostream& operator<<(ostream& os, const DIEM3C& d)
{
    d.Xuat();
    os << ", " << d.z;
    return os;
}

class MAU
{
protected:
    int r, g, b;
public:
    ~MAU();
    MAU(int = 0, int = 0, int = 0);
    MAU(const MAU&);
    int GetR() const;
    int GetG() const;
    int GetB() const;
    void SetR(int);
    void SetG(int);
    void SetB(int);
    void SetRGB(int, int, int);
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const MAU&) const;
    friend istream& operator>>(istream&, MAU&);
    friend ostream& operator<<(ostream&, const MAU&);
};

MAU::~MAU() {}

MAU::MAU(int r, int g, int b) : r(r), g(g), b(b)
{}

MAU::MAU(const MAU& m) : r(m.r), g(m.g), b(m.b)
{}

int MAU::GetB() const
{
    return b;
}

int MAU::GetG() const
{
    return g;
}

int MAU::GetR() const
{
    return r;
}

void MAU::SetR(int r)
{
    while (r < 0 || r > 255)
    {
        cout << "Nhap lai thong so Red tu 0 den 255:";
        cin >> r;
    }
    this->r = r;
}

void MAU::SetG(int g)
{
    while (g < 0 || g > 255)
    {
        cout << "Nhap lai thong so Green tu 0 den 255:";
        cin >> g;
    }
    this->g = g;
}

void MAU::SetB(int b)
{
    while (b < 0 || b > 255)
    {
        cout << "Nhap lai thong so Blue tu 0 den 255:";
        cin >> b;
    }
    this->b = b;
}

void MAU::SetRGB(int r, int g, int b)
{
    SetR(r);
    SetG(g);
    SetB(b);
}

void MAU::Nhap()
{

    do
    {
        cout << "Nhap 3 thong so mau RGB tu 0 den 255" << endl;
        cout << "Nhap Red:";
        cin >> r;
        cout << "Nhap Green:";
        cin >> g;
        cout << "Nhap Blue:";
        cin >> b;
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) cout << "Vui long nhap RGB hop le" << endl;
    } while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}

void MAU::Xuat() const
{
    cout << " - Mau RGB(" << r << ", " << g << ", " << b << ")";
}

bool MAU::KiemTraTrung(const MAU& m) const
{
    return r == m.r && g == m.g && b == m.b;
}

istream& operator>>(istream& is, MAU& m)
{
    m.Nhap();
    return is;
}

ostream& operator<<(ostream& os, const MAU& m)
{
    m.Xuat();
    return os;
}

class DIEM3CMAU: public DIEM3C, MAU
{
public:
    ~DIEM3CMAU();
    DIEM3CMAU(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const DIEM3CMAU&) const;
    friend istream& operator>>(istream&, DIEM3CMAU&);
    friend ostream& operator<<(ostream&, const DIEM3CMAU&);
};

DIEM3CMAU::~DIEM3CMAU() {}

DIEM3CMAU::DIEM3CMAU(double x, double y, double z, int r, int g, int b) : DIEM3C(x, y, z), MAU(r, g, b)
{}

void DIEM3CMAU::Nhap()
{
    DIEM3C::Nhap();
    MAU::Nhap();
}

void DIEM3CMAU::Xuat() const
{
    cout << "(";
    DIEM3C::Xuat();
    cout << ")";
    MAU::Xuat();
}

bool DIEM3CMAU::KiemTraTrung(const DIEM3CMAU& d) const
{
    return DIEM3C::KiemTraTrung(d) && MAU::KiemTraTrung(d);
}

istream& operator>>(istream& is, DIEM3CMAU& d)
{
    d.Nhap();
    return is;
}

ostream& operator<<(ostream& os, DIEM3CMAU& d)
{
    d.Xuat();
    return os;
}

int main()
{
    DIEM3CMAU a, b, c;
    int number;
    double kq, dx, dy, dz;
    do {
        cout << "----CHUONG TRINH XU LY DIEM3CMAU------" << endl;
        cout << "1.Nhap 1 DIEM3CMAU" << endl;
        cout << "2.Nhap 2 DIEM3CMAU" << endl;
        cout << "3.Nhap 3 DIEM3CMAU" << endl;
        cout << "4.Kiem Tra Trung" << endl;
        cout << "5.Tinh Chu Vi" << endl;
        cout << "6.Tinh Dien Tich" << endl;
        cout << "7.Tim Doi Xung" << endl;
        cout << "8.Di Chuyen" << endl;
        cout << "9.Xuat 1 DIEM3CMAU" << endl;
        cout << "10.Xuat 3 DIEM3CMAU" << endl;
        cout << "0.Thoat chuong trinh" << endl;
        cout << "--------------------------------------" << endl;
        do {
            cout << "Chon chuc nang:";
            cin >> number;
            if (number < 0 || number > 10) cout << "Vui long nhap lai" << endl;
        } while (number < 0 || number > 10);
        switch (number) {
        case 1:
            cin >> a;
            break;
        case 2:
            cin >> a >> b;
            break;
        case 3:
            cin >> a >> b >> c;
            break;
        case 4:
            if (a.KiemTraTrung(b)) cout << "Diem A trung diem B" << endl;
            if (a.KiemTraTrung(c)) cout << "Diem A trung diem C" << endl;
            if (c.KiemTraTrung(b)) cout << "Diem B trung diem C" << endl;
            if (!(a.KiemTraTrung(b) && b.KiemTraTrung(c))) cout << "Diem A, B, C khong trung nhau" << endl;
            break;
        case 5:
            cout << "Chu vi cua tam giac la: " << a.TinhChuViTamGiac(b, c) << endl;
            break;
        case 6:
            cout << "Dien tich cua tam giac la: " << a.TinhDienTichTamGiac(b, c) << endl;
            break;
        case 7:
            cout << "Diem doi xung voi A" << a << " la A'(" << a.TimDiemDoiXung() << ")" << endl;
            cout << "Diem doi xung voi B" << b << " la B'(" << b.TimDiemDoiXung() << ")" << endl;
            cout << "Diem doi xung voi C" << c << " la C'(" << c.TimDiemDoiXung() << ")" << endl;
            break;
        case 8:
            cout << "Nhap dx:";
            cin >> dx;
            cout << "Nhap dy:";
            cin >> dy;
            cout << "Nhap dz:";
            cin >> dz;
            a.DiChuyen(dx, dy, dz);
            b.DiChuyen(dx, dy, dz);
            c.DiChuyen(dx, dy, dz);
            break;
        case 9:
            cout << "A" << a << endl;
            break;
        case 10:
            cout << "A" << a << endl;
            cout << "B" << b << endl;
            cout << "C" << c << endl;
            break;
        default:
            break;
        }
    } while (number != 0);
}