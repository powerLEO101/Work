#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
#define _ 1000000
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
int SPFA(int Start,int End)
{
	std::queue<int> Q;
	Q.push(Start);
	Vis[Start] = true;
	for(int i = Start;i<=End;i++)Dist[i] = -INF;
	Dist[Start] = 0;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
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
		Vis[Now] = false;
	}
	return Dist[End];
}

int main()
{
	memset(Head,-1,sizeof(Head));
	File(code);
	int n = gi,Max = -INF,Min = INF;
	for(int i = 0;i<n;i++)
	{
		int a = gi,b = gi,c = gi;
		Add_edge(a-1,b,c);
		Max = std::max(Max,b);Min = std::min(Min,a-1);
	}
	for(int i = Min;i<=Max;i++)Add_edge(i,i+1,0),Add_edge(i+1,i,-1);
	std::cout<<SPFA(Min,Max)<<std::endl;
	return 0;
}
