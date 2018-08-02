#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 100005
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
}Edges[_<<1];
int E_num,Head[_];
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

int Dist[_],Dist1[_],n,m;
bool Vis[_];
void SPFA()
{
	memset(Dist,0x3f,sizeof(Dist));
	std::queue<int> Q;
	Vis[1] = true;
	Q.push(1);
	Dist[1] = 0;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		Vis[Now] = false;
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]<=Dist[Now]+Value)continue;
			Dist[To] = Dist[Now]+Value;
			if(Vis[To]==false)
			{
				Vis[To] = true;
				Q.push(To);
			}
		}
	}
	for(int i = 1;i<=n;i++)Dist1[i] = Dist[i];
	memset(Dist,0x3f,sizeof(Dist));
	memset(Vis,0,sizeof(Vis));
	Vis[n] = true;
	Q.push(n);
	Dist[n] = 0;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		Vis[Now] = false;
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]<=Dist[Now]+Value)continue;
			Dist[To] = Dist[Now]+Value;
			if(Vis[To]==false)
			{
				Vis[To] = true;
				Q.push(To);
			}
		}
	}

}

int main()
{
	File(code);
	n = gi,m = gi;
	memset(Head,-1,sizeof(Head));
	for(int i = 0;i<m;i++)
	{
		int From = gi,To = gi,Value = gi;
		Add_edge(From,To,Value);
		Add_edge(To,From,Value);
	}
	SPFA();
	int Ans = 0x3f3f3f3f;
	for(int i = 1;i<=n;i++)
	{
		for_edge(j,i)
		{
			int To = Edges[j].To,Value = Edges[j].Value;
			int Temp = Dist[To]+Dist1[i]+Value;
			if(Temp!=Dist[1])Ans = std::min(Ans,Temp);
		}
	}
	std::cout<<Ans;
	return 0;
}
