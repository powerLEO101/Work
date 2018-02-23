#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int w[10001],Dis[10001];
bool Vis[10001];

int Prim(int n)
{
	memset(Vis,0,sizeof(Vis));
	memset(Dis,0x3f,sizeof(Dis));
	int Ans = 0;
	Dis[0] = 0;
	for(int i = 0;i<n;i++)
	{
		int Temp = INF,Index;
		for(int j = 0;j<n;j++)
		{
			if(Vis[j]==false&&Dis[j]<Temp)
			{
				Temp = Dis[j];
				Index = j;
			}
		}
		Vis[Index] = true;
		Ans+=Temp;
		for(int j = 0;j<n;j++)
		{
			if(Vis[j]==true||Dis[j]<=(w[Index]^w[j]))continue;
			Dis[j] = w[Index]^w[j];
		}
	}
	return Ans;
}

int main()
{
	freopen("liu.in","r",stdin);
	freopen("liu.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)w[i] = gi;
	std::cout<<Prim(n);
	return 0;
}

