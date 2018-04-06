#include<iostream>
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

int Num[10001],Dp[10001];

int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int n = gi,Ans = -INF;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	for(int i = 0;i<10001;i++)Dp[i] = -INF;
	Dp[0] = Num[0];
	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
			if(Num[i]>=Num[j])
				Dp[i] = std::max(Dp[j]-((i-j)*(i-j-1))/2,Dp[i]);
		Dp[i]+=Num[i];
		Dp[i] = std::max(Dp[i],Num[i]-((i)*(i+1)/2));
		std::cout<<Dp[i]<<" ";
	}
	std::cout<<std::endl;
	for(int i = 0;i<n;i++)Ans = std::max(Ans,Dp[i]-((n-i)*(n-i-1))/2);
	std::cout<<Ans;
	return 0;
}
