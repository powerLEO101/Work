#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define INF 0x3f3f3f3f
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
	int Time,x,y;
}Nodes[10001];

int ABS(int u){return u<0?-u:u;}
int f[10001];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,Ans = -INF;
	for(int i = 0;i<m;i++)
	{
		int Time = gi,x = gi,y = gi;
		Nodes[i] = (Node){Time,x,y};
		f[i] = 1;
		for(int j = i-1;j>=0;j--)
		{
			if((ABS(Nodes[j].x-x)+ABS(Nodes[j].y-y))>ABS(Time-Nodes[j].Time))continue;
			f[i] = std::max(f[i],f[j]+1);
		}
		Ans = std::max(Ans,f[i]);
	}
	std::cout<<Ans;
	return 0;
} 
