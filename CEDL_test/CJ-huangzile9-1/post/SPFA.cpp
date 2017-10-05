#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<vector>

class node
{
public
}

std::vector<>

int main()
{
	return 0;
}




SPFA
dis[s] = 0;
q.push(s)
while(!q.empty())
{
	int u = q.front();
	q.pop();
	for(int e = head[u];e!=-1;e = edge[u].next)
	{
		int v = edge[e].to;
		if(!vis[v])continue;
		if(dist[u]+1<dist[v])
	
	{
			dis[v] = dis[u]+1;
			q.push(v);
		}
	}
}


















