#include<iostream>
#include<cstdio>
#include<algorithm>
#define _ 1000500
#define get_int() gi

int n,fa[_];
bool t[_];
struct ed{int u,v;
	bool operator < (const ed &A)
	{
		if(u==A.u)return v>A.v;
		return u<A.u;
	}
}l[_];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	std::cin>>n;
	for(int i=1;i<=10000;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		int x,y;
		std::cin>>x>>y;
		if(y<x)std::swap(x,y);
		l[i] = (ed){x,y};
	}
	std::sort(l+1,l+1+n);
	for(int i = 1;i<=n;++i)
	{
		int x = l[i].u,y = l[i].v;
		int fx = find(x),fy = find(y);
		if(fx!=fy)
		{
			if(fx>fy)std::swap(fx,fy);
			fa[fx] = fy;
			t[fx] = 1;
		}
		else t[fx] = 1;
	}
	int Ans = 0;
	for(int i=1;i<=n;++i)
	{
		if(t[i])Ans=i;
		else break;
	}
	std::cout<<Ans;
	return 0;
}
