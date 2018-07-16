#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
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

int Num[100005];

int main()
{
	File(maximum);
	int T = gi;
	while(T--)
	{
		int n = gi,c = gi,Ans = -INF;
		for(int i = 0;i<n;i++)
			Num[i] = gi;
		for(int i = 0;i<n;i++)
		for(int j = i+1;j<n;j++)
			if(c==1) Ans = std::max(Ans,Num[i]&Num[j]);
			else if(c==2) Ans = std::max(Ans,Num[i]^Num[j]);
			else if(c==3) Ans = std::max(Ans,Num[i]|Num[j]);
		std::cout<<Ans<<std::endl;
	}
	return 0;
}

