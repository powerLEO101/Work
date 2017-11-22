#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()
#define INF 0x3f3f3f3f
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int v,w;
};
std::vector<Node> Map[500001];

int Dp[500001];
bool Vis[500001];
void Get_ans(int Now)
{
	int Count = 0,Sum = 0,Max = -INF;
	for(int i = 0;i<Map[Now].size();i++)
	{
		int v = Map[Now][i].v,w = Map[Now][i].w;
		if(Vis[v]==true)continue;
		Count++;
		Sum-=w;
		Max = std::max(Max,w);
		Vis[v] = true;
		Get_ans(v);
		Dp[Now]+=Dp[v];
	}
	if(Count==0)
	{
		std::cout<<Now+1<<std::endl;
		Dp[Now] = 0;
	}
	else
	{
		Sum+=Count*Max;
		std::cout<<Now+1<<" "<<Sum<<std::endl;
		Dp[Now]+=Sum;
	}
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi-1;
	Vis[m] = true;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		Map[u].push_back((Node){v,w});
		Map[v].push_back((Node){u,w});
	}
	Get_ans(m);
	for(int i = 0;i<n;i++)std::cout<<Dp[i]<<" ";
	return 0;
}
