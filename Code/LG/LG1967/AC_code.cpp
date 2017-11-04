#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define MAXN 10005
using namespace std;
int n,m;
struct T
{
	int v;
	int w;
	int next;
}edge[100005];
 
struct P
{
	int u;
	int v;
	int w;
}a[MAXN*5];
bool cmp(P x,P y)
{
	return x.w > y.w;
}
 
int head[MAXN],cnt;
int f[MAXN];
int find(int x)//并查集，判断是否在同一个集合内
{
	if(f[x] == x) return f[x];
	else return f[x] = find(f[x]);
}
void Add_edge(int u,int v,int w)//树连边
{
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
void Union(int u,int v)//联通块
{
	int x = find(u);
	int y = find(v);
	if(x != y) f[x] = y;
}
void kruskal()//最大生成树
{
	for(int i = 0; i <= MAXN; i++)
		f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u = a[i].u,v = a[i].v;
		if(find(u) != find(v))
		{
			Union(u,v);
			Add_edge(u,v,a[i].w);
			Add_edge(v,u,a[i].w);
		}
	}
}
 
int up[MAXN][25],g[MAXN][25],h[MAXN];//up[i][j]表示i的第2^j个祖先，g[i][j]表示i到i的第2^j个祖先路径上的最小权值，h[i]表示i在树中深度
bool vis[MAXN];
void build_tree(int u)
{
	vis[u] = 1;
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(!vis[v])
		{
			g[v][0] = edge[i].w; 
			up[v][0] = u;
			h[v] = h[u]+1;
			build_tree(v);
		}
	}
}
//把较深的一个点往上提，并记录他到祖先边权最小值，用他的一个祖先代替他
int move(int &u,int H)
{
	int res = 123546789;
	for(int i =20; i >= 0; i--)
	{
		if(h[up[u][i]] >= H)
		{
			res = min(res,g[u][i]);
			u = up[u][i];
		}
	}
	return res;
}
int query(int u,int v)//自认为是最难的地方
{
	if(find(u) != find(v)) return -1;
	int res = 123456789;
	if(h[u] != h[v]) res = h[u] > h[v]?move(u,h[v]):move(v,h[u]);
	if(u == v) return res;
	for(int i = 20; i >= 0; i--)//倍增的同时记录最小值，两个点越来越逼近公共祖先
	{
		if(up[u][i] != up[v][i])
		{
			res = min(res,min(g[u][i],g[v][i]));
			u = up[u][i];
			v = up[v][i];
		}
	}
	res = min(res,min(g[u][0],g[v][0]));//实际上到了这一步up[x][0] == up[y][0]因为它们的已经在同一棵子树里面
	//printf("up[u][0]: %d\n",up[u][0]);
	//printf("up[v][0]: %d\n",up[v][0]);
	return res;
}
 
int main()
{
	memset(head,-1,sizeof head);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+m+1,cmp);
	kruskal();
	 
	for(int i = 1; i <= n; i++)//构建森林，并且初始化h,up,g
	{
		if(!vis[i])
		{
			h[i] = 0;
			build_tree(i);
			g[i][0] = 123456789;
			up[i][0] = i;
		}
	}
	for(int i = 1; i <= 20; i++)//预处理up和g，i大了也没有什么影响
	{
		for(int j = 1; j <= n; j++)
		{
			up[j][i] = up[up[j][i-1]][i-1];
			g[j][i] = min(g[j][i-1],g[up[j][i-1]][i-1]);
		}
	}
	 
	int q;
	scanf("%d",&q);
	for(int i = 1; i <= q; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y));
	}
	return 0;
}
