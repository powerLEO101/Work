#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
#define _ 100001
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[_],n,m;
long long Dist[_];
bool Vis[_];

int Prim()
{
	for(int i = 0;i<=n;i++)
		Dist[i] = -INF;
	memset(Vis,0,sizeof(Vis));
	long long Ans = 0;
	Dist[0] = 0;
	for(int i = 0;i<n;i++)
	{
		int Max;
		long long Max_Value = -INF;
		for(int i = 0;i<n;i++)
		{
			if(Vis[i]==true)continue;
			if(Dist[i]>Max_Value)
			{
				Max_Value = Dist[i];
				Max = i;
			}
		}
		Vis[Max] = true;
		Ans+=Max_Value;
		for(int i = 0;i<n;i++)
			if(i!=Max&&Vis[i]==false)
				Dist[i] = std::max(Dist[i],1ll*Num[Max]&Num[i]);
	}
	return Ans;
}

int main()
{
	File(mst);
	n = gi,m = gi;
	for(int i = 0;i<n;i++)Num[i] = gi;
	std::cout<<Prim();
	return 0;
}
