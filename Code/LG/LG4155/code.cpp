#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define _ 500001
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

int n,m,p;
class Node
{
public:
	int l,r,id;
}Nodes[_];
bool operator< (const Node& a,const Node& b)
{
	return a.l<b.l;
}
int Find(int l,int r,int Key)
{
	int ans = p;
	while(l<=r)
	{
		int MID = (l+r)/2;
		if(Nodes[MID].l<=Key)l = MID+1,ans = MID;
		else r = MID-1;
	}
	return ans;
}

int Up[_][30],Ans[_];

int main()
{
	File(code);
	p = n = gi,m = gi;
	for(int i = 0;i<n;i++)
	{
		int c = gi,d = gi;
		if(c>d)Nodes[i].l = c,Nodes[i].r = d+m;
		else 
		{
			Nodes[i].l = c,Nodes[i].r = d;
			Nodes[p].l = c+m;Nodes[p].r = d+m;
			Nodes[p++].id = i;
		}
		Nodes[i].id = i;
	}
	Nodes[p].r = 2e9;
	std::sort(Nodes,Nodes+p);
	for(int i = 0;i<=p;i++)
		for(int j = 0;j<=30;j++)
			Up[i][j] = p;
	for(int i = 0;i<p;i++)
		Up[i][0] = Find(i+1,p,Nodes[i].r);
	for(int j = 1;j<30;j++)
		for(int i = 0;i<p;i++)
			Up[i][j] = Up[Up[i][j-1]][j-1];
	for(int i = 0;i<n;i++)
	{
		int Now = i,Limit = Nodes[i].l+m;
		for(int j = 29;j>=0;j--)
			if(Nodes[Up[Now][j]].r<Limit)Now = Up[Now][j],Ans[Nodes[i].id]|=(1<<j);
	}
	for(int i = 0;i<n;i++)std::cout<<Ans[i]+2<<" ";
	return 0;
}

