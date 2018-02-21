#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define MOD 1000

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Dp[10][2];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi;
	int Index = 0;
	Dp[1][0] = 1;
	for(int i = 1;i<n;i++)
	{
		Index^=1;
		Dp[1][Index] = (Dp[2][Index^1]*2)%MOD;
		Dp[2][Index] = (Dp[1][Index^1]+Dp[3][Index^1])%MOD;
		Dp[3][Index] = (Dp[2][Index^1]+Dp[4][Index^1])%MOD;
		Dp[4][Index] = (Dp[3][Index^1])%MOD;
	}
	std::cout<<(Dp[4][Index]*2)%MOD;
	return 0;
}
