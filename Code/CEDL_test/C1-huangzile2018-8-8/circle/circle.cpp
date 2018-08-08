#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
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

int n,m,k,Num[1001],Ans = -INF,Sum[1001],Answer[1001][1001],Ans_n;
bool Vis[1001];

int Calc()
{
	memset(Vis,0,sizeof(Vis));
	for(int i = 0;i<n;i++)Num[i+n] = Num[i];
	Sum[0] = Num[0];
	for(int i = 1;i<2*n;i++)Sum[i] = Sum[i-1]+Num[i];
	for(int i = 0;i<2*n;i++)
		for(int j = i;j<2*n&&j<i+n;j++)
			Vis[Sum[j]-Sum[i-1]] = true;
	for(int i = m;;i++)
		if(Vis[i]==false)return i-1;
}
void Get_ans(int Now = 0,int Pre = -1)
{
	if(Now==n)
	{
		int Temp = Calc();
		if(Ans==Temp)
		{
			for(int i = 0;i<n;i++)Answer[Ans_n][i] = Num[i];
			Ans_n++;
		}
		else if(Ans<Temp)
		{
			Ans = Temp;
			Ans_n = 1;
			for(int i = 0;i<n;i++)Answer[0][i] = Num[i];
		}
		return;
	}
	bool Flag = false;
	for(int i = Pre;i<=24;i++)
	{
		if(i==-1)
		{
			Flag = true;
			continue;
		}
		Num[Now] = i;
		if(Flag==true)
			Get_ans(Now+1,i);
		else Get_ans(Now+1,Pre);
	}
}

int main()
{
	File(circle);
	n = gi,m = gi,k = gi;
	/*
	Num[0] = 1;
	Num[1] = 3;
	Num[2] = 10;
	Num[3] = 2;
	Num[4] = 5;
	std::cout<<Calc();
	return 0;
	*/
	Get_ans();
	std::cout<<Ans<<std::endl;
	for(int i = 0;i<Ans_n;i++)
	{
		for(int j = 0;j<n;j++)
			std::cout<<Answer[i][j]<<' ';
		std::cout<<std::endl;
	}
	return 0;
}
