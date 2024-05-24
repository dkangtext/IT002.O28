#include "PHANSO.h"
#include <iostream>

using namespace std;

int main()
{
	PHANSO ps1, ps2(-3), ps3(-3,15);
	cout << "Phan so 1: "; ps1.Xuat(); cout << endl;
	cout << "Phan so 2: "; ps2.Xuat(); cout << endl;
	cout << "Phan so 3: "; ps3.Xuat(); cout << endl;

	cout << "Nhap phan so 1: ";
	ps1.Nhap();
	cout << "Phan so 1: "; ps1.Xuat(); cout << endl;
	
	// PHANSO A = ps1.Cong(ps2);
	PHANSO A = ps1 + ps2 + 1;
	cout << "A = ps1 + ps2 = "; A.Xuat(); cout << endl;
}