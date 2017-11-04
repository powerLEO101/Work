/*
第一行n,m,s表示有n个点,m条边,源点为s
下面m行u,v,w,表示u-->v有一条单向边,从1开始
输出每个点到源点的距离
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int v,w;
};
std::vector<Node> Map[10001];
int Dis[10001],in[10001],n,m,s;
bool inq[10001];

void SPFA(int s)
{
	memset(Dis,0x3f,sizeof(Dis));
	Dis[s] = 0;
	std::queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for(int i = 0;i<Map[u].size();i++)
		{
			int v = Map[u][i].v;
			if(Dis[v]<=Dis[u]+Map[u][i].w)continue;
			Dis[v] = Dis[u]+Map[u][i].w;
			if(!inq[v])
			{
				inq[v] = true;
				Q.push(v);
			}
		}
	}
	for(int i = 0;i<n;i++)
		std::cout<<Dis[i]<<" ";
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	n = gi,m = gi,s = gi-1;
	for(int i = 0;i<m;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		Map[u].push_back((Node){v,w});
	}
	SPFA(s);
	return 0;
}

