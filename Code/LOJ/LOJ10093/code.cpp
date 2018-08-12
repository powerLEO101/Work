#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 20000
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
void Add_edge(int From,int To)
{
	Edges[E_num] = (Edge){Head[From],To};
	Head[From] = E_num++;
}

int Dfn[_],Low[_],Belong[_],Sum[_],In[_],Out[_],Tot,Number;
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
	Sum[Number] = 1;
	while(Stack.top()!=Now)
	{
		Belong[Stack.top()] = Number;
		Sum[Number]++;
		Stack.pop();
	}
	Stack.pop();
}

int main()
{
	File(code);
	int n = gi;
	memset(Head,-1,sizeof(Head));
	for(int i = 0;i<n;i++)
	{
		int From = i,To = gi-1;
		while(To!=-1)
		{
			Add_edge(From,To);
			To = gi-1;
		}
	}
	for(int i = 0;i<n;i++)
		if(Dfn[i]==0)Tarjan(i);
	for(int i = 0;i<n;i++)
	{
		for_edge(j,i)
		{
			int To = Edges[j].To;
			if(Belong[i]==Belong[To])continue;
			In[Belong[To]]++;
			Out[Belong[i]]++;
		}
	}
	int Ans1 = 0,Max1 = 0,Max2 = 0;
	for(int i = 1;i<=Number;i++)
	{
		if(In[i]==0)Ans1++,Max1++;
		if(Out[i]==0)Max2++;
	}
	if(Number==1)Max1 = Max2 = 0;
	std::cout<<Ans1<<std::endl<<std::max(Max1,Max2);
	return 0;
}
