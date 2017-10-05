#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<vector>
typedef unsigned long long ll;

class BigInteger
{
public:
	int BASE = 100000000;
	int WIDTH = 8;
	std::vector<ll> val;
	BigInteger(ll = 0){*this =;}
private:
	void operator= (const int&);
	void operator= (const BigInteger&);
	int operator% (const int&)const;
	bool operator< (const int&)const;
	bool operator> (const int&)const;
	bool operator< (const BigInteger&)const;
	bool operator> (const BigInteger&)const;
	istream operator>> (istream&,BigInteger&);
	istream operator>> (ifsrean&,int&);
	ostream operator<< (ostream&,BigInteger&);
	ostream operator<< (ostream&,int&);
	BigInteger operator+ (const BigInteger&)const;
	BigInteger operator- (const BigInteger&)const;
	BigInteger operator* (const BigInteger&)const;
	BigInteger operator^ (const BigInteger&)const;
	BigInteger operator+ (const int&)const;
	BigInteger operator- (const int&)const;
	BigInteger operator* (const int&)const;
	BigInteger operator/ (const int&)const;
	BigInteger operator^ (const int&)const;
	
}

int main()
{
	return 0;
}
