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
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int v,w;
}; 
std::vector<Node> Map[500001];
int f[500001];
long long Ans=0;

void Get_ans(int Now,int Pre)
{
	//f[Now] = 0;
	for(int i = 0;i<Map[Now].size();i++)
	{
		int v = Map[Now][i].v,w = Map[Now][i].w;
		if(v==Pre)continue;
		Get_ans(v,Now);
		f[Now] = std::max(f[Now],f[v]+w);
	}
}
void dfs(int Now,int Pre)
{
	for(int i = 0;i<Map[Now].size();i++)
	{
		int v = Map[Now][i].v,w = Map[Now][i].w;
		if(v==Pre)continue;
		Ans+=f[Now]-f[v]-w;
		dfs(v,Now);
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,s = gi-1;
	for(int i = 0;i<n-1;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		Map[u].push_back((Node){v,w});
		Map[v].push_back((Node){u,w});
	}
	Get_ans(s,-1);dfs(s,-1);
	std::cout<<Ans;
	return 0;
}
