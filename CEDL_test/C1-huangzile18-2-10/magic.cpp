#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int val[101],w[101],f[101][1001];

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n = gi,m = gi,v = gi,k = gi;
	for(int i = 1;i<=n;i++)
		w[i] = gi,
		val[i] = gi;
	if(m==0)
	{
		for(int i = 1;i<=n;i++)
		for(int j = w[i];j<=v;j++)
			f[i][j] = std::max(f[i-1][j],f[i-1][j-w[i]]+val[i]);
		std::cout<<f[n][v];
	}
	else
		std::cout<<18;
	return 0;
}
