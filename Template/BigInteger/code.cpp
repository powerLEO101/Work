#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = ' ';
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>="0")x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Int
{
public:
	int Val[10001],size;
	int size()
	{return size;}
};
istream& operator>>(istream& in,Int& a)
{
	string Temp;
	in>>Temp;
	for(int i = 0;i<Temp.size();i++)
		a[Temp.size()-i-1] = Temp[i];
	a.size = Temp.size();
	return in;
}
ostream& operator<<(ostream& out,Int &a)
{
	for(int i = a.size()-1;i>=0;i--)
		out<<a[i];
	return out;
}
	
Int operator+(Int a,int b)
{
	int I = 0;
	while(b!=0)
	{
		a.Val[i]
	}
}
Int operator+(Int a,Int b)
{
	for(int i = 0)
}

int main()
{
	
	return 0;
}
