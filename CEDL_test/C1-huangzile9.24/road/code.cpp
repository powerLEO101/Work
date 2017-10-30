#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f

int map[1001][1001],map1[1001][1001];

int main()
{
	int n,m;
	std::cin>>n>>m;
	memset(map,0x3f,sizeof(map));
	for(int i = 0;i<n;i++)
	{
		int u,v;
		std::cin>>u>>v;
		map[u][v] = map[v][u] = 1;
	}
	memcpy(map1,map,sizeof(map));
	for(int i = 0;i<m;i++)
	{
		int u,v;
		std::cin>>u>>v;
		map[u][v] = map[v][u] = 1;
		for(int k = 0;k<n;k++)
		for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			map[i][j] = std::min(map[i][j],map[i][k]+map[k][j]);
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
			{
			}
		memcpy(map,map1,sizeof(map1));
	}
	return 0;
}
