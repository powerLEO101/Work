#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define gi get_int()
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
	int Next,To,Val;
}Edges[50000 << 1];
int Head[50000 << 1],E_num;
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

int n,m,b;

int Val[50000],Dist[50000];
bool Vis[50000];
bool Relax(int Now,int v,int w,int Limit)
{
	if(Val[v]>Limit)return false;
	if(Dist[v]>Dist[Now]+w)
	{
		Dist[v] = Dist[Now]+w;
		return true;
	}
	return false;
}
bool Judge(int Limit)
{
	memset(Vis,0,sizeof(Vis));
	memset(Dist,0x3f,sizeof(Dist));
	Dist[0] = 0;
	std::queue<int> Q;
	Q.push(0);
	Vis[0] = true;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		Vis[Now] = false;
		for_edge(i,Now)
		{
			int v = Edges[i].To,w = Edges[i].Val;
			if(Relax(Now,v,w,Limit)==true&&Vis[v]==false)
			{
				Q.push(v);
				Vis[v] = true;
			}
		}
	}
	if(Dist[n-1]<=b)return true;
	return false;
}

int main()
{
	memset(Head,-1,sizeof(Head));
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	n = gi;m = gi;b = gi;
	for(int i = 0;i<n;i++)
		Val[i] = gi;
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1,Value = gi;
		Add_edge(From,To,Value);
		Add_edge(To,From,Value);
	}
	if(Judge(INF)==false)
	{
		std::cout<<"AFK";
		return 0;
	}
	int l = 0,r = INF;
	while(l<=r)
	{
		int MID = (l+r)/2;
		if(Judge(MID)==true)r = MID-1;
		else l = MID+1;
	}
	std::cout<<l;
	return 0;
}
