#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()
#define MOD 1000000007

int get_int()
{
	long long x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long Num[100001],Dp[100001][101][2];
std::vector<int> Map[100001];

int main()
{
	freopen("generals.in","r",stdin);
	freopen("generals.out","w",stdout);
	int n = gi,m = gi,mod = gi;
	for(int i = 0;i<n;i++)Num[i] = gi;
	for(int i = 0;i<m;i++)
	{
		int u,v;
		std::cin>>u>>v;
		u--;v--;
		Map[v].push_back(u);
	}
	for(int i = 0;i<n;i++)
		Dp[i][Num[i]%mod][0] = 1;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<mod;j++)
	for(int k = 0;k<Map[i].size();k++)
	{
		int v = Map[i][k];
		Dp[i][j][0] += Dp[v][((j-Num[i])%mod+mod)%mod][1];
		Dp[i][j][1] += Dp[v][((j+Num[i])%mod+mod)%mod][0];
		Dp[i][j][0] = Dp[i][j][0]%MOD;
		Dp[i][j][1] = Dp[i][j][1]%MOD;
	}
	for(int i = 0;i<n;i++)
		std::cout<<Dp[i][0][0]<<" "<<Dp[i][0][1]<<std::endl;
	int Ans = 0;
	for(int i = 0;i<n;i++)
		Ans = (Ans+Dp[i][0][1]+Dp[i][0][0])%MOD;
	std::cout<<Ans;
	return 0;
}
