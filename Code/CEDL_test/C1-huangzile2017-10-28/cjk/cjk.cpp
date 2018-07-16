#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define MOD 998244353
long long get_int()
{
	long long x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long a[100001],b[100001],c[100001];
int main()
{
	freopen("cjk.in","r",stdin);
	freopen("cjk.out","w",stdout);
	long long n = gi,m = gi,op = gi,A = 0,B = 0,C = 0;
	if(op==5||op==6)
	{
		for(long long i = 0;i<n;i++)A+=gi;
		for(long long i = 0;i<n;i++)B+=gi; 
		for(long long i = 0;i<n;i++)C+=gi;
		for(long long i = 0;i<m;i++)
		{   
			long long Mode = gi; 
			if(Mode==1)
			{   
			        long long l = gi-1,r = gi,x = gi; 
			        A = (A+(x*n))%MOD;
			}   
			if(Mode==2)
			{   
			        long long l = gi-1,r = gi,x = gi; 
			        B = (B*x)%MOD;
			}   
			if(Mode==3)
			{   
			        long long l = gi-1,r = gi,x = gi; 
			        C = (x*n)%MOD;
			}   
			if(Mode==4)
			{   
			        long long l = gi-1,r = gi; 
			        A = (A+B)%MOD;
			}   
			if(Mode==5)
			{   
			        long long l = gi-1,r = gi;
			        B = (B+C)%MOD;
			}   
			if(Mode==6)
			{   
			        long long l = gi-1,r = gi; 
			        C = (C+A)%MOD;
			}   
			if(Mode==7)
			{   
			        long long l = gi-1,r = gi,Ansa = 0,Ansb = 0,Ansc = 0;
			        std::cout<<A<<" "<<B<<" "<<C<<std::endl;
			}
		}
		return 0;
	}
	for(long long i = 0;i<n;i++)a[i] = gi;
	for(long long i = 0;i<n;i++)b[i] = gi;
	for(long long i = 0;i<n;i++)c[i] = gi;
	for(long long i = 0;i<m;i++)
	{
		long long Mode = gi;
		if(Mode==1)
		{
			long long l = gi-1,r = gi,x = gi;
			for(long long i = l;i<r;i++)a[i] = (a[i]+x)%MOD;
		}
		if(Mode==2)
		{
			long long l = gi-1,r = gi,x = gi;
			for(long long i = l;i<r;i++)b[i] = (b[i]*x)%MOD;
		}
		if(Mode==3)
		{
			long long l = gi-1,r = gi,x = gi;
			for(long long i = l;i<r;i++)c[i] = x;
		}
		if(Mode==4)
		{
			long long l = gi-1,r = gi;
			for(long long i = l;i<r;i++)a[i] = (a[i]+b[i])%MOD;
		}
		if(Mode==5)
		{
			long long l = gi-1,r = gi;
			for(long long i = l;i<r;i++)b[i] = (b[i]+c[i])%MOD;
		}
		if(Mode==6)
		{
			long long l = gi-1,r = gi;
			for(long long i = l;i<r;i++)c[i] = (c[i]+a[i])%MOD;
		}
		if(Mode==7)
		{
			long long l = gi-1,r = gi,Ansa = 0,Ansb = 0,Ansc = 0;
			for(long long i = l;i<r;i++)Ansa = (Ansa+a[i])%MOD;
			for(long long i = l;i<r;i++)Ansb = (Ansb+b[i])%MOD;
			for(long long i = l;i<r;i++)Ansc = (Ansc+c[i])%MOD;
			std::cout<<Ansa<<" "<<Ansb<<" "<<Ansc<<std::endl;
		}
	}
	return 0;
}
