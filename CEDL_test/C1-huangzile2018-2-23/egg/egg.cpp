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

int Dp[2002][2002];

int main()
{
	freopen("egg.in","r",stdin);
	freopen("egg.out","w",stdout);
	int n = gi,m = gi;
	Dp[0][0] = 1;
	for(int i = 1;i<=n;i++)
	for(int j = 1;j<=i&&j<=m;j++)
		Dp[i][j] = (Dp[i-j][j]+Dp[i-1][j-1])%19940714;
	int Ans = 0;
	for(int i = 1;i<=m;i++)Ans = (Ans+Dp[n][i])%19940714;
	std::cout<<Ans;
	return 0;
}
