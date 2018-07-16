#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();	
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int map[10][10],Ans = INF;

void bfs(int n)
{
	std::queue<int> q;
	std::queue<int> cost;
	q.push(1);
	cost.push(0);
	while(!q.empty())
	{
		int x = q.front();q.pop();
		int y = cost.front();cost.pop();
		for(int i = 1;i<10;i++)
		{
			if(map[x][i]==INF)continue;
			if(i!=n)q.push(i),cost.push(y+map[x][i]);
			else
			{
				Ans = std::min();
			}
		}
	}	
}

int main()
{
	int n = gi,m = gi,k = gi,l = gi;
	memset(map,0x3f,sizeof(map));
	for(int i = 0;i<m;i++)
	{
		int u = gi,v = gi,w = gi;
		map[u][v] = std::min(map[u][v],w);
		map[v][u] = std::min(map[v][u],w);
	}
	
	return 0;
}
