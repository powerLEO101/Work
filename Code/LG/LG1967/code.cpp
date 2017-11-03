#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<list>
#include<vector>
#define INF 0x3f3f3f3f

class edge
{
public:
	int u,v,w;
}edges[50000];
bool operator< (const edge& a,const edge& b){return a.w>b.w;}

int father[10001];
void init(){for(int i = 0;i<10001;i++)father[i] = i;}
int get_father(int u){return father[u]==u?u:father[u] = get_father(father[u]);}
void merge(int u,int v){father[get_father(u)] = get_father(v);}

class node
{
public:
	int v,w;
};
std::vector<node> map[10001];
int cnt = 0;
void add_edge(int u,int v,int w)
{
	map[u].push_back((node){v,w});
	map[v].push_back((node){u,w});
}

void kruskal(int m)
{
	std::sort(edges,edges+m);
	for(int i = 0;i<m;i++)
	{
		if(get_father(edges[i].u)==get_father(edges[i].v))continue;
		merge(edges[i].u,edges[i].v);
		add_edge(edges[i].u,edges[i].v,edges[i].w);
	}
}

int f[10001][50],g[10001][50],deep[10001];
bool vis[10001];
void build_tree(int u)
{
	vis[u] = true;
	for(std::vector<node>::iterator it = map[u].begin();it!=map[u].end();it++)
	{	
		if(vis[it->v]==false)
		{
			g[it->v][0] = it->w;
			f[it->v][0] = u;
			deep[it->v] = deep[u]+1;
			build_tree(it->v);
		}
	}
}

int move(int &u,int h)
{
//	std::cout<<"_______"<<std::endl<<deep[2]<<std::endl;
	int min = INF;
	for(int i = 20;i>=0;i--)
	{
		if(deep[f[u][i]]>=h)
		{
			min = std::min(min,g[u][i]);
			u = f[u][i];
//			std::cout<<u<<" "<<i<<" "<<g[u][i]<<std::endl;
		}
	}
	return min;
}

int Query(int x,int y)
{
	if(get_father(x)!=get_father(y))return -1;
	int min = INF;
	if(deep[x]!=deep[y])min = deep[x]>deep[y]?move(x,deep[y]):move(y,deep[x]);
	if(x==y)return min;
	for(int i = 20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			min = std::min(g[x][i],std::min(min,g[y][i]));
			x = f[x][i];
			y = f[y][i];
		}
	}
	min = std::min(g[x][0],std::min(min,g[y][0]));
	return min;
}

int main()
{
	init();
	int n,m,q;
	std::cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		std::cin>>edges[i].u>>edges[i].v>>edges[i].w;
		edges[i].u--;edges[i].v--;
	}
	kruskal(m);
	for(int i = 0;i<n;i++)
	{
		if(vis[i]==true)continue;
		deep[i] = 0;
		build_tree(i);
		f[i][0] = i;
		g[i][0] = INF;
	}
	for(int j = 1;j<=20;j++)
		for(int i = 0;i<n;i++)
		{
			f[i][j] = f[f[i][j-1]][j-1];
			g[i][j] = std::min(g[i][j-1],g[f[i][j-1]][j-1]);
		}
//	for(int i = 0;i<n;i++)
//	{
//		for(int j = 0;j<=20;j++)
//			std::cout<<i<<" "<<j<<" : "<<f[i][j]<<" "<<g[i][j]<<std::endl;
//	}
	std::cin>>q;
	for(int i = 0;i<q;i++)
	{
		int x,y;
		std::cin>>x>>y;x--;y--;
		std::cout<<Query(x,y)<<std::endl;
	}
	return 0;
}
