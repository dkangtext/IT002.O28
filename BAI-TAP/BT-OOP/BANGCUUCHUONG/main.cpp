#include "BCC.h"

int main()
{
	BCC bcc;
	int Chon;
	do
	{
		cout << "-----------CHUONG TRINH IN BANG CUU CHUONG-----------\n";
		cout << "1. Nhap Bang cuu chuong\n";
		cout << "2. Xuat Bang cuu chuong\n";
		cout << "3. In Bang cuu chuong thu m\n";
		cout << "4. In Bang cuu chuong tu m den n\n";
		cout << "5. In Bang cuu chuong tong hop\n";
		cout << "6. Thiet lap lai gia tri m, n\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "------------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> Chon;
		
		switch (Chon)
		{
		case 0:
			cout << "Dang thoat chuong trinh ......\n"; 
			break;

		case 1:
			bcc.Nhap();
			break;

		case 2:
			bcc.Xuat();
			break;

		case 3:
			bcc.InBCCm();
			break;

		case 4:
			bcc.InBCCmn();
			break;

		case 5:
			bcc.InBCCth();
			break;

		case 6:
			bcc.SetMN(3, 7);
			cout << "m moi = : " << bcc.GetM() << ", n moi = " << bcc.GetN() << endl;
			break;

		default:
			cout << "Ban chon sai.Moi ban chon lai !\n";
			break;
		}
	} while (Chon != 0);
}