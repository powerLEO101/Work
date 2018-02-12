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
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[1001],Stone[1001],Dp[20000];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,S = gi,T = gi,m = gi;
	for(int i = 0;i<m;i++)
		Num[i] = gi;
	for(int i = 0;i<m-1;i++)
	{
		if(Num[i+1]-Num[i]<=100)continue;
		int Temp = Num[i+1]-(Num[i]+100);
		for(int j = i+1;j<m;j++)
			Num[j]-=Temp;
	}
	n = Num[m-1];
	for(int i = 0;i<m;i++)Stone[Num[i]]++;
	for(int i = 1;i<=n;i++)std::cout<<Stone[i]<<" ";
	std::cout<<std::endl;
	for(int i = 1;i<=n+t;i++)
	{
		Dp[i] = INF;
		if(i-S<=0)
		{
			Dp[i] = Stone[i];
			std::cout<<i<<std::endl;
		}
		else
			for(int j = i-S;j>=i-T&&j>=1;j--)
				Dp[i] = std::min(Dp[i],Dp[j]+Stone[i]);
	}
	for(int i = n;i<=)
	for(int i = 1;i<=n;i++)std::cout<<Dp[i]<<" ";
	std::cout<<std::endl;
	std::cout<<Dp[n];
	return 0;
}
