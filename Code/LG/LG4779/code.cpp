#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
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

class heap
{
public:
	int Dist,Value;
}Heap[200000];
bool operator< (const heap& a,const heap& b)
{return a.Dist>b.Dist;}
int Length,n,m;
bool Vis[200000];
void Insert(int Dist,int Value)
{
	Heap[Length++] = (heap){Dist,Value};
	std::push_heap(Heap,Heap+Length);
}
int Delete()
{
	std::pop_heap(Heap,Heap+Length);
	return Heap[--Length].Value;
}

class Edge
{
public:
	int Next,To,Value;
}Edges[200000 << 1];
int E_num,Head[200000],Dist[200000];
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

void Dijkstra(int s)
{
	memset(Dist,0x3f,sizeof(Dist));
	Dist[s] = 0;
	Insert(Dist[s],s);
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
	File(code);
	memset(Head,-1,sizeof(Head));
	n = gi,m = gi;
	int s = gi-1;
	for(int i = 0;i<m;i++)
	{
		int From = gi-1,To = gi-1,Value = gi;
		Add_edge(From,To,Value);
	}
	Dijkstra(s);
	for(int i = 0;i<n;i++)
		if(Dist[i]==0x3f3f3f3f)std::cout<<"2147483647 ";
		else std::cout<<Dist[i]<<" ";
	return 0;
}
