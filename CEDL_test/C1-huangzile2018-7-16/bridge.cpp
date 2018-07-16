#include<iostream>
#include<cstdio>
#include<algorithm>
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


class Child
{
	public:
		int Num,k,d;
}p[500000];
int p1[500000];
int P[500000];
int cmd(const Child& a,const Child& b)
{
	return a.Num<b.Num;
}

void CASE1(int n)
{
	int Q = gi;
	while(Q--)
	{
		int k = gi,t = gi;
		if(p[k].d==1)std::cout<<p[k].Num+t;
		else std::cout<<p[k].Num-t;
		std::cout<<std::endl;
	}
}
bool check(int n)
{
	for(int i = 1;i<n;i++)
		if(p[i].d!=p[i-1].d)return false;
	return true;
}

int main()
{
	File(bridge);
	int n = gi;
	for(int i = 0;i<n;i++)
	{
		p[i].Num = gi;
		p[i].k = i;
	}
	for(int i = 0;i<n;i++)
		p[i].d = gi;
	if(check(n)==true)
	{
		CASE1(n);
		return 0;
	}
	std::sort(p,p+n,cmd);
	for(int i = 0;i<n;i++)
		P[p[i].k] = i;
	int Q = gi;
	while(Q--)
	{
		int k = gi,t = gi;
		for(int i = 0;i<n;i++)
			if(p[i].d==1)p1[i] = p[i].Num+t;
			else p1[i] = p[i].Num-t;
		std::sort(p1,p1+n);
		std::cout<<p1[P[k]]<<std::endl;
	}
	return 0;
}

