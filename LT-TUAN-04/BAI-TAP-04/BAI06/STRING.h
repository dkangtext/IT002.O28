#pragma once
#ifndef _CSTRING
#include <iostream>

using namespace std;

class CSTRING
{
private:
	char* str;

public:
	CSTRING();
	CSTRING(char*);
	CSTRING(const CSTRING&);
	~CSTRING();

	int length() const;

	char* GetString() const;
	void SetString(char*);

	void daonguoc();
	void lower();
	void upper();

	CSTRING& operator=(const CSTRING&);

	friend CSTRING operator+(const CSTRING&, const CSTRING&);

	friend bool operator==(const CSTRING&, const CSTRING&);
	friend bool operator!=(const CSTRING&, const CSTRING&);
	friend bool operator>(const CSTRING&, const CSTRING&);
	friend bool operator>=(const CSTRING&, const CSTRING&);
	friend bool operator<(const CSTRING&, const CSTRING&);
	friend bool operator<=(const CSTRING&, const CSTRING&);

	friend istream& operator>>(istream& is, CSTRING& s);
	friend ostream& operator<<(ostream& os, CSTRING& s);
};

#endif

