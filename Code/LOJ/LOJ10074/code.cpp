#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define _ 10005
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
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
	int Next,To,Value,w;
}Edges[_<<1];
int E_num,Head[_],n,p,k;
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value,0};
	Head[From] = E_num++;
}

class Node
{
public:
	int Dist,Value;
}Heap[_];
bool operator< (const Node& a,const Node& b)
{
	return a.Dist>b.Dist;
}
int Dist[_],Length;
bool Vis[_];
void Insert(int d,int v)
{
	Heap[Length++] = (Node){d,v};
	std::push_heap(Heap,Heap+Length);
}
int Delete()
{
	std::pop_heap(Heap,Heap+Length);
	Heap[Length--];
	return Heap[Length].Value;
}
void Dijkstra()
{
	Length = 0;
	memset(Dist,0x3f,sizeof(Dist));
	memset(Vis,0,sizeof(Vis));
	Dist[0] = 0;
	Insert(0,0);
	while(Length)
	{
		int Now = Delete();
		if(Vis[Now]==true)continue;
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].w;
			if(Dist[To]<=Dist[Now]+Value)continue;
			Dist[To] = Dist[Now]+Value;
			Insert(Dist[To],To);
		}
	}
}

bool Judge(int x)
{
	for(int i = 0;i<E_num;i++)
		if(Edges[i].Value>x)Edges[i].w = 1;
	Dijkstra();
	for(int i = 0;i<E_num;i++)
		if(Edges[i].Value>x)Edges[i].w = 0;
	if(Dist[n-1]<=k)return true;
	return false;
}

int main()
{
	File(code);
	memset(Head,-1,sizeof(Head));
	n = gi,p = gi,k = gi;
	for(int i = 0;i<p;i++)
	{
		int From = gi-1,To = gi-1,Value = gi;
		Add_edge(From,To,Value);Add_edge(To,From,Value);
	}
	int l = 0,r = 1e9,Ans = -1;
	while(l<=r)
	{
		int MID = (l+r)/2;
		if(Judge(MID)==true)Ans = MID,r = MID-1;
		else l = MID+1;
	}
	std::cout<<Ans;
	return 0;
}
