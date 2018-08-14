#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 30000
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
void Add_edge(int From,int To)
{
	Edges[E_num] = (Edge){Head[From],To,E_num+1};
	Head[From] = E_num++;
	Edges[E_num] = (Edge){Head[To],From,E_num-1};
	Head[To] = E_num++;
}

int Dfn[_],Low[_],Belong[_],Count[_],Tot,Number;
bool Vis[_];
std::stack<int> Stack;
void Tarjan(int Now)
{
	Dfn[Now] = Low[Now] = ++Tot;
	Stack.push(Now);
	for_edge(i,Now)
	{
		if(Vis[Edges[i].Value]==true)
		{
			Vis[i] = true;
			continue;
		}
		Vis[i] = true;
		int To = Edges[i].To;
		if(Dfn[To]==0)
		{
			Tarjan(To);
			Low[Now] = std::min(Low[Now],Low[To]);
		}
		else Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	if(Dfn[Now]!=Low[Now])return;
	Belong[Now] = ++Number;
	while(Stack.top()!=Now)
	{
		Belong[Stack.top()] = Number;
		Stack.pop();
	}
	Stack.pop();
}

int main()
{
	File(code);
	int n = gi,m = gi;
	memset(Head,-1,sizeof(Head));
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1;
		Add_edge(From,To);
	}
	Tarjan(0);
	for(int i = 0;i<n;i++)
		for_edge(j,i)
		{
			int To = Edges[j].To;
			if(Belong[i]==Belong[To])continue;
			Count[Belong[To]]++;
		}
	int Ans = 0;
	for(int i = 1;i<=Number;i++)
		if(Count[i]==1)Ans++;
	std::cout<<(Ans+1)/2;
	return 0;
}
