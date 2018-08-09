#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

void Tarjan(int Now = 0)
{
	Dfn[Now] = Low[Now] = Tot++;
	Stack.push(Now);
	for_edge(i,Now)
	{
		int To = Edges[i].To;
		if(Belong[To]!=-1)
		{
			Tarjan(To);
			Low[Now] = std::min(Low[Now],Low[To]);
		}
		else Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	if(!Dfn[Now]==Low[Now])return;
	while(Stack.top()!=Now)
	{
		Belong[Stack.top()] = Number;
		Stack.pop();
	}
	Belong[Stack.top()] = Number++;
	Stack.pop();
}

int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	memset(Belong,-1,sizeof(Belong));
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1;
		Add_edge(From,To);
	}
	Tarjan();
	return 0;
}
