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
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[50001];
int Deep[50001],Up[50001][30],Temp[50001];

void Dfs(int Now,int Pre)
{
	for(int i = 0;i<Map[Now].size();i++)
	{
		if(Map[Now][i]==Pre)continue;
		Deep[Map[Now][i]] = Deep[Now]+1;
		Up[Map[Now][i]][0] = Now;
		Dfs(Map[Now][i],Now);
	}
}
void move(int& u,int deep)
{
	if(Deep[u]==deep)return;
	for(int i = 25;i>=0;i--)
		if(Deep[Up[u][i]]>=deep)
			u = Up[u][i];
}
int LCA(int u,int v)
{
	Deep[u]>Deep[v]?move(u,Deep[v]):move(v,Deep[u]);
	if(u==v)return u;
	for(int i = 25;i>=0;i--)
		if(Up[u][i]!=Up[v][i])
			u = Up[u][i],
			v = Up[v][i];
	return Up[u][0];
}
void Get_ans(int Now,int Pre)
{
	for(int i = 0;i<Map[Now].size();i++)
	{
		if(Map[Now][i]==Pre)continue;
		Get_ans(Map[Now][i],Now);
		Temp[Now]+=Temp[Map[Now][i]];
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	Up[0][0] = 0;
	Dfs(0,-1);
	for(int j = 1;j<=25;j++)
	for(int i = 0;i<n;i++)
		Up[i][j] = Up[Up[i][j-1]][j-1];
	for(int i = 0;i<m;i++)
	{
		int u = gi-1,v = gi-1;
		Temp[u]++;Temp[v]++;
		int lca = LCA(u,v);
//		std::cout<<"$"<<lca+1<<std::endl;
		Temp[lca]--;
		if(lca!=0)Temp[Up[lca][0]]--;
	}
	Get_ans(0,-1);
	int Ans = -1;
	for(int i = 0;i<n;i++)Ans = std::max(Ans,Temp[i]);
	std::cout<<Ans;
	return 0;
}
