#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 1000000
#define for_edge1(i,x) for(int i = Head1[x];i!=-1;i = Edges1[i].Next)
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
}Edges[_],Edges1[_];
int Head[_],E_num;
int Head1[_],E_num1;
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}
void Add_edge1(int From,int To,int Value)
{
	Edges1[E_num1] = (Edge){Head1[From],To,Value};
	Head1[From] = E_num1++;
}

int Dfn[_],Low[_],Belong[_],Sum[_],Money[_],Is[_],Number,Tot;
std::stack<int> Stack;
void Tarjan(int Now)
{
	Dfn[Now] = Low[Now] = ++Tot;
	Stack.push(Now);
	for_edge(i,Now)
	{
		int To = Edges[i].To;
		if(Dfn[To]==0)
		{
			Tarjan(To);
			Low[Now] = std::min(Low[Now],Low[To]);
		}
		else if(Belong[To]==0)
			Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	if(Dfn[Now]!=Low[Now])return;
	Belong[Now] = ++Number;
	Sum[Number] = Money[Now];
	while(Stack.top()!=Now)
	{
		Belong[Stack.top()] = Number;
		Sum[Number]+=Money[Stack.top()];
		Stack.pop();
	}
	Stack.pop();
}

int Dist[_];
bool Vis[_];
void SPFA()
{
	std::queue<int> Q;
	Q.push(0);
	Vis[0] = true;
	for(int i = 0;i<_;i++)Dist[i] = -INF;
	Dist[0] = 0;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		for_edge1(i,Now)
		{
			int To = Edges1[i].To,Value = Edges1[i].Value;
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
}

int main()
{
	File(save);
	int n = gi,m = gi;
	memset(Head,-1,sizeof(Head));
	memset(Head1,-1,sizeof(Head1));
	for(int i = 0;i<m;i++)
	{
		int From = gi,To = gi;
		Add_edge(From,To,0);
	}
	for(int i = 1;i<=n;i++)
		Money[i] = gi;
	int s = gi,p = gi;
	for(int i = 0;i<p;i++)
		Is[gi] = true;
	for(int i = 1;i<=n;i++)
		if(Dfn[i]==0)Tarjan(i);
	for(int i = 1;i<=n;i++)
		for_edge(j,i)
		{
			int To = Edges[j].To;
			if(Belong[i]==Belong[To])continue;
			Add_edge1(Belong[i],Belong[To],Sum[Belong[To]]);
		}
	Add_edge1(0,Belong[s],Sum[Belong[s]]);
	SPFA();
	int Ans = -INF;
	for(int i = 1;i<=n;i++)
	{
		if(Is[i]==false)continue;
		Ans = std::max(Ans,Dist[Belong[i]]);
	}
	std::cout<<Ans;
	return 0;
}
