#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define RG register
#define gi get_int()
#define for_edge(i, x) for(RG int i=head[x];i;i=e[i].next)
inline int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}
inline void swap(int& x, int& y)
{y^=x^=y^=x;}

class edge
{
public:
	int next, to;
}e[500001 << 1];
int head[500001], e_num;
inline void Add_edge(int from,int to)
{
	e[++e_num]=(edge){head[from], to};
	head[from]=e_num;
}

int Size[500001],Father[500001],Deep[500001],HSon[500001],Top[500001];

void Dfs1(int Now)
{
	Size[Now] = 1;
	for_edge(i, Now)
	{
		int to=e[i].to;
		if(to==Father[Now])continue;
		Father[to] = Now;
		Deep[to] = Deep[Now]+1;
		Dfs1(to);
		Size[Now]+=Size[to];
		if(HSon[Now]==-1||(HSon[Now]!=-1&&Size[HSon[Now]]<Size[to]))
			HSon[Now] = to;
	}
}
void Dfs2(int Now,int top)
{
	Top[Now] = top;
	if(!HSon[Now])return;
	Dfs2(HSon[Now],top);
	for_edge(i, Now)
	{
		int to=e[i].to;
		if(to!=Father[Now]&&to!=HSon[Now]) Dfs2(to, to);
	}
}
inline int Query(int x,int y)
{
	while(Top[x]!=Top[y])
	{
		if(Deep[Top[x]]<Deep[Top[y]]) swap(x,y);
		x = Father[Top[x]];
	}
	return Deep[x]<Deep[y]?x:y;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	RG int n = gi,m = gi,s = gi;
	for(RG int i = 1;i<n;i++)
	{
		int u = gi,v = gi;
		Add_edge(u, v); Add_edge(v, u);
	}
	Father[s] = s;
	Dfs1(s);
	Dfs2(s,s);
	while(m--) printf("%d\n", Query(gi, gi));
	return 0;
}
