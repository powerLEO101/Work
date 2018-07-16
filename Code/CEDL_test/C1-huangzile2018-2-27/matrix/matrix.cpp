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
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[2002][2002],Up[2002][2002],Down[2002][2002];

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n = gi,Ans = 0;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		Num[i][j] = gi;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		Up[i][j] = Num[i][j]==1?0:Up[i-1][j]+1;
	for(int i = n-1;i>=0;i--)
	for(int j = 0;j<n;j++)
		Down[i][j] = Num[i][j]==1?0:Down[i+1][j]+1;
	for(int i = 0;i<n;i++)
	{
		int Min_up = n,Min_down = n,l = 0;
		for(int j = 0;j<n;j++)
		{
			if(Num[i][j]==1){Min_up = n,Min_down = n,l = 0;continue;}
			l++;
			Min_up = std::min(Min_up,Up[i][j]);
			Min_down = std::min(Min_down,Down[i][j]);
			Ans = std::max(l*(Min_up+Min_down-1),Ans);
		}
	}
	std::cout<<Ans;
	return 0;
}
