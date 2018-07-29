#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define MID ((l+r)/2)
using namespace std;
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
		int From,To,Value,Color;
}Edges[100005];
int Ans = -1,need,E_num,n,m;
bool operator< (const Edge& a,const Edge& b)
{
	if(a.Value==b.Value)return a.Color<b.Color;
	return a.Value<b.Value;  
}
void Add_edge(int From,int To,int Value,int Color)
{
	Edges[E_num++] = (Edge){From,To,Value,Color};
}

int Father[100005];
void Init(){for(int i = 0;i<n;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}
bool Query(int u,int v){return Get_father(u)==Get_father(v);}

bool Judge(int Val)
{
	Init();
	for(int i = 0;i<E_num;i++)
		if(Edges[i].Color==0)Edges[i].Value+=Val;
	sort(Edges,Edges+E_num);
	int Count = 0,ans = 0;
	for(int i = 0;i<E_num;i++)
	{
		if(Query(Edges[i].From,Edges[i].To))continue;
		if(Edges[i].Color==0)Count++;
		Merge(Edges[i].From,Edges[i].To);
		ans+=Edges[i].Value;
	}
	for(int i = 0;i<E_num;i++)
		if(Edges[i].Color==0)Edges[i].Value-=Val;
	ans-=Val*Count;
	if(Count>=need)
	{
		Ans = ans;
		return true;
	}
	else return false;
}
int main()
{
	File(code);
	n = gi,m = gi;
	need = gi;
	for(int i = 0;i<m;i++)
	{
		int u = gi,v = gi,w = gi,c = gi;
		Add_edge(u,v,w,c);
	}
	int l = -120,r = 120;
	while(l<=r)
	{
		if(Judge(MID))l = MID+1;
		else r = MID-1;
	}
	cout<<Ans<<endl;
	return 0;
}
