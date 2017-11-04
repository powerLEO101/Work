#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstdio>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long f[2010][2010],s[2010][2010];

int main()
{
	int t,k,u,v;
	t = gi;k = gi;
	for(int i = 0;i<2002;i++)
		f[i][i] = f[i][0] = 1;
	for(int i = 1;i<2002;i++)
	for(int j = 1;j<i;j++)
		f[i][j] = (f[i-1][j-1]+f[i-1][j])%k;
	for(int i = 1;i<2002;i++)
		for(int j = 1;j<2002;j++)
		{
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
			if(f[i][j]==0&&j<=i)
				s[i][j]++;
		}
	for(int i = 0;i<t;i++)
	{
		u = gi;v = gi;
		std::cout<<s[u][v]<<std::endl;
	}
	return 0;
}
