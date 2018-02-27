#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>

int Num[2001][2001];
int n;

int Get_ans(int i,int j)
{
	int Ans = 0;
	int Sum = 0;
	for(int k = 0;k<n;k++)
	{
		int Val;
		if(i==0)Val = Num[k][j];
		else Val = Num[k][j]-Num[k][i-1];
		if(Val==0)Sum+=1;
		else Sum = 0;
		Ans = std::max(Sum*(j-i+1),Ans);
	}
	return Ans;
}

void CASE1()
{
	srand(time(0));
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		scanf("%d",&Num[i][j]);
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		Num[i][j]+=Num[i][j-1];
	int Ans;
	while(clock()<=910000)
	{
		int l = rand()%n;
		int r = l+(rand()%(n-l));
		Ans = std::max(Get_ans(l,r),Ans);
	}
	std::cout<<Ans;
}

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		scanf("%d",&Num[i][j]);
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		Num[i][j]+=Num[i][j-1];	
	if(n>=500)
	{
		CASE1();
		return 0;
	}
	int Ans = 0;
	for(int i = 0;i<n;i++)
	for(int j = i+1;j<n;j++)
	{
		int Sum = 0;
		for(int k = 0;k<n;k++)
		{
			int Val;
			if(i==0)Val = Num[k][j];
			else Val = Num[k][j]-Num[k][i-1];
			if(Val==0)Sum+=1;
			else Sum = 0;
			Ans = std::max(Sum*(j-i+1),Ans);
		}
	}
	std::cout<<Ans;
	return 0;
}
