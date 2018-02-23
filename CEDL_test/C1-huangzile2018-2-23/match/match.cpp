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

long long Num[1001][1001];

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int u = gi,v = gi,w = gi;
		Num[u][v]+=w;
	}
	for(int i = 1;i<=n;i++)
	for(int j = 1;j<=n;j++)
		Num[i][j] = Num[i][j-1]+Num[i][j];
	long long Ans = 0;
	for(int i = 1;i<=n;i++)
	for(int j = i+1;j<=n;j++)
	{
		long long Max_Sum = 0;
		for(int k = 1;k<=n;k++)
		{
			Max_Sum = std::max(1ll*0,Max_Sum+Num[k][j]-Num[k][i-1]);
			Ans = std::max(Ans,Max_Sum);
		}
	}
	std::cout<<Ans;
	return 0;
}
