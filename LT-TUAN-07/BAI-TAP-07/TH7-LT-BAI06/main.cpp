#include "GIASUC.h"
#include "BO.h"
#include "CUU.h"
#include "DE.h"

int main()
{
	int bo, de, cuu;
	cout << "Nhap so luong bo: ";
	cin >> bo;
	cout << "Nhap so luong cuu: ";
	cin >> cuu;
	cout << "Nhap so luong de: ";
	cin >> de;

	int n = bo + cuu + de;

	GIASUC** list = new GIASUC*[n];

	for (int i = 0; i < bo; i++)
	{
		list[i] = new BO;
	}

	for (int i = bo; i < (cuu + bo); i++)
	{
		list[i] = new CUU;
	}

	for (int i = cuu+bo; i < n; i++)
	{
		list[i] = new DE;
	}

	for (int i = 0; i < n; i++)
	{
		list[i]->Keu();
	}

	int Sum1 = 0, Sum2 = 0, Sum3 = 0;

	for (int i = 0; i < n; i++)
	{
		if (list[i]->getLoai() == 1)Sum1 += list[i]->SinhCon();
		else if (list[i]->getLoai() == 2)Sum2 += list[i]->SinhCon();
		else if (list[i]->getLoai() == 3)Sum3 += list[i]->SinhCon();
	}

	cout << "So luong gia suc trong nong trai sau khi sinh con lai: " << endl;
	cout << "Bo: " << bo + Sum1 << endl;
	cout << "Cuu: " << cuu + Sum2 << endl;
	cout << "De: " << de + Sum3 << endl;

	int Sua = 0;

	for (int i = 0; i < n; i++)
	{
		Sua += list[i]->Sua();
	}

	cout << "Tong so lit sua: " << Sua << endl;
}