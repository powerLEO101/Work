#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[100001];
int dfn[100001],Count = 1,father[100001],Deep[100001];
int W[100001],Ans;
void Dfs(int Now,int Father)
{
	Deep[Now] = Deep[Father]+1;
	father[Now] = Father;
	if(Map[Now].size()==1)
	{
		dfn[Now] = Count++;
		Ans+=W[Now];
		return;
	}
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
	{
		if(*it==Father)continue;
		Dfs(*it,Now);
	}
}
int Query(int u,int v)
{
	int Ans = -0x3f3f3f3f;
	while(father[u]!=father[v])
	{
		if(Deep[u]>Deep[v])
		{
			Ans = std::max(W[father[u]],Ans);
			u = father[u];
		}
		else
		{
			Ans = std::max(W[father[v]],Ans);
			v = father[v];
		}
	}
	Ans = std::max(Ans,W[father[u]]);
	return Ans;
}

int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)
	{
		W[i] = gi;
		int t = gi;
		for(int j = 0;j<t;j++)
		{
			int v = gi-1;
			Map[i].push_back(v);
			Map[v].push_back(i);
		}
	}
	Dfs(0,-1);
	for(int i = 0;i<n;i++)
	{
		if(dfn[i]==0)continue;
		for(int j = 0;j<n;j++)
			if(dfn[j]!=0&&dfn[i]-dfn[j]==1)
			{
				Ans-=Query(i,j);
			}
	}
	std::cout<<Ans;
	return 0;
}
