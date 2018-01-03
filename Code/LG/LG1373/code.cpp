#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Map[801][801],Dp[801][801][20][2];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m =  gi,k = gi+1,Ans = 0;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++)
		Map[i][j] = gi,
		Dp[i][j][Map[i][j]%k][0] = 1;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++)
	for(int p = 0;p<=k;p++)
	{
		if(i!=0&&j!=0)
			Dp[i][j][p][0] = (Dp[i][j][p][0]+Dp[i-1][j][(p-Map[i][j]+k)%k][1]+Dp[i][j-1][(p-Map[i][j]+k)%k][1])%MOD,
			Dp[i][j][p][1] = (Dp[i][j][p][1]+Dp[i-1][j][(p+Map[i][j]+k)%k][0]+Dp[i][j-1][(p+Map[i][j]+k)%k][0])%MOD;
		else if(!(i==0&&j==0))
			if(i==0)
				Dp[i][j][p][0] = (Dp[i][j][p][0]+Dp[i][j-1][(p-Map[i][j]+k)%k][1])%MOD,
				Dp[i][j][p][1] = (Dp[i][j][p][1]+Dp[i][j-1][(p+Map[i][j]+k)%k][0])%MOD;
			else 
				Dp[i][j][p][0] = (Dp[i][j][p][0]+Dp[i-1][j][(p-Map[i][j]+k)%k][1])%MOD,
				Dp[i][j][p][1] = (Dp[i][j][p][1]+Dp[i-1][j][(p+Map[i][j]+k)%k][0])%MOD;
		if(p==0)Ans = (Ans+Dp[i][j][p][1])%MOD;
	}
	std::cout<<Ans;
	return 0;
}
