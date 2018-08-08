#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 300000
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
int Head[_],E_num;
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

int Dist[_],Count[_];
bool Vis[_];
void SPFA(int n)
{
	memset(Vis,0,sizeof(Vis));
	memset(Dist,0,sizeof(Dist));
	memset(Count,0,sizeof(Count));
	std::queue<int> Q;
	Q.push(0);
	Count[0] = 1;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		Vis[Now] = true;
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]>=Dist[Now]+Value)continue;
			if(++Count[To]>=n)
			{
				std::cout<<-1;
				return;
			}
			Dist[To] = Dist[Now]+Value;
			if(Vis[To]==false)
			{
				Vis[To] = true;
				Q.push(To);
			}
		}
		Vis[Now] = false;
	}
	long long Ans = 0;
	for(int i = 1;i<=n;i++)
		Ans+=Dist[i];
	std::cout<<Ans;
}

int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	int n = gi,k = gi;
	for(int i = 0;i<k;i++)
	{
		int Mod = gi,A = gi,B = gi;
		if(Mod==1)Add_edge(A,B,0),Add_edge(B,A,0);
		if(Mod==2)
			if(A==B){std::cout<<-1;return 0;}
			else Add_edge(A,B,1);
		if(Mod==3)Add_edge(B,A,0);
		if(Mod==4)
			if(A==B){std::cout<<-1;return 0;}
			else Add_edge(B,A,1);
		if(Mod==5)Add_edge(A,B,0);
	}
	for(int i = n;i>=1;i--)Add_edge(0,i,1);
	SPFA(n);
	return 0;
}
