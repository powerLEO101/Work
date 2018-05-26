#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define gi get_int()
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int v,w;
};
std::vector<Node> Map[1001];
int Dis[1001],Cnt[1001],n;
bool inq[1001];
int SPFA(int s,int t)
{
	memset(Dis,0x3f,sizeof(Dis));
	Dis[s] = 0;
	std::queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for(int i = 0;i<Map[u].size();i++)
		{
			int v = Map[u][i].v;
			if(Dis[v]<=Dis[u]+Map[u][i].w)continue;
			Dis[v] = Dis[u]+Map[u][i].w;
			if(!inq[v])
			{
				if(Cnt[v]>n)return -1;
				inq[v] = true;
				Cnt[v]++;
				Q.push(v);
			}
		}
	}
	if(Dis[t]==0x3f3f3f3f)return -2;
	return Dis[t];
}
int main()
{
	File(layout);
	n = gi;
	int Len1 = gi,Len2 = gi;
	for(int i = 0;i<Len1;i++)
	{
		int a = gi,b = gi,c = gi;
		Map[a].push_back((Node){b,c});
	}
	for(int i = 0;i<Len2;i++)
	{
		int a = gi,b = gi,c = gi;
		Map[b].push_back((Node){a,-c});
	}
	std::cout<<SPFA(1,n);
	return 0;
}
