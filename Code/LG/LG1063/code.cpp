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
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[300],Dp[300][300];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,Ans = -1;
	n = gi;
	for(int i = 1;i<=n;i++)
	{
		Num[i] = gi;
		Num[i+n] = Num[i];
	}
	for(int j = 2;j<2*n;j++)
	for(int i = j-1;j-i<n&&i>=1;i--)
	{
		for(int k = i;k<j;k++)
			Dp[i][j]  = std::max(Dp[i][j],Dp[i][k]+Dp[k+1][j]+Num[i]*Num[k+1]*Num[j+1]);  
		if(Dp[i][j]>Ans)Ans = Dp[i][j];
	}
	std::cout<<Ans;
	return 0;
}
