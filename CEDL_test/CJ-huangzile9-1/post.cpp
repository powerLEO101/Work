#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#define INF 0x3f3f3f3f

namespace file
{
	std::ifstream cin("post.in");
	std::ofstream cout("post.out");
}

int map[1001][1001];

int main()
{
	int n,m;
	file::cin>>n>>m;
	for(int i = 0;i<n+1;i++)
		for(int j = 0;j<n+1;j++)
			map[i][j] = INF;
	for(int i = 0;i<m;i++)
	{
		int u,v,w;
		file::cin>>u>>v>>w;u--;v--;
		map[u][v] = w;
	}
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			map[i][i] = 0;
	for(int k = 0;k<n;k++)
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		if(map[i][k]+map[k][j]<map[i][j])
			map[i][j] = map[i][k]+map[k][j];
	int Ans = 0;
	for(int i = 1;i<n;i++)Ans+=map[0][i];
	for(int i = 1;i<n;i++)Ans+=map[i][0];
	file::cout<<Ans;
	return 0;
}
