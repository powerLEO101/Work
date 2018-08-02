#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 500000
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
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
}Edges[_<<2];
int E_num,Head[_<<1],n,m;
void add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}
int Num[_<<1];
void Add_edge(int From,int To)
{
	add_edge(From,To,0);
	add_edge(From+n,To+n,0);
	add_edge(From+n+n,To+n+n,0);
}

int Dist[_<<1];
bool Vis[_<<1];
void SPFA()
{
	for(int i = 0;i<4*n;i++)Dist[i] = -0x3f3f3f3f;
	Vis[1] = true;
	Dist[1] = 0;
	std::queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		Vis[Now] = false;
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]>=Dist[Now]+Value)continue;
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
	for(int i = 1;i<=n;i++)Num[i] = gi;
	for(int i = 0;i<m;i++)
	{
		int From = gi,To = gi,Mod = gi;
		if(Mod==1)Add_edge(From,To);
		else
		{
			Add_edge(From,To);
			Add_edge(To,From);
		}
	}
	for(int i = 1;i<=n;i++)
	{
		add_edge(i,i+n,-Num[i]);
		add_edge(i+n,i+n+n,Num[i]);
	}
	/*
	for(int i = 1;i<=3*n;i++)
	{
		std::cout<<i<<" : "<<std::endl;
		for_edge(j,i)
		{
			std::cout<<Edges[j].To<<" "<<Edges[j].Value<<std::endl;
		}
		std::cout<<std::endl;
	}
	*/
	add_edge(1,3*n,0);
	SPFA();
	std::cout<<Dist[n*3];
	return 0;
}
