// Bài 3: Tìm số lớn nhất trong 3 số nguyên.

#include <iostream>
using namespace std;

struct SoLonNhat 
{
    int x;
    int y;
    int z;
};

void Nhap(SoLonNhat &so) 
{
    cout << "Nhap lan luot 3 so nguyen tu ban phim: ";
    cin >> so.x >> so.y >> so.z;
}

void Xuat(const SoLonNhat &so) 
{
    cout << "Ba so nguyen vua nhap la: " << so.x << ", " << so.y << ", " << so.z << endl;
}

int TimSoLonNhat(const SoLonNhat &so) 
{
    int max = so.x;
    if (so.y > max)
        max = so.y;
    if (so.z > max)
        max = so.z;
    return max;
}

int main() 
{
    SoLonNhat A;
    Nhap(A);
    Xuat(A);
    int max = TimSoLonNhat(A);
    cout << "So lon nhat trong 3 so nguyen tren la: " << max << endl;
    return 0;
}
