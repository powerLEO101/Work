#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long Num[1001][1001];//注意空间

int Get_ans(int n,int m)
{
	Num[1][1] = 1;
	for(int i = 2;i<=n+1;i++)
	for(int j = 1;j<=i;j++)
		Num[i][j] = Num[i-1][j]+Num[i-1][j-1];
	return Num[n+1][m+1];
}

int main()
{
	freopen("si.in","r",stdin);
	freopen("si.out","w",stdout);
	int n = gi,m = gi;
	std::cout<<Get_ans(n,m);
	return 0;
}

