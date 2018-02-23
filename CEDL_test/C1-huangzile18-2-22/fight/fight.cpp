#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define gi get_int()
#define INF 0x3f3f3f3f

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int c[100001];
std::priority_queue<int> Q;

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	int n = gi,X = gi,Y = gi,A = gi,B = gi;
	for(int i = 0;i<n;i++)
		c[i] = gi;
	int H = B;
	int Max_Hurt = -INF;
	for(int i = 0;i<n;i++)
	{
		B-=X;
		if(B<=0)
		{
			std::cout<<"Win"<<std::endl<<i+1;
			return 0;
		}
		Max_Hurt = std::max(Max_Hurt,H-B);
		A-=c[i];
		Q.push(c[i]);
		while(A<=0&&!Q.empty())
		{
			A+=std::max(Q.top(),Y);
			B+=X;
			Q.pop();
		}
	}
	std::cout<<"Lose"<<std::endl<<Max_Hurt;
	return 0;
}
