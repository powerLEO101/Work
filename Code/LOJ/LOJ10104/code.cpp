#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 2000000
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

int Low[_],Dfn[_],Size[_],Tot,n,m;
bool Cut[_];
std::vector<int> Block[_];
void Tarjan(int Now)
{
	Dfn[Now] = Low[Now] = ++Tot;
	int Cnt = 0,Temp = 0;
	Size[Now] = 1;
	for_edge(i,Now)
	{
		int To = Edges[i].To;
		if(Dfn[To]==0)
		{
			Tarjan(To);
			Low[Now] = std::min(Low[Now],Low[To]);
			Size[Now]+=Size[To];
			Cnt++;
			if(Now!=0&&Dfn[Now]<=Low[To])
			{
				Temp+=Size[To];
				Cut[Now] = true;
				Block[Now].push_back(Size[To]);
			}
			if(Now==0)Block[Now].push_back(Size[To]);
		}
		else Low[Now] = std::min(Low[Now],Dfn[To]);
	}
	if(Now!=0&&Cut[Now]==true)Block[Now].push_back(n-Temp-1);
	if(Cnt==1&&Now==0)Block[Now].pop_back();
}

int main()
{
	File(code);
	n = gi,m = gi;
	memset(Head,-1,sizeof(Head));
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1;
		Add_edge(From,To);
		Add_edge(To,From);
	}
	Tarjan(0);
	for(int i = 0;i<n;i++)
	{
		int Len = Block[i].size();
		long long Ans = 2*(n-1);
		for(int j = 0;j<Len;j++)
			for(int k = j+1;k<Len;k++)
				Ans+=1ll*Block[i][j]*Block[i][k]*2;
		std::cout<<Ans<<std::endl;
	}
	return 0;
}
