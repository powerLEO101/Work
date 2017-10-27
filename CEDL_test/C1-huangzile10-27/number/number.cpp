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
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int l,r,n,m;

int check(int x)
{
	int Count = 0;
	while(x!=0)
	{
		Count++;
		x/=m;
	}
	
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	l = gi;r = gi;n = gi;m = gi;
	std::cout<<check
	return 0;
}
