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
	while ((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if (ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[1001];
int Sum[1001];

void Dfs(int Now,int Pre)
{
	Sum[Now] = 1;
	for(int i = 0;i<Map[Now].size();i++)
	{
		if(Map[Now][i]==Pre)continue;
		Dfs(Map[Now][i],Pre);
		Sum[Now]+=Sum[Map[Now][i]];
	}
}
int Get_ans(int Now)
{
	for(int i = 0;i<n;i+++)
	return Ma;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,p = gi;
	for(int i = 1;i<p;i++)
	{
		int u = gi-1,v = gi-1;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	Dfs(0);
	std::cout<<Get_ans(9)
	return 0;
}
