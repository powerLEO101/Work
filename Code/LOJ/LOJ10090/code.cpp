#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 200000
#define INF 0x3f3f3f3f
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Edge
{
public:
	int Next,To,Value;
}Edges[_];
int Head[_],E_num,n,m1,m2;
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

int Dist[_],Count[_];
bool Vis[_];
void SPFA(int S)
{
	std::queue<int> Q;
	memset(Vis, 0, sizeof(Vis));
	memset(Count, 0, sizeof(Count));
	memset(Dist,0x3f,sizeof(Dist));
	Dist[S] = 0;
	Vis[S] = true;
	Q.push(S);
	Count[S] = 1;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]<=Dist[Now]+Value)continue;
			Dist[To] = Dist[Now]+Value;
			if(Vis[To]==false)
			{
				Vis[To] = true;
				Count[To]++;
				if(Count[To]>=n)
				{
					std::cout<<-1;
					exit(0);
				}
				Q.push(To);
			}
		}
		Vis[Now] = false;
	}
}

int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	n = gi,m1 = gi,m2 = gi;
	for(int i = 0;i<m1;i++)
	{
		int From = gi,To = gi,Value = gi;
		if(From>=To)std::swap(From,To);
		Add_edge(From,To,Value);
	}
	for(int i = 0;i<m2;i++)
	{
		int From = gi,To = gi,Value = -gi;
		if(From<=To)std::swap(From,To);
		Add_edge(From,To,Value);
	}
	for(int i = 1;i<=n;i++)Add_edge(0,i,0);
	SPFA(0);
	SPFA(1);
	if(Dist[n]==INF)std::cout<<-2;
	else std::cout<<Dist[n];
	return 0;
}
