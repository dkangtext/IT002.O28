#include "string.h"

int main() 
{
	int chon;
	CSTRING str, str1, str2, strtong;
	do
	{
		cout << "---------------- CHUONG TRINH XU LI CHUOI ----------------\n";
		cout << "Hay chon 1 trong nhung phuong thuc xu li sau:\n";
		cout << "1. Nhap 1 chuoi.\n";
		cout << "2. Xuat chuoi.\n";
		cout << "3. Cho biet do dai chuoi.\n";
		cout << "4. Dao nguoc chuoi.\n";
		cout << "5. In thuong tat ca cac ki tu trong chuoi.\n";
		cout << "6. In hoa tat ca cac ki tu trong chuoi.\n";
		cout << "7. Gan chuoi bang 1 chuoi moi.\n";
		cout << "8. Cong 2 chuoi.\n";
		cout << "9. So sanh 2 chuoi.\n";
		cout << "0. Thoat.\n";
		cout << "------------------------------------------------------------\n";
		cout << "Moi ban chon: ";
		cin >> chon;

		cin.ignore();

		switch (chon)
		{
		case 0:
			cout << "Dang thoat CT...\n";
			break;

		case 1:
			cout << "Nhap chuoi: ";
			cin >> str;
			break;
		
		case 2:
			cout << str << endl;
			break;
		
		case 3:
			cout << "Do dai cua chuoi hien tai la: " << str.length() << endl;
			break;
		
		case 4:
			str.daonguoc();
			cout << "Chuoi sau khi dao nguoc: " << str << endl;
			break;
		
		case 5:
			str.lower();
			cout << "Chuoi sau khi in thuong: " << str << endl;
			break;
		
		case 6:
			str.upper();
			cout << "Chuoi sau khi in hoa: " << str << endl;
			break;
		
		case 7:
			cout << "Nhap chuoi moi muon gan: ";
			cin >> str1;
			str = str1;
			cout << "Chuoi sau khi gan: " << str << endl;
			break;
		
		case 8:
			cout << "Nhap chuoi thu nhat: ";
			cin >> str1;
			cout << "Nhap chuoi thu hai: ";
			cin >> str2;
			strtong = str1 + str2;
			cout << "Chuoi sau khi cong: " << strtong << endl;
			break;
		
		case 9:
			cout << "Nhap chuoi can so sanh voi chuoi hien tai: ";
			cin >> str1;
			if (str > str1) cout << '"' << str << '"' << " > " << '"' << str1 << '"' << endl;
			else if (str == str1) cout << '"' << str << '"' << " = " << '"' << str1 << '"' << endl;
			else cout << '"' << str << '"' << " < " << '"' << str1 << '"' << endl;
			break;
		
		default:
			cout << "Ban chon sai. Moi chon lai.\n";
			break;
		}
	} while (chon != 0);
	return 0;
}