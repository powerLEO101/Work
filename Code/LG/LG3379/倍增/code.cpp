#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 0x3f3f3f3f
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}
void print(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

std::vector<int> Map[500001];
int Up[500001][30],Deep[500001];

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
int Query(int u,int v)
{
	Deep[u]>Deep[v]?move(u,Deep[v]):move(v,Deep[u]);
	if(u==v)return u;
	for(int i = 25;i>=0;i--)
		if(Up[u][i]!=Up[v][i])
			u = Up[u][i],
			v = Up[v][i];
	return Up[u][0];
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,Q = gi,s = gi-1;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
//	memset(Deep,0x3f,sizeof(Deep));//当根节点不为s,或有多个时,就把这个加上
	Deep[s] = 0;
	Up[s][0] = s;
	Dfs(s,-1);
	/*
	for(int i = 0;i<n;i++)//当根节点不为s,或有多个时,就把这个加上
	{
		if(Deep[i]!=INF)continue;
		Deep[i] = 0;
		Up[i][0] = i;
		Dfs(i,-1);
	}
*/
	for(int j = 1;j<=25;j++)
	for(int i = 0;i<n;i++)
		Up[i][j] = Up[Up[i][j-1]][j-1];
	for(int i = 0;i<Q;i++)
	{
		int u = gi-1,v = gi-1;
		print(Query(u,v)+1);
		putchar('\n');
	}
	return 0;
}
