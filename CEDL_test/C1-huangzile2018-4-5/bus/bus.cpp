#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define gi get_int()
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
	int Next,To,Val,Index;
}Edges[4001];
int Head[4001],Val[4001],E_num;
void Add_edge(int From,int To,int val,int Index)
{
	Edges[E_num] = (Edge){Head[From],To,val,Index};
	Head[From] = E_num++;
}

int T[1001][1001],Size[1001],Vis[1001];

int Get_ans(int x)
{
	memset(Vis,0,sizeof(Vis));
	std::queue<int> Q,Time;
	Q.push(0);
	Time.push(0);
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		int Tim = Time.front();Time.pop();
		for_edge(i,Now)
		{
			int v = Edges[i].To,Val = Edges[i].Val,Index = Edges[i].Index;
			if(Tim%Size[Index]!=Val)continue;
			if(v==x)return Tim+1;
			if(Vis[v]>300)continue;
			Vis[v]++;
			Q.push(v);
			Time.push(Tim+1);
		}
		if(Vis[Now]>300)continue;
		Vis[Now]++;
		Q.push(Now);
		Time.push(Tim+1);
	}
	return -1;
}

int main()
{
	memset(Head,-1,sizeof(Head));
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		Size[i] = gi;
		for(int j = 0;j<Size[i];j++)T[i][j] = gi-1;
		for(int j = 0;j<Size[i]-1;j++)
			Add_edge(T[i][j],T[i][j+1],j,i);
		Add_edge(T[i][Size[i]-1],T[i][0],Size[i]-1,i);
	}
	for(int i = 1;i<n;i++)
		std::cout<<Get_ans(i)<<" ";
	return 0;
}
