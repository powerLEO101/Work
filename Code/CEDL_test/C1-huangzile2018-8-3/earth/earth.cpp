#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 20000
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
}Edges[_];
int E_num,Head[_],Ans,n,m;
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

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
int Dist[_];
bool Vis[_];
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
	Dist[1] = 0;
	Insert(Dist[1],1);
	while(Length)
	{
		int Now = Delete();
		for_edge(i,Now)
		{
			int To = Edges[i].To,Value = Edges[i].Value;
			if(Dist[To]<=Dist[Now]+Value)continue;
			Dist[To] = Dist[Now]+Value;
			Insert(Dist[To],To);
		}
	}
}
bool Judge(int x)
{
	for(int i = 0;i<E_num;i++)Edges[i].Value+=x;
	Dijkstra();
	Ans = Dist[n];
	for(int i = 0;i<E_num;i++)Edges[i].Value-=x;
	return Ans>=0;
}

int main()
{
	File(earth);
	int T = gi;
	while(T--)
	{
		memset(Head,-1,sizeof(Head));
		E_num = 0;
		n = gi,m = gi;
		for(int i = 0;i<m;i++)
		{
			int From = gi,To = gi,Value = gi;
			Add_edge(From,To,Value);
		}
		int l = 1,r = 1e6,Answer = -1,s;
		while(l<=r)
		{
			int Mid = (l+r)/2;
			if(Judge(Mid)==true)
			{
				r = Mid-1,Answer = Ans;
			}
			else l = Mid+1;
		}
		std::cout<<Answer;
	}
	return 0;
}
