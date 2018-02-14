#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

int Num[1001],Stone[500001],Dp[500001];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,S = gi,T = gi,m = gi;
	for(int i = 1;i<=m;i++)
		Num[i] = gi;
	if(S==T)
	{
		int Ans = 0;
		for(int i = 1;i<=m;i++)
			if(Num[i]%S==0)Ans++;
		std::cout<<Ans;
		return 0;
	}
	std::sort(Num+1,Num+m+1);
	int MaxVal = S*T;
	for(int i = 1;i<=m;i++)
	{
		if(Num[i]-Num[i-1]<=MaxVal)continue;
		int Temp = Num[i]-(Num[i-1]+MaxVal);
		for(int j = i;j<=m;j++)
			Num[j]-=Temp;
	}
	n = Num[m]+101;
	memset(Dp,0x3f,sizeof(Dp));
	Dp[0] = 0;
	for(int i = 1;i<=m;i++)Stone[Num[i]] = 1;
	for(int i = 1;i<=n+T-1;i++)
	{
		for(int j = S;j<=T;j++)
			if(i-j>=0)
				Dp[i] = std::min(Dp[i],Dp[i-j]+Stone[i]);
	}
	int Ans = INF;
	for(int i = n;i<=n+T-1;i++)Ans = std::min(Ans,Dp[i]);
	std::cout<<Ans;
	return 0;
}

