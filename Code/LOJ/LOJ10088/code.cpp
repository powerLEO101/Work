#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 10001
#define INF 0x3f3f3f3f
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

int Dist[_],Count[_],R[_],Time[_];
bool Vis[_];
bool SPFA(int Start,int End)
{
	for(int i = 0;i<_;i++)Dist[i] = -INF;
	memset(Vis,0,sizeof(Vis));
	memset(Count,0,sizeof(Count));
	std::queue<int> Q;
	Q.push(Start);
	Vis[Start] = true;
	Count[Start]++;
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
				Count[To]++;
				//std::cout<<To<<std::endl;
				//std::cout<<Count[To]<<std::endl;
				//std::cout<<std::endl;
				if(Count[To]>25)
					return false;
				Q.push(To);
			}
		}
		Vis[Now] = false;
	}
	return true;
}

int main()
{
	File(code);
	int T = gi;
	while(T--)
	{
		int Ans = -INF;
		for(int i = 1;i<=24;i++)R[i] = gi;
		int n = gi;
		bool Flag = false;
		memset(Time,0,sizeof(Time));
		for(int i = 0;i<n;i++)Time[gi+1]++;
		for(int x = 0;x<=n;x++)
		{
			memset(Head,-1,sizeof(Head));
			E_num = 0;
			for(int i = 1;i<=24;i++)Add_edge(i-1,i,0);
			for(int i = 1;i<=24;i++)Add_edge(i,i-1,-Time[i]);
			for(int i = 8;i<=24;i++)Add_edge(i-8,i,R[i]);
			for(int j = 1;j<=8;j++)Add_edge(j+16,j,R[j]-x);
			Add_edge(0,24,x);
			if(SPFA(0,25)==true)
			{
				Flag = true;
				std::cout<<x;
				break;
			}
		}
		if(Flag==false)std::cout<<"No Solution";
		std::cout<<std::endl;
	}
	return 0;
}
