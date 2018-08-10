#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 100000
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
void Add_edge(int From,int To)
{
	Edges[E_num] = (Edge){Head[From],To};
	Head[From] = E_num++;
}

int Dfn[_],Low[_],Tot,Number,Belong[_],s[_];
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
		else 
			if(Belong[To]==0)Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	if(Dfn[Now]!=Low[Now])
		return;
	Belong[Now] = ++Number;
	s[Number]++;
	while(Stack.top()!=Now)
	{
		Belong[Stack.top()] = Number;
		s[Number]++;
		Stack.pop();
	}
	Stack.pop();
}

int Count[_];
int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1;
		Add_edge(To,From);
	}
	for(int i = 0;i<n;i++)
		if(Dfn[i]==0)Tarjan(i);
	for(int i = 0;i<n;i++)
		for_edge(j,i)
			if(Belong[i]!=Belong[Edges[j].To])
				Count[Belong[Edges[j].To]]++;
	int Ans = 0,x = 0;
	for(int i = 1;i<=Number;i++)
	{
		if(Count[i]==0)
		{
			Ans+=s[i];
			x++;
		}
	}
	if(x!=1)std::cout<<0;
	else std::cout<<Ans;
	return 0;
}
