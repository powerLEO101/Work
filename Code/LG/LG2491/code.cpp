#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define gi get_int()
#define INF 0x3f3f3f3f
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while ((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if (ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int v,w;
};
std::vector<Node> Map[300001];
bool Vis[300001];
int Ans[300001];

int Get(int start)
{
	int Val = -INF,Index;
	std::queue<int> Q,V;
	Q.push(start);
	V.push(0);
	memset(Vis,0,sizeof(Vis));
	Vis[start] = true;
	while(!Q.empty())
	{
		int Now = Q.front(),Now_v = V.front();
		Q.pop();V.pop();
		for(int i = 0;i<Map[Now].size();i++)
		{
			if(Vis[Map[Now][i].v]==true)continue;
			Vis[Map[Now][i].v] = true;
			Q.push(Map[Now][i].v);
			V.push(Now_v+Map[Now][i].w);
			if(Val<Now_v+Map[Now][i].w)
			{
				Val = Now_v+Map[Now][i].w;
				Index = Map[Now][i].v;
			}
		}
	}
	return Index;
}
bool Get_ans(int Now,int t)
{
	if(Now==t)
		return true;
	for(int i = 0;i<Map[Now].size();i++)
	{
		if(Vis[Map[Now][i].v]==true)continue;
		Vis[Map[Now][i].v] = true;
		if(Get_ans(Map[Now][i].v,t)==true)
		{
			Ans[Now] = Map[Now][i].v;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,s = gi;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		Map[u].push_back((Node){v,w});
		Map[v].push_back((Node){u,w});
	}
	int start = Get(0);
	int end = Get(start);
	memset(Vis,0,sizeof(Vis));
	Get_ans(start,end);
	int Temp = end;
	std::cout<<start+1<<" "<<end+1<<std::endl;
	for(int i = 0;i<n;i++)std::cout<<Ans[i]+1<<" ";
	std::cout<<std::endl;
	while(Ans[Temp]!=start)
	{
		std::cout<<Temp+1<<" ";
		Temp = Ans[Temp];
	}
	return 0;
}
