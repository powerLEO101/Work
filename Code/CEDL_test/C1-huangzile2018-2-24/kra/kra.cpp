#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<functional>
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

int Num[300001];

int main()
{
	freopen("kra.in","r",stdin);
	freopen("kra.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)Num[i] = gi;
	for(int i = 1;i<n;i++)Num[i] = std::min(Num[i],Num[i-1]);
	int Ans = n+1;
	while(m--)
	{
		int Plate = gi,l = 0,r = Ans-1;
		while(l<=r)
		{
			int Mid = (l+r)/2;
			if(Num[Mid]>=Plate)Ans = Mid,l = Mid+1;
			else r = Mid-1;
		}
		if(Ans<=0)
		{
			std::cout<<0;
			return 0;
		}
	}
	std::cout<<Ans+1;
	return 0;
}
