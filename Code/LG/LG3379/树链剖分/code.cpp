#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define gi get_int()
inline int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[500001];
int Size[500001],Father[500001],Deep[500001],HSon[500001],Top[500001],Dfn[500001],Rnk[500001];

void Dfs1(int Now)
{
	Size[Now] = 1;
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
	{
		if(*it==Father[Now])continue;
		Father[*it] = Now;
		Deep[*it] = Deep[Now]+1;
		Dfs1(*it);
		Size[Now]+=Size[*it];
		if(HSon[Now]==-1||Size[HSon[Now]]<Size[HSon[*it]])
			HSon[Now] = *it;
	}
}
int Count = 0;
void Dfs2(int Now,int top)
{
	Top[Now] = top;
	Dfn[Now] = Count;
	Rnk[Count++] = Now;
	if(HSon[Now]==-1)return;
	Dfs2(HSon[Now],top);
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
		if(*it!=Father[Now]&&*it==HSon[Now])
			Dfs2(*it,*it);
}
int Query(int x,int y)
{
	int Tx = Top[x],Ty = Top[y];
	while(Tx!=Ty)
	{
		if(Deep[Tx]>Deep[Ty])
			x = Father[Deep[Tx]];
		else
			y = Father[Deep[Ty]];
	}
	return x==y?x:Tx;
}

int main()
{
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	int n = gi,m = gi,s = gi-1;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	Father[s] = s;
	memset(HSon,-1,sizeof(HSon));
	Dfs1(s);
	Dfs2(s,s);
	for(int i = 0;i<m;i++)
	{
		int x = gi,y = gi;
		std::cout<<Query(x,y)<<std::endl;
	}
	return 0;
}
