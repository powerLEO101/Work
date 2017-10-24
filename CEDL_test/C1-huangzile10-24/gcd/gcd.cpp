#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<string>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = ' ';
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int gcd(long long x,long long y)
{
	return y!=0?gcd(y,x%y):x;
}

int x[1001];
std::string a1;
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	long long y,temp = 0,Index = 0,Ans = 0;
	std::cin>>a1;
	y = gi;
	if(y==0)
	{
		std::cout<<0;
		return 0;
	}
	for(int i = 0;i<a1.size();i++)x[i] = a1[i]-'0';
	while(temp<y&&Index<a1.size())temp = temp*10+x[Index++];
	for(;Index<a1.size();Index++)
	{
		Ans = Ans*10+temp%y;
		temp%=y;
		temp = temp*10+x[Index];
	}
	std::cout<<gcd(y,temp%y);
	return 0;
}
