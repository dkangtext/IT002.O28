#pragma once
#ifndef _MONEY
#define _MONEY

#include <iostream>
using namespace std;

class MONEY
{
private:
	int dollar;
	int cent;

public:
	MONEY();
	MONEY(int);
	MONEY(int, int);
	MONEY(const MONEY&);
	~MONEY();

	int GetDollar() const;
	int GetCent() const;

	void SetDollar(int);
	void SetCent(int);
	void SetMoney(int, int);

	friend istream& operator >> (istream&, MONEY&);
	friend ostream& operator << (ostream&, const MONEY&);

	double convertToVND(double) const;

	MONEY& operator++();
	MONEY operator++(int);
};

#endif // !_MONEY
