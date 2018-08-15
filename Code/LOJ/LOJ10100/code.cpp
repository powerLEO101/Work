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
			Tarjan(To,Root);
			Low[Now] = std::min(Low[Now],Low[To]);
			if(Dfn[Now]<=Low[To])
			{
				Cnt++;
				if(Now!=Root||Cnt>1)Cut[Now] = true;
			}
		}
		Low[Now] = std::min(Low[Now],Dfn[To]);
	}
}

int main()
{
	File(code);
	int n = gi;
	while(n!=0)
	{
		memset(Head,-1,sizeof(Head));
		memset(Dfn,0,sizeof(Dfn));
		memset(Low,0,sizeof(Low));
		memset(Cut,0,sizeof(Cut));
		Tot = 0;
		E_num = 0;
		int From;
		std::cin>>From;
		while(From!=0)
		{
			while(true)
			{
				char ch = getchar();
				if(ch=='\n')break;
				int To;
				std::cin>>To;
				Add_edge(From,To);
				Add_edge(To,From);
			}
			std::cin>>From;
		}
		for(int i = 1;i<=n;i++)
			if(Dfn[i]==0)
				Tarjan(i,i);
		int Ans = 0;
		for(int i = 1;i<=n;i++)
			if(Cut[i]==true)
				Ans++;
		std::cout<<Ans<<std::endl;
		n = gi;
	}
	return 0;
}
