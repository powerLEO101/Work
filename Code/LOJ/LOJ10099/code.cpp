#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 10000
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
	int Next,To;
}Edges[_];
int Head[_],E_num;
void Add_edge(int From,int To)
{
	Edges[E_num] = (Edge){Head[From],To};
	Head[From] = E_num++;
}

int Low[_],Dfn[_],Tot,Number;
bool Cut[_];
std::stack<int> Stack;
std::vector<int> Block[_];
void Tarjan(int Now,int Root)
{
	Dfn[Now] = Low[Now] = ++Tot;
	Stack.push(Now);
	int Count = 0;
	for_edge(i,Now)
	{
		int To = Edges[i].To;
		if(Dfn[To]==0)
		{
			Count++;
			Tarjan(To,Root);
			Low[Now] = std::min(Low[Now],Low[To]);
			if((Now==Root&&Count>1)||(Now!=Root&&Dfn[Now]<=Low[To]))
				Cut[Now] = true;
			if(Dfn[Now]<=Low[To])
			{
				Block[++Number].clear();
				Block[Number].push_back(Now);
				while(Stack.top()!=Now)
				{
					Block[Number].push_back(Stack.top());
					Stack.pop();
				}
			}
		}
		Low[Now] = std::min(Low[Now],Dfn[To]);
	}
}

int main()
{
	File(code);
	int n = gi,T = 1;
	while(n!=0)
	{
		std::cout<<"Case "<<T++<<": ";
		memset(Head,-1,sizeof(Head));
		for(int i = 0;i<n;i++)
		{
			int From = gi,To = gi;
			Add_edge(From,To);
			Add_edge(To,From);
		}
		memset(Dfn,0,sizeof(Dfn));
		memset(Low,0,sizeof(Low));
		memset(Cut,0,sizeof(Cut));
		while(!Stack.empty())Stack.pop();
		Number = Tot = 0;
		for(int i = 1;i<=n;i++)
			if(Dfn[i]==0)
				Tarjan(i,i);
		long long Num = 0,Ans = 1;
		for(int i = 1;i<=Number;i++)
		{
			int Len = Block[i].size(),Count = 0;
			for(int j = 0;j<Len;j++)
				if(Cut[Block[i][j]]==true)Count++;
			if(Count==0)Num+=2,Ans = Len*(Len-1)/2;
			if(Count==1)Num++,Ans = Ans*(Len-1);
		}
		std::cout<<Num<<' '<<Ans<<std::endl;
		n = gi;
	}
	return 0;
}
