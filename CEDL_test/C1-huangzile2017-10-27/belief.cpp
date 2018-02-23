#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = ' ';
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int n,m,q;
bool State[1001][1001];

void Modify(int x,int y)
{
	for(int i = 0;i<n;i++)State[i][y] = x==i?State[i][y]:!State[i][y];
	for(int i = 0;i<m;i++)State[x][i] = y==i?State[x][i]:!State[x][i];
}
int Query(int x1,int y1,int x2,int y2)
{
	int Ans = 0;
	for(int i = x1;i<=x2;i++)
		for(int j = y1;j<=y2;j++)
			Ans+=State[i][j];
	return Ans;
}

int main()
{
	freopen("belief.in","r",stdin);
	freopen("belief.out","w",stdout);
	n = gi;m = gi;q = gi;
	for(int i = 0;i<q;i++)
	{
		int Mode = gi;
		if(Mode==1)
		{
			int x = gi-1,y = gi-1;
			Modify(x,y);
		}
		else
		{
			int x1 = gi-1,y1 = gi-1,x2 = gi-1,y2 = gi-1;
			std::cout<<Query(x1,y1,x2,y2)<<std::endl;
		}
	}	
	return 0;
}
