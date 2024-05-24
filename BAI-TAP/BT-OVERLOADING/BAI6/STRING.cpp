#include "string.h"

CSTRING::CSTRING() :str(NULL) {}

CSTRING::CSTRING(char* s)
{
	int length = 0;
	while (s[length] != '\0') 
	{
		length++;
	}
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = s[i];
	}
	str[length] = '\0';
}

CSTRING::CSTRING(const CSTRING& other) 
{
	if (other.str != nullptr) 
	{
		int len = 0;
		while (other.str[len] != '\0') 
		{
			++len;
		}
		str = new char[len + 1];
		for (int i = 0; i < len; ++i) 
		{
			str[i] = other.str[i];
		}
		str[len] = '\0';
	}
	else 
	{
		str = nullptr;
	}
}

CSTRING::~CSTRING()
{
	delete[] str;
}

char* CSTRING::GetString() const 
{
	return str;
}

void CSTRING::SetString(char* s) 
{
	if (s != nullptr) 
	{
		int len = 0;
		while (s[len] != '\0') 
		{
			++len;
		}
		delete[] str;
		str = new char[len + 1];
		for (int i = 0; i < len; ++i) 
		{
			str[i] = s[i];
		}
		str[len] = '\0';
	}
	else 
	{
		delete[] str;
		str = nullptr;
	}
}

int CSTRING::length() const
{
	int length_ = 0;
	while (str[length_] != '\0')
	{
		length_++;
	}
	return length_;
}

void CSTRING::daonguoc()
{
	char* reversed = new char[length() + 1];
	int j = 0;
	for (int i = length() - 1; i >= 0; i--)
	{
		reversed[j] = str[i];
		j++;
	}
	reversed[j] = '\0';
	*this = CSTRING(reversed);
	delete[] reversed;
}

void CSTRING::lower() 
{
	char* lowercase = new char[length() + 1];
	for (int i = 0; i < length(); i++) 
	{
		lowercase[i] = (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] + 32) : str[i];
	}
	lowercase[length()] = '\0';
	*this = CSTRING(lowercase);
	delete[] lowercase;
}

void CSTRING::upper() 
{
	char* uppercase = new char[length() + 1];
	for (int i = 0; i < length(); i++) 
	{
		uppercase[i] = (str[i] >= 'a' && str[i] <= 'z') ? (str[i] - 32) : str[i];
	}
	uppercase[length()] = '\0';
	*this = CSTRING(uppercase);
	delete[] uppercase;
}

CSTRING& CSTRING::operator=(const CSTRING& s) 
{
	if (this != &s) 
	{
		delete[] str;
		if (s.str != nullptr) 
		{
			str = new char[s.length() + 1];
			for (int i = 0; i < s.length(); i++)
			{
				str[i] = s.str[i];
			}
			str[s.length()] = '\0';
		}
		else 
		{
			str = nullptr;
		}
	}
	return *this;
}

CSTRING operator+(const CSTRING& a, const CSTRING& b) 
{
	int len_a = a.length();
	int len_b = b.length();
	char* combined = new char[len_a + len_b + 1];
	int i = 0;

	for (int j = 0; j < len_a; ++j) 
	{
		combined[i++] = a.str[j];
	}

	for (int j = 0; j < len_b; ++j) 
	{
		combined[i++] = b.str[j];
	}

	combined[i] = '\0';
	CSTRING result(combined);
	delete[] combined;
	return result;
}

bool operator==(const CSTRING& a, const CSTRING& b) 
{
	int len_a = a.length();
	int len_b = b.length();
	if (len_a != len_b) 
	{
		return false;
	}
	for (int i = 0; i < len_a; ++i) 
	{
		if (a.str[i] != b.str[i]) 
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const CSTRING& a, const CSTRING& b) 
{
	return !(a == b);
}

bool operator>(const CSTRING& a, const CSTRING& b) 
{
	int len_a = a.length();
	int len_b = b.length();
	int len_min = len_a < len_b ? len_a : len_b;
	for (int i = 0; i < len_min; ++i) 
	{
		if (a.str[i] > b.str[i]) 
		{
			return true;
		}
		else if (a.str[i] < b.str[i]) 
		{
			return false;
		}
	}
	return len_a > len_b;
}

bool operator>=(const CSTRING& a, const CSTRING& b) 
{
	return (a == b) || (a > b);
}

bool operator<(const CSTRING& a, const CSTRING& b) 
{
	return !(a >= b);
}

bool operator<=(const CSTRING& a, const CSTRING& b) 
{
	return !(a > b);
}

istream& operator>>(istream& is, CSTRING& s) 
{
	char temp[1000];
	is.getline(temp, 100);
	delete[] s.str;
	int length = 0;
	while (temp[length] != '\0') 
	{
		length++;
	}
	s.str = new char[length + 1];
	s = CSTRING(temp);
	return is;
}

ostream& operator<<(ostream& os, CSTRING& s) 
{
	os << s.str;
	return os;
}

