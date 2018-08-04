#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 201
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define INF 0x3f3f3f3f
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
}Edges[_*_*_];
int E_num,Head[_*_*_];
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

int Num[_*_],n,k,A,B,C;

void Build(int x)
{
	if(x!=0)
	{
		for(int i = 0;i<n*n;i++)
		{
			if(Num[i]==1&&x!=k)continue;
			if((i+1)%n!=0)Add_edge(i+(x*n*n),i+1+((x-1)*n*n),0);
			if((i+n)<n*n)Add_edge(i+(x*n*n),i+n+((x-1)*n*n),0);
		}
	}
	for(int i = 0;i<n*n;i++)
	{
		if(x==0)
		{
			if(Num[i]==1)Add_edge(i+(x*n*n),i+(k*n*n),A);
			else Add_edge(i+(x*n*n),i+(k*n*n),C+A);
			continue;
		}
		if(Num[i]==1&&x!=k)Add_edge(i+(x*n*n),i+(k*n*n),A);
		else
		{
			if((i+1)%n!=1)Add_edge(i+(x*n*n),i-1+((x-1)*n*n),B);
			if((i-n)>=0)Add_edge(i+(x*n*n),i-n+((x-1)*n*n),B);
		}
	}
}

int Dist[_*_*_];
class heap
{
public:
	int Dist,Value;
}Heap[_*_*_];
int Length;
bool Vis[_*_*_];
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
	Dist[k*n*n] = 0;
	Insert(Dist[k*n*n],k*n*n);
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
	n = gi,k = gi,A = gi,B = gi,C = gi;
	for(int i = 0;i<n*n;i++)Num[i] = gi;
	for(int i = 0;i<=k;i++)
		Build(i);
	Dijkstra();
	int Ans = INF;
	for(int i = 0;i<=k;i++)Ans = std::min(Ans,Dist[(i+1)*n*n-1]);
	std::cout<<Ans;
	return 0;
}
