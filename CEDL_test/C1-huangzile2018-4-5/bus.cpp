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
}Edges[100000 << 1];
int Head[100000 << 1],E_num;
void Add_edge(int From,int To,int val,int Index)
{
	Edges[E_num] = (Edge){Head[From],To,val,Index};
	Head[From] = E_num++;
}

int T[100000 << 1],Dist[100000 << 1];
bool Vis[100000 << 1];

int Get_ans()
{
	memset(Dist,0x3f,sizeof(Dist));
	memset(Vis,0,sizeof(Vis));
	std::queue<int> Q;
	Q.push(0);
	Vis[0] = true;
	Dist[0] = 0;
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		for_edge(i,Now)
		{
			int v = Edges[i].To,Val = Edges[i].Val,Index = Edges[i].Index,w;
			if(Dist[Now]%Val<=Index)w = Index-(Dist[Now]%Val)+1;
			else w = Val-(Dist[Now]%Val-Index)+1;
			if(Dist[v]>Dist[Now]+w)
			{
				Dist[v] = Dist[Now]+w;
				if(Vis[v]==false)
				{
					Vis[v] = true;
					Q.push(v);
				}
			}
		}
		Vis[Now] = false;
	}
}

int main()
{
	memset(Head,-1,sizeof(Head));
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int K = gi;
		for(int j = 0;j<K;j++)T[j] = gi-1;
		T[K] = T[0];
		for(int j = 0;j<K;j++)Add_edge(T[j],T[j+1],K,j);
	}
	Get_ans();
	for(int i = 1;i<n;i++)std::cout<<(Dist[i]>1e9?-1:Dist[i])<<" ";
	return 0;
}
