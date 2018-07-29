#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Map[5001][5001],n,m,Dist[5001];
bool Vis[5001];

void Prim()
{
	int Ans = 0;
	memset(Dist,0x3f,sizeof(Dist));
	Dist[1] = 0;
	for(int x = 0;x<n;x++)
	{
		int Min = INF-1,k = -1;
		for(int i = 1;i<=n;i++)
			if(Vis[i]==false&&Min>Dist[i])Min = Dist[i],k = i;
		if(k==-1)
		{
			printf("orz");
			return;
		}
		Ans+=Dist[k];
		Vis[k] = true;
		for(int i = 1;i<=n;i++)
			if(Vis[i]==false&&Map[k][i]<Dist[i])Dist[i] = Map[k][i];
	}
	printf("%d",Ans);
}

int main()
{
	File(code);
	n = gi,m = gi;
	memset(Map,0x3f,sizeof(Map));
	for(int i = 0;i<m;i++)
	{
		int x = gi,y = gi,z = gi;
		Map[x][y] = Map[y][x] = std::min(Map[x][y],z);
	}
	Prim();
	return 0;
}
