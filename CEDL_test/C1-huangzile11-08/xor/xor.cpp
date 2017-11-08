#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while ((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if (ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int f[100001],g[100001];

int main()//long long!!!
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n = gi,Ans = 0;
	for(int i = 0;i<n;i++)f[i] = gi;
	for(int i = 0;i<n;i++)g[i] = gi;
	for(int i = 0;i<n;i++)
	{
		Ans = f[0]^g[i];
		for(int j = 1;j<=i;j++)	Ans^=(f[j]^g[i-j]);
		std::cout<<Ans<<" ";
	}
	return 0;
}

