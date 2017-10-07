#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define gi get_int()
#define INF 0x3f3f3f3f
#define MID ((l+r)/2)

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}
namespace file
{
	std::ifstream cin("transport.in");
	std::ofstream cout("transport.out");
}

class Node{public:int v,w;};
std::vector<Node> Map[300001];
class Plan
{
public:
	int len,lca,st,ed;
}Q[300001];

int Up[300001][21],Deep[300001],deep[300001];
bool Vis[300001];
void Build_tree(int u)
{
	Vis[u] = true;
	for(std::vector<Node>::iterator it = Map[u].begin();it!=Map[u].end();it++)
	{
		if(Vis[it->v]==true)continue;
		Vis[it->v] = true;
		Up[it->v][0] = u;
		Deep[it->v] = Deep[u]+1;
		deep[it->v] = deep[u]+it->w;
		Build_tree(it->v);
	}
}
void move(int &u,int h)
{
	for(int i = 20;i>=0;i--)
		if(Deep[Up[u][i]]>=h)u = Up[u][i];
}
int Query(int u,int v)
{
	deep[u]>deep[v]?move(u,deep[v]):move(v,deep[u]);
	for(int i = 20;i>=0;i--)
		if(Up[u][i]!=Up[v][i])
			u = Up[u][i],
			v = Up[v][i];
	if(u!=v)u = Up[u][0],v = Up[u][0];
	return u;
}

int Temp[300001],Dist[300001];
void Dfs(int u)
{
	for(std::vector<Node>::iterator it  = Map[u].begin();it!=Map[u].end();it++)
	{
		if(it->v==Up[u][0])continue;
		Dfs(it->v);
		Dist[it->v] = it->w;
	}
}
void Get(int u)
{
	for(std::vector<Node>::iterator it = Map[u].begin();it!=Map[u].end();it++)
	{
		if(it->v==Up[u][0])continue;
		Get(it->v);
		Temp[u]+=Temp[it->v];
	}
}
bool check(int mid,int n,int m)
{
	memset(Temp,0,sizeof(Temp));
	int Max = -INF,Count = 0;
	for(int i = 0;i<m;i++)
	{
		if(Q[i].len<=mid)continue;
		Temp[Q[i].st]++;Temp[Q[i].ed]++;
		Temp[Q[i].lca]-=2;
		Count++;
		Max = std::max(Max,Q[i].len-mid);
	}
	if(Count==0)return true;
	Get(0);
	for(int i = 0;i<n;i++)
		if(Temp[i]==Count&&Dist[i]>=Max)return true;
	return false;
}

int main()
{
//	freopen("transport.in","r",stdin);
//	freopen("transport.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		Map[u].push_back((Node){v,w});
		Map[v].push_back((Node){u,w});
	}
	for(int i = 0;i<n;i++)
	{
		if(Vis[i]==true)continue;
		Deep[i] = deep[i] = 0;
		Build_tree(i);
		Up[i][0] = i;
	}
	for(int j = 1;j<=20;j++)
		for(int i = 0;i<n;i++)
			Up[i][j] = Up[Up[i][j-1]][j-1];
	for(int i = 0;i<m;i++)
	{
		Q[i].st = gi-1;
		Q[i].ed = gi-1;
		Q[i].lca = Query(Q[i].st,Q[i].ed);
		Q[i].len = deep[Q[i].st]+deep[Q[i].ed]-(2*deep[Q[i].lca]);
	}
	Dfs(0);
	int l = 0,r = 1e9;
	while(l<r)
	{
		if(check(MID,n,m))r = MID;
		else l = MID+1;	
	}
	std::cout<<l;
	return 0;
}
