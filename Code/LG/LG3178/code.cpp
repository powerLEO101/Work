#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define gi get_int()
#define for_edge(i,x) for(int i = x;i!=-1;i = Edges[i].Next)
inline int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[100001];

class Edge
{
public:
	int Next,To;
}Edges[100001 << 1];
int Head[100001 << 1],E_num = 0;
void Add_edge(int From,int To)
{
	Edges[E_num].Next = (Edge){Head[From],To};
	Head[From] = E_num++;
}

int Father[100001],Deep[100001],HSon[100001],Size[100001];
int Top[100001],Rnk[100001],Dfn[100001];
void Dfs1(int Now)
{
	Size[Now] = 1;
	for_edge(i,Now)
	{
		int v = Edges[i].To;
		if(v==Father[Now])continue;
		Father[v] = Now;
		Deep[v] = Deep[Now]+1;
		Dfs1(v);
		Size[Now]+=Size[v];
		if(HSon[Now]==-1||(Size[HSon[Now]]<Size[v]&&HSon[Now]!=-1))
			HSon[Now] = v;
	}
}
int Count;
void Dfs2(int Now,int top)
{
	Top[Now] = top;
	Dfn[Now] = Count;
	Rnk[Count++] = Now;
	if(HSON[Now]==-1)return;
	Dfs2(HSon[Now],top);
	for_edge(i,Now)
	{
		int To = Edges[Now].To;
		if(To==Father[Now]||To==HSon[Now])continue;
		Dfs2(To,To);
	}
}

class Node
{
public:
	int l,r,Val;
	Node* l_son,* r_son;
Node()
{
	l = r = Val = 0;
	
}
};

int main()
{
	memset(Head,-1,sizeof(Head));
	memset(HSon,-1,sizeof(HSon));
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1;
		Add_edge(u,v);
		Add_egde(v,u);
	}
	Dfs1(0);
	Dfs2(0,0);
	
	for(int i = 0;i<m;i++)
	{
		int Mode = gi;
		if(Mode==1)
		{
			int node = gi,Val = gi;
			Modify(node,Val);
		}
		else if(Mode==2)
		{
			int node = gi,Val = gi;
			Modify_tree(node,Val);
		}
		else if(Node==3)
		{
			int node = gi;
			std::cout<<Query(node);
		}
	}
	return 0;
}
