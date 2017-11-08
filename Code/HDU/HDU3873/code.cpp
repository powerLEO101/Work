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
	while ((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if (ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int v,w;
};
std::vector<Node> Map[10001];
std::vector<int> Center[10001];
int Dis[10001],Save[10001];
bool inq[10001];

void SPFA(int S)
{
	std::queue<int> Q;
	inq[S] = true;
	Q.push(S);
	Dis[S] = 0;
	while(!Q.empty())
	{
		int u = Q.front();Q.pop();
		inq[u] = false;
		for(int i = 0;i<Map[u].size();i++)
		{
			int v = Map[u][i].v;
			if(Save[v]!=0||Dis[u]+Map[u][i].w>=Dis[v])continue;
			Dis[v] = Dis[u]+Map[u][i].w;
			for(int j = 0;j<Center[v].size();j++)
				Save[Center[i][j]]--;
			if(inq[v]==false)
			{
				inq[v] = true;
				Q.push(v);
			}
		}
	}
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T = gi;
	while(T--)
	{
		int n = gi,m = gi;
		memset(Dis,0x3f,sizeof(Dis));
		for(int i = 0;i<n;i++)Map[i].clear();
		for(int i = 0;i<n;i++)Center[i].clear();
		for(int i = 0;i<m;i++)
		{
			int u = gi-1,v = gi-1,w = gi;
			Map[u].push_back((Node){v,w});
			Map[v].push_back((Node){u,w});
		}
		for(int i = 0;i<n;i++)
		{
			Save[i] = gi;
			for(int j = 0;j<Save[i];j++)
				Center[j].push_back(i);
		}
		SPFA(0);
		std::cout<<Dis[n-1]<<std::endl;
	}
	return 0;
}
