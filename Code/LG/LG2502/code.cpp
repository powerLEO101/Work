#include<iostream>
#include<cstdio>
#include<algorithm>
#define _ 10000
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
	int x,y,v;
}Edges[_];
bool operator< (const Edge& a,const Edge& b)
{
	return a.v<b.v;
}

int Father[_];
void init(){for(int i = 0;i<_;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
bool Query(int u,int v){return Get_father(u)==Get_father(v);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}

int Get_ans(int Now,int s,int t)
{
	init();
	if(Query(s,t)==true)return Now;
	for(int i = Now;i>=0;i--)
	{
		Merge(Edges[i].x,Edges[i].y);
		if(Query(s,t)==true)return i;
	}
	return -1;
}
int Gcd(int x,int y){return y==0?x:Gcd(y,x%y);}

int main()
{
	File(code);
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		Edges[i].x = gi;
		Edges[i].y = gi;
		Edges[i].v = gi;
	}
	int s = gi,t = gi;
	std::sort(Edges,Edges+m);
	int Ans1,Ans2;
	double Ans = 3000000.0;
	for(int i = 1;i<m;i++)
	{
		int Temp = Get_ans(i,s,t);
		if(Temp==-1)continue;
		if(((1.0*Edges[i].v)/Edges[Temp].v)<Ans)
		{
			Ans1 = Edges[i].v;
			Ans2 = Edges[Temp].v;
			Ans = (1.0*Edges[i].v)/Edges[Temp].v;
		}
	}
	if(Ans==3000000.0)
	{
		std::cout<<"IMPOSSIBLE";
		return 0;
	}
	int Temp = Gcd(Ans1,Ans2);
	Ans1/=Temp;
	Ans2/=Temp;
	if(Ans2==1)std::cout<<Ans1;
	else std::cout<<Ans1<<"/"<<Ans2;
	return 0;
}
