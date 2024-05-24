#include"DIEMMAU.h"

void main()
{
	cout << "So diem mau 2C hien tai la: " << DIEMMAU::GetDem() << endl;
	DIEMMAU d1, d2(1), d3(1, 2), d4(1, 2, 100), d5(1, 2, 50, 150), d6(1, 2, 50, 150, 256), * d7 = new DIEMMAU;
	cout << "So diem mau 2C hien tai la: " << DIEMMAU::GetDem() << endl;
	cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\n d4: " << d4 << "\nd5: " << d5 << "\nd6: " << d6 << "\nd7: " << *d7 << endl;
	cout << "Nhap lai toa do diem mau 2C d1: \n";
	cin >> d1;
	cout << "d1_moi: " << d1 << endl;
	if (d1.DIEM::KiemTraTrung(*d7))
		cout << "d1 va d7 trung hoanh do va tung do\n";
	else
		cout << "d1 va d7 khong trung hoanh do va tung do\n";
	if (d1.MAU::KiemTraTrung(*d7))
		cout << "d1 va d7 trung mau\n";
	else
		cout << "d1 va d7 khong trung mau\n";
	if (d1.KiemTraTrung(*d7))
		cout << "d1 va d7 trung hoanh do, tung do va mau\n";
	else
		cout << "d1 va d7 khong trung hoanh do, tung do va mau\n";
	delete d7;
	cout << "So diem mau 2C hien tai la: " << DIEMMAU::GetDem() << endl;
}