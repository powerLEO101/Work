#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 20000
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

int Dfn[_],Low[_],Tot,Number;
int Belong[_],Min[_],Money[_];
std::stack<int> Stack;
void Tarjan(int Now)
{
	Stack.push(Now);
	Dfn[Now] = Low[Now] = ++Tot;
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
	Min[Number] = Money[Now];
	while(Stack.top()!=Now)
	{
		Belong[Stack.top()] = Number;
		Min[Number] = std::min(Min[Number],Money[Stack.top()]);
		Stack.pop();
	}
	Stack.pop();
}

int Count[_];
int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	int n = gi,p = gi;
	memset(Money,0x3f,sizeof(Money));
	for(int i = 0;i<p;i++)
		Money[gi-1] = gi;
	int m = gi;
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1;
		Add_edge(From,To);
	}
	for(int i = 0;i<n;i++)
	{
		if(Dfn[i]!=0||Money[i]==INF)continue;
		Tarjan(i);
	}
	for(int i = 0;i<n;i++)
		if(Dfn[i]==0)
		{
			std::cout<<"NO"<<std::endl<<i+1;
			return 0;
		}
	for(int i = 0;i<n;i++)
	{
		for_edge(j,i)
		{
			int To = Edges[j].To;
			if(Belong[i]==Belong[To])continue;
			Count[Belong[To]]++;
		}
	}
	int Ans = 0;
	for(int i = 1;i<=Number;i++)
	{
		if(Count[i]!=0)continue;
		Ans+=Min[i];
	}
	std::cout<<"YES"<<std::endl;
	std::cout<<Ans<<std::endl;
	return 0;
}
