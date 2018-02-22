#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
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

int Num1[100001],Num[100001];

int ABS(int a){return a<0?-a:a;}

int Get_ans(int n)
{
	int Ans = 0;
	for(int i = 1;i<n;i++)
	{
		if(Num[i]>=Num[i-1])continue;
		int r = rand()%2;
		if(r==0)
		{
			for(int j = 0;j<i;j++)
			{
				Ans+=ABS(Num[j]-Num[i]);
				Num[j] = Num[i];
			}
		}
		else
		{
			Ans+=ABS(Num[i]-Num[i-1]);
			Num[i] = Num[i-1];
		}
	}
	return Ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	int n = gi;
	for(int i = 0;i<n;i++)
		Num1[i] = Num[i] = gi;
	int Ans = INF;
	while(true)
	{
		Ans = std::min(Ans,Get_ans(n));
		for(int i = 0;i<n;i++)
			Num[i] = Num1[i];
		if(clock()>=930233)break;
	}
	std::cout<<Ans;
	return 0;
}
