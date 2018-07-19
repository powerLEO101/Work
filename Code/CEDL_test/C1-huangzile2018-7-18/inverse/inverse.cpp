#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define MOD 998244353
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[1001],n,p[1001],Num1[1001];

int ABS(int a){return a<0?-a:a;}
int calc1()
{
	int Ans = 0;
	for(int i = 0;i<n;i++)
		Ans+=ABS((i+1)-Num[i]);
	return Ans/2;
}
int calc2()
{
	for(int i = 0;i<n;i++)p[i] = Num[i];
	int Count = 0;
	for(int i = 0;i<n-1;i++)
		for(int j = 0;j<n-1-i;j++)
			if(p[j]>p[j+1])
			{
				Count++;
				std::swap(p[j],p[j+1]);
			}
	return Count;
}
bool Judge()
{
	for(int i = 0;i<n;i++)
		if(Num[i]>Num1[i])return true;
		else if(Num[i]<Num1[i])return false;
	return false;
}

int main()
{
	File(inverse);
	int T = gi;
	while(T--)
	{
		n = gi;
		long long Count = 0;
		for(int i = 0;i<n;i++)
			Num[i] = Num1[i] = gi;
		std::sort(Num,Num+n);
		while(std::next_permutation(Num,Num+n))
			if(Judge()&&calc1()==calc2())
				Count++;
		std::cout<<Count%MOD<<std::endl;
	}
	return 0;
}

