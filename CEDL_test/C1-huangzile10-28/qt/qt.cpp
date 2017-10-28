#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>

bool check(int n)
{
	int Count = 0;
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n%i==0)Count+=2;
		if(n/i==i&&n%i==0)Count--;
		if(Count>2)return false;
	}
	if(Count==2)return true;
	return false;
}

int main()
{
	freopen("qt.in","r",stdin);
	freopen("qt.out","w",stdout);
	int n;
	long long Ans = 0;
	std::cin>>n;
	for(int i = 6;i<=n;i++)
		if(check(i))Ans++;
	std::cout<<Ans;
	return 0;
}
