#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 200005
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
	int Next,To;
}Edges[_];
int Head[_],E_num;
void Add_edge(int From,int To)
{
	Edges[E_num] = (Edge){Head[From],To};
	Head[From] = E_num++;
}

int Dfn[_],Low[_],Cut[_],Tot;
void Tarjan(int Now,int Root)
{
	Dfn[Now] = Low[Now] = ++Tot;
	int Cnt = 0;
	for_edge(i,Now)
	{
		int To = Edges[i].To;
		if(Dfn[To]==0)
		{
			Cnt++;
			Tarjan(To,Root);
			Low[Now] = std::min(Low[Now],Low[To]);
			if(Now!=Root&&Dfn[Now]<=Low[To])Cut[Now] = true;
		}
		Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	if(Now==Root&&Cnt>1)Cut[Now] = true;
}

int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1;
		Add_edge(From,To);
		Add_edge(To,From);
	}
	for(int i = 0;i<n;i++)
		if(Dfn[i]==0)
			Tarjan(i,i);
	int Ans = 0;
	for(int i = 0;i<n;i++)
		if(Cut[i]==true)
			Ans++;
	std::cout<<Ans<<std::endl;
	for(int i = 0;i<n;i++)
		if(Cut[i]==true)
			std::cout<<i+1<<' ';
	return 0;
}
