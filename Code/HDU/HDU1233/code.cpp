#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
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

class Node
{
public:
	int v,w;
};
int Map[101][101];
int Dis[101];
bool Vis[101];

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
			if(Vis[j]==true||Dis[j]<=Map[Index][j])continue;
			Dis[j] = Map[Index][j];
		}
	}
	return Ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	while(std::cin>>n)
	{
		if(n==0)return 0;
		memset(Map,0x3f,sizeof(Map));
		for(int i = 0;i<n*(n-1)/2;i++)
		{
			int u = gi-1,v = gi-1,w = gi;
			Map[u][v] = Map[v][u] = std::min(w,Map[u][v]);
		}
		std::cout<<Prim(n)<<std::endl;
	}
	return 0;
}

