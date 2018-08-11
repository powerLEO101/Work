#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 10001
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int l,r,id;
}Nodes[_];
bool operator< (const Node& a,const Node& b)
{
	if(a.r<b.r)return true;
	if(a.r>b.r)return false;
	if(a.r==b.r)return a.l>b.l;
}

int Num[_],Sum[_];
bool Vis[_];

int main()
{
	File(reunion);
	int n = gi,k = gi;
	for(int i = 1;i<n;i++)Num[i] = gi;
	for(int i = 1;i<n;i++)Sum[i] = Num[i];
	int Q = gi;
	for(int i = 0;i<Q;i++)Nodes[i].l = gi-1,Nodes[i].r = gi-1,Nodes[i].id = i;
	int Max_r = 0;
	for(int i = 0;i<Q;i++)
	{
		if(Max_r>Nodes[i].l)continue;
		Max_r = Nodes[i].r;
		Vis[Nodes[i].id] = true;
	}
	int Ans = 0;
	for(int i = 0;i<Q;i++)
	{
		if(Vis[i]==false)continue;
		Ans+=(Sum[Nodes[i].r]-Sum[Nodes[i].l]);
	}
	Ans = Num[n-1]-Ans;
	std::cout<<Ans<<std::endl;
	for(int i = 0;i<Q;i++)
		if(Vis[i]==true)std::cout<<'Y';
		else std::cout<<'N';
	std::cout<<std::endl<<0;
	return 0;
}
