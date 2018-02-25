#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define gi get_int()
#define RG register
#define for_edge(i,x) for(RG int i = Head[x];i!=-1;i = Edges[i].Next)

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Edge
{
public:
	int Next,To;
}Edges[250000<<1];
int Head[250000],E_num,Val[250000];
void Add_edge(int From,int To)
{
	Edges[E_num] = (Edge){Head[From],To};
	Head[From] = E_num++;
}

int Size[250000],Father[250000],Deep[250000],HSon[250000];
void Dfs1(int Now)
{
	Size[Now] = 1;
	for_edge(i,Now)
	{
		int to = Edges[i].To;
		if(to==Father[Now])continue;
		Father[to] = Now;Deep[to] = Deep[Now]+1;
		Dfs1(to);
		Size[Now]+=Size[to];
		if(HSon[Now]==-1||(HSon[Now]!=-1&&Size[HSon[Now]]<Size[to]))
			HSon[Now] = to;
	}
}
int Count,Dfn[250000],Rnk[250000],Top[250000];
void Dfs2(int Now,int top)
{
	Top[Now] = top;
	Dfn[Now] = Count;
	Rnk[Count++] = Now;
	if(HSon[Now]==-1)return;
	Dfs2(HSon[Now],top);
	for_edge(i,Now)
	{
		int to = Edges[i].To;
		if(to!=Father[Now]&&to!=HSon[Now])
			Dfs2(to,to);
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
	l_son = r_son = NULL;
}
}*Root = new Node;
void Build(Node* root)
{
	if(root->l==root->r-1)
	{
		root->Val = Val[Rnk[root->l]];
		return;
	}
	root->l_son = new Node;
	root->r_son = new Node;
	root->l_son->l = root->l;
	root->l_son->r = (root->l+root->r)/2;
	root->r_son->l = (root->l+root->r)/2;
	root->r_son->r = root->r;
	Build(root->l_son);
	Build(root->r_son);
	root->Val = root->l_son->Val+root->r_son->Val;
}
int Query(Node* root,int l,int r)
{
	if(root->l>=r||root->r<=l)return 0;
	if(l<=root->l&&r>=root->r)return root->Val;
	return Query(root->l_son,l,r)+Query(root->r_son,l,r);
}
void Modify(Node* root,int Index,int Val)
{
	if(root->l>Index||Index>=root->r)return;
	if(root->l==Index&&root->l==root->r-1)
	{
		root->Val = Val;
		return;
	}
	if(root->l==root->r-1)return;
	Modify(root->l_son,Index,Val);
	Modify(root->r_son,Index,Val);
	root->Val = root->l_son->Val+root->r_son->Val;
}

int Query_path(int x)
{
	int Ans = 0;
	while(Top[x]!=0)
		Ans+=Query(Root,Dfn[Top[x]],Dfn[x]+1),
		x = Father[Top[x]];
	Ans+=Query(Root,Dfn[0],Dfn[x]+1);
	return Ans;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi;
	memset(Head,-1,sizeof(Head));
	for(RG int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1;
		Add_edge(u,v);
		Add_edge(v,u);
		Val[i] = 1;
	}
	memset(HSon,-1,sizeof(HSon));
	Dfs1(0);
	Dfs2(0,0);
	Root->l = 0;Root->r = n;
	Build(Root);
	int m = gi+n-1;
	while(m--)
	{
		char Mode;
		std::cin>>Mode;
		if(Mode=='W')
		{
			int x = gi-1;
			std::cout<<Query_path(x)<<std::endl;
		}
		else
		{
			int x = gi-1,y = gi-1;
			Modify(Root,Dfn[y],0);
		}
	}
	return 0;
}
