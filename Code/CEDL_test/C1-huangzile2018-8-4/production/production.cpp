#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 200005
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
	int Next,To,Value;
}Edges[_],Edges1[_];
int E_num,Head[_],Head1[_];
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num;
	Edges1[E_num] = (Edge){Head1[To],From,Value};
	Head1[To] = E_num++;
}

int Dist[_],Dist1[_];
bool Vis[_];
class heap
{
public:
	int Dist,Value;
}Heap[_];
int Length;
bool operator< (const heap& a,const heap& b)
{
	return a.Dist>b.Dist;
}
void Insert(int d,int v)
{
	Heap[Length++] = (heap){d,v};
	std::push_heap(Heap,Heap+Length);
}
int Delete()
{
	std::pop_heap(Heap,Heap+Length);
	return Heap[--Length].Value;
}
void Dijkstra()
{
	memset(Dist,0x3f,sizeof(Dist));
	memset(Vis,0,sizeof(Vis));
	Dist[0] = 0;
	Length = 0;
	Insert(Dist[0],0);
	while(Length)
	{
		int Now = Delete();
		if(Vis[Now]==true)continue;
		Vis[Now] = true;
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]<=Dist[Now]+Value)continue;
			Dist[To] = Dist[Now]+Value;
			Insert(Dist[To],To);
		}
	}
}

int main()
{
	File(production);
	memset(Head,-1,sizeof(Head));
	memset(Head1,-1,sizeof(Head1)); 
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1,Value = gi;
		Add_edge(From,To,Value);
	}
	Dijkstra();
	for(int i = 0;i<n;i++)Head[i] = Head1[i];
	for(int i = 0;i<E_num;i++)Edges[i] = Edges1[i];
	for(int i = 0;i<n;i++)Dist1[i] = Dist[i];
	Dijkstra();
	int q = gi;
	for(int i = 0;i<q;i++)
	{
		int From = gi-1,To = gi-1;
		if(Dist[From]==0x3f3f3f3f||Dist1[To]==0x3f3f3f3f)std::cout<<-1<<std::endl;
		else std::cout<<Dist[From]+Dist1[To]<<std::endl;
	}
	return 0;
}
