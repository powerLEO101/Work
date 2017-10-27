#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
long long get_int()
{
	long long x = 0,y = 1;char ch = ' ';
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long l,r,n,m;

long long check(long long x)
{
	long long Count = 0;
	while(x!=0)
	{
		Count++;
		x/=m;
	}
	return Count;
}
long long Get(long long x)
{
	long long Count = 0;
	while(x!=0)
	{
		if(x%m==1)Count++;
		if(x%m!=0&&x%m!=1)return -1;
		x/=m;
	}
	return Count;
}
/*
 n
C 
 m
*/
long long C(long long n,long long m)
{
	long long Ans = 1;
	for(long long i = m;i>=m-n+1;i--)Ans*=i;
	for(long long i = n;i>=2;i--)Ans/=i;
	return Ans;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(std::cin>>l)
	{
		r = gi;n = gi;m = gi;
		long long Temp = l,len = check(l),Ans = 0;
		while(check(Temp)==len)
		{
			if(Get(Temp)==n)Ans++;
			Temp++;
		}
		l = Temp;Temp = r;
		len = check(r);
		while(check(Temp)==len)
		{
			if(Get(Temp)==n)
				Ans++;
			Temp--;
		}
		r = Temp;
		Ans+=C(n,check(r));
		Ans-=C(n,check(l)-1);
		std::cout<<Ans<<std::endl;
	}
	return 0;
}
