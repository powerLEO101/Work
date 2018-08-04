#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 2000000
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
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
int E_num,Head[_];
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

int Dist[_];
bool Vis[_];
void SPFA(int s)
{
	memset(Dist,0x3f,sizeof(Dist));
	memset(Vis,0,sizeof(Vis));
	std::deque<int> Q;
	Q.push_back(s);
	Dist[s] = 0;
	Vis[s] = true;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop_front();
		Vis[Now] = false;
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]<=Dist[Now]+Value)continue;
			Dist[To] = Dist[Now]+Value;
			if(Vis[To]==false)
			{
				Vis[To] = true;
				if(Dist[To]<=Dist[Q.front()])Q.push_front(To);
				else Q.push_back(To);
			}
		}
	}
}

int main()
{
	File(code);
	int n = gi,r = gi,p = gi,s = gi-1;
	memset(Head,-1,sizeof(Head));
	for(int i = 0;i<r;i++)
	{
		int From = gi-1,To = gi-1,Value = gi;
		Add_edge(From,To,Value);
		Add_edge(To,From,Value);
	}
	for(int i = 0;i<p;i++)
	{
		int From = gi-1,To = gi-1,Value = gi;
		Add_edge(From,To,Value);
	}
	SPFA(s);
	for(int i = 0;i<n;i++)
		if(Dist[i]==INF)std::cout<<"NO PATH"<<std::endl;
		else std::cout<<Dist[i]<<std::endl;
	return 0;
}
