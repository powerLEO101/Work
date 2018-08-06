#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 10000
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
}Edges[_];
int Head[_],E_num;
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

int Dist[_];
bool Vis[_];
bool Flag;
void SPFA(int Now)
{
	if(Vis[Now]==true)
	{
		Flag = true;
		return;
	}
	Vis[Now] = true;
	for_edge(i,Now)
	{
		int To = Edges[i].To,Value = Edges[i].Value;
		if(Dist[To]<=Dist[Now]+Value)continue;
		Dist[To] = Dist[Now]+Value;
		SPFA(To);
		if(Flag==true)
		{
			Vis[Now] = false;
			return;
		}
	}
	Vis[Now] = false;
}

int main()
{
	File(code);
	int F = gi;
	while(F--)
	{
		memset(Head,-1,sizeof(Head));
		memset(Dist,0,sizeof(Dist));
		memset(Vis,0,sizeof(Vis));
		E_num = 0;
		int n = gi,m = gi,w = gi;
		for(int i = 0;i<m;i++)
		{
			int From = gi-1,To = gi-1,Value = gi;
			Add_edge(From,To,Value);
			Add_edge(To,From,Value);
		}
		for(int i = 0;i<w;i++)
		{
			int From = gi-1,To = gi-1,Value = gi;
			Add_edge(From,To,-Value);
		}
		for(int i = 0;i<n;i++)
		{
			SPFA(i);
			if(Flag==true)
			{
				std::cout<<"YES"<<std::endl;
				break;
			}
		}
		if(Flag==true)Flag = false;
		else std::cout<<"NO"<<std::endl;
	}
	return 0;
}
