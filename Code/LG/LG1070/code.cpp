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

int Money[1001][1001],Spend[1001];
int Dp[1001];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,p = gi;
	for(int i = 0;i<n;i++)
	for(int j = 1;j<=m;j++)
		Money[i][j] = gi;
	for(int i = 0;i<n;i++)Spend[i] = gi;
	for(int i = 0;i<1001;i++)
		Dp[i] = -INF;
	Dp[0] = 0;
	for(int i = 1;i<=m;i++)
	for(int j = 0;j<n;j++)
	{
		int Last = j-1;
		if(Last==-1)Last = n-1;
		int Sum = Money[Last][i];
		for(int k = 1;k<=p;k++)
		{
			if(i-k<0)break;
			Dp[i]= std::max(Dp[i],Dp[i-k]+Sum-Spend[Last]);
			Last--;
			if(Last==-1)Last = n-1;
			Sum+=Money[Last][i-k];
		}
	}
	std::cout<<Dp[m];
	return 0;
}
