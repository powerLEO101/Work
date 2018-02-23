#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define gi get_int()

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int People[50001],Dis[50001];
class Node
{
public:
	int v,w;
};
std::vector<Node> Map[50001];
bool Vis[50001];

void SPFA()
{
	memset(Dis,0x3f,sizeof(Dis));
	std::queue<int> Q;
	Q.push(0);
	Vis[0] = true;
	Dis[0] = 0;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		Vis[Now] = false;
		for(std::vector<Node>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
		{
			if(Dis[it->v]<=Dis[Now]+it->w)continue;
			Dis[it->v] = Dis[Now]+it->w;
			if(Vis[it->v]==false)
			{
				Vis[it->v] = true;
				Q.push(it->v);
			}
		}
	}
}

int main()
{
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)People[i] = gi;
	for(int i = 0;i<m;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		Map[u].push_back((Node){v,w});
	}
	SPFA();
	for(int i = 0;i<n;i++)
		if(Dis[i]==0x3f3f3f3f)
		{
			std::cout<<"No Answer";
			return 0;
		}
	long long Ans = 0;
	for(int i = 0;i<n;i++)
		Ans+=1ll*Dis[i]*People[i];
	std::cout<<Ans;
	return 0;
}
