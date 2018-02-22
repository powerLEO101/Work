#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define INF 0x3f3f3f3f

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[100001],Dp[2][100001];

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	int n = gi,X = gi,Y = gi,A = gi,B = gi;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	int Index = 0;
	for(int i = 0;i<=2*B;i++)
		Dp[0][i] = Dp[1][i] = -INF;
	Dp[0][]
	for(int i = 1;i<n;i++)
	{
		Index^=1;
		for(int j = 0;j<=2*B;j++)
		{
			Dp[i][j] = std::max(Dp[i-1][j],std::max(Dp[i-1][j-x]+));
		}
	}
	return 0;
}
