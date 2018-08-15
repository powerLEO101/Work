#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 20005
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

int Ans = INF,s,t;
void Update(int x){if(x!=s&&x!=t)Ans = std::min(Ans,x);}
int Low[_],Dfn[_],Tot,Father[_];
bool Tarjan(int Now)
{
	bool Flag = false,Temp;
	if(Now==t)Flag = true;
	Dfn[Now] = Low[Now] = ++Tot;
	for_edge(i,Now)
	{
		int To = Edges[i].To;
		if(Father[Now]==To)continue;
		Father[To] = Now;
		if(Dfn[To]==0)
		{
			if(Temp = Tarjan(To))Flag = true;
			if(Temp==true&&Dfn[Now]<=Low[To])
				Update(Now);
			Low[Now] = std::min(Low[Now],Low[To]);
		}
		else 
			Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	return Flag;
}

int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	int n = gi;
	int From = gi,To = gi;
	while(!(From==0&&To==0))
	{
		Add_edge(From,To);
		Add_edge(To,From);
		From = gi,To = gi;
	}
	s = gi,t = gi;
	Tarjan(s);
	if(Ans==INF)std::cout<<"No solution";
	else std::cout<<Ans;
	return 0;
}
