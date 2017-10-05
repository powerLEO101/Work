#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=300005;
struct edge
{
	int to,next,w;
}a[MAX<<1];
struct plan
{
	int s,t;
	int lca,dis;
}q[MAX];
int head[MAX],cnt;
int fa[MAX],dep[MAX],sz[MAX],son[MAX];
int top[MAX],tim[MAX],temp[MAX];
int N,M;
int gi()
{
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=-1,ch=getchar();
	while (ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
void Add(int u,int v,int w)
{
	a[++cnt]=(edge){v,head[u],w};
	head[u]=cnt;
}
void dfs1(int u,int f)
{
	sz[u]=1;
	for (int e=head[u];e;e=a[e].next)
	{
		int v=a[e].to;
		if (v==f) continue;
		dep[v]=dep[u]+a[e].w;
		tim[v]=a[e].w;
		fa[v]=u;
		dfs1(v,u);
		sz[u]+=sz[v];
		if (sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int up)
{
	top[u]=up;
	if (son[u]) dfs2(son[u],up);
	for (int e=head[u];e;e=a[e].next)
	{
		int v=a[e].to;
		if (v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int LCA(int u,int v)//树剖LCA
{
	while (top[u]!=top[v])
	{
		if (dep[top[u]]<dep[top[v]]) swap(v,u);
		u=fa[top[u]];
	}
	if (dep[u]<dep[v]) return u;
	else return v;
}
void dfs(int u)
{
	for (int e=head[u];e;e=a[e].next)
	{
		int v=a[e].to;
		if (v==fa[u]) continue;
		dfs(v);
		temp[u]+=temp[v];
	}
}
bool check(int mid)
{
	int mx=0,tot=0;
	memset(temp,0,sizeof(temp));
	for (int i=1;i<=M;i++)
	{
		if (q[i].dis>mid)
		{
			temp[q[i].s]++;temp[q[i].t]++;
			temp[q[i].lca]-=2;
			tot++;
			mx=max(mx,q[i].dis-mid);
		}
	}
	if (tot==0) return true;
	dfs(1);
	for (int i=1;i<=N;i++)
		if (temp[i]==tot&&tim[i]>=mx) return true;
	return false;
}
int main()
{
	N=gi();M=gi();
	for (int i=1;i<N;i++)
	{
		int u=gi(),v=gi(),w=gi();
		Add(u,v,w);Add(v,u,w);
	}
	dfs1(1,0);
	dfs2(1,1);
	for (int i=1;i<=M;i++)
	{
		q[i].s=gi();q[i].t=gi();
		q[i].lca=LCA(q[i].s,q[i].t);
		q[i].dis=dep[q[i].s]+dep[q[i].t]-(dep[q[i].lca]<<1);
	}
	int l=0,r=2147483647>>1;
	while (l<r)
	{
		int mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
