#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define INF 0x3f3f3f3f

int get_int()
{
	long long x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long P1[1001],P2[1001];
long long Dp[1001][1001];

int main()
{
	freopen("wing.in","r",stdin);
	freopen("wing.out","w",stdout);
	int n = gi;
	for(int i = 1;i<=n;i++)P1[i] = gi;
	for(int i = 1;i<=n;i++)P2[i] = gi;
	Dp[0][1] = Dp[0][2] = -INF;
	for(int i = 0;i<=n;i++)
	for(int j = i+1;j<=n;j++)
		Dp[i][j] = -INF;
	for(int i = 1;i<=n;i++)
	for(int j = 0;j<=i;j++)
	{
		Dp[i][j] = std::max(Dp[i-1][j-1]+(P1[i]-P2[i]),Dp[i-1][j]+P1[i]);
		if(Dp[i][j]<0)Dp[i][j] = -INF;
	}	
	for(int i = n;i>=1;i--)
	{
		if(Dp[n][i]>=0)
		{
			std::cout<<i;
			return 0;
		}
	}
	return 0;
}
