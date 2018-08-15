#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 200005
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
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
	int Next,To;
}Edges[_];
int Head[_],E_num;
void Add_edge(int From,int To)
{
	Edges[E_num] = (Edge){Head[From],To};
	Head[From] = E_num++;
}

int Low[_],Dfn[_],Tot,Count[_];
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
			if(Dfn[Now]<=Low[To]&&Now!=Root)
				Count[Now]++;
		}
		else Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	if(Now==Root&&Cnt>1)Count[Now] = Cnt;
}

int main()
{
	File(code);
	int n = gi,m = gi;
	while(!(n==0&&m==0))
	{
		memset(Head,-1,sizeof(Head));
		memset(Dfn,0,sizeof(Dfn));
		memset(Low,0,sizeof(Low));
		for(int i = 0;i<_;i++)Count[i] = 1;
		Tot = E_num = 0;
		for(int i = 0;i<m;i++)
		{
			int From = gi,To = gi;
			Add_edge(From,To);
			Add_edge(To,From);
		}
		int Cnt = 0;
		for(int i = 0;i<n;i++)
			if(Dfn[i]==0)
			{
				Count[i] = 0;
				Tarjan(i,i);
				Cnt++;
			}
		int Ans = -INF;
		for(int i = 0;i<n;i++)
			Ans = std::max(Ans,Cnt+Count[i]-1);
		std::cout<<Ans<<std::endl;
		n = gi,m = gi;
	}
	return 0;
}
