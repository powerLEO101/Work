#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

int Num[1001],Dp[100][11][11][11];

int Get_ans(int Now,int x,int y,int z)
{
	if(Dp[Now][x][y][z]!=-1)return Dp[Now][x][y][z];
	if(x==0&&y==0&z==0)return 0;
	int Ans = INF;
	if(x!=0)
	{
		int t1 = 0,t2 = y,t3 = z;
		for(int i = Now;i<Now+x;i++)
			if(Num[i]==1)t1++;
			else if(Num[i]==2)t2++;
			else if(Num[i]==3)t3++;
		Ans = std::min(Ans,Get_ans(Now+1,t1,t2,t3));
	}
	if(y!=0)
	{
		int t1 = x,t2 = 0,t3 = z;
		for(int i = Now;i<Now+y;i++)
			if(Num[i]==1)t1++;
			else if(Num[i]==2)t2++;
			else if(Num[i]==3)t3++;
		Ans = std::min(Ans,Get_ans(Now+1,t1,t2,t3));
	}
	if(z!=0)
	{
		int t1 = x,t2 = y,t3 = 0;
		for(int i = Now;i<Now+z;i++)
			if(Num[i]==1)t1++;
			else if(Num[i]==2)t2++;
			else if(Num[i]==3)t3++;
		Ans = std::min(Ans,Get_ans(Now+1,t1,t2,t3));
	}
	return Dp[Now][x][y][z] = ++Ans;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	memset(Dp,-1,sizeof(Dp));
	int n = gi;
	for(int i = 0;i<n;i++)
	{
		char ch;
		std::cin>>ch;
		if(ch=='A')Num[i] = 1;
		if(ch=='B')Num[i] = 2;
		if(ch=='C')Num[i] = 3;
	}
	int x = 0,y = 0,z = 0;
	for(int i = 0;i<10;i++)
		if(Num[i]==1)x++;
		else if(Num[i]==2)y++;
		else if(Num[i]==3)z++;
	std::cout<<Get_ans(10,x,y,z);
	return 0;
}
