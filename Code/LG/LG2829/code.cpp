#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')ch = getchar(),y = -1;
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class node
{
public:
	int v,w;
}father[50001];
std::vector<node> map[50001];
bool vis[50001],tag[50001];
int dis[50001],dis2[50001];

void spfa(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	vis[s] = true;dis[s] = 0;
	std::queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int now = q.front();q.pop();
		vis[now] = false;
		for(int i = 0;i<map[now].size();i++)
		{
			int v = map[now][i].v,w = map[now][i].w;
			if(tag[v]==true||dis[v]<=dis[now]+w)continue;
			dis[v] = dis[now]+w;
			if(vis[v]==false)
			{
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

int main()
{
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	int n = gi,m = gi,k = gi;
	for(int i = 0;i<m;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		map[u].push_back((node){v,w});
		map[v].push_back((node){u,w});
	}
	for(int i = 1;i<n-1;i++)
	{
		memset(vis,0,sizeof(vis));
		int Count = 0;
		for(int j = 0;j<map[i].size();j++)
		{
			if(vis[map[i][j].v]==1)continue;
			vis[map[i][j].v] = 1;
			Count++;
		}
		if(Count<k)tag[i] = true;
	}
	spfa(0);
	int min = dis[n-1],ans = 0x3f3f3f3f;
	for(int i = 0;i<n;i++)dis2[i] = dis[i];
	spfa(n-1);
	for(int i = 0;i<n;i++)
	{
		if(tag[i]==true)continue;
		for(int j = 0;j<map[i].size();j++)
		{
			int v = map[i][j].v,w = map[i][j].w;
			if(dis2[i]+dis[v]+w<=min||tag[v]==true)continue;
			ans = std::min(ans,dis2[i]+dis[v]+w);
		}
	}
	if(ans>=1e9)std::cout<<-1;
	else std::cout<<ans;
	return 0;
}
