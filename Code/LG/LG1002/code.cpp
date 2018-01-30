#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define X (hx+10)
#define Y (hy+10)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long Map[101][101],f[101][101];

void Get(int hx,int hy)
{
	Map[X][Y] = 1;
	Map[X-1][Y-2] = 1;
	Map[X-2][Y-1] = 1;
	Map[X-2][Y+1] = 1;
	Map[X-1][Y+2] = 1;
	Map[X+1][Y-2] = 1;
	Map[X+2][Y-1] = 1;
	Map[X+2][Y+1] = 1;
	Map[X+1][Y+2] = 1;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,hx = gi,hy = gi;
	Get(hx,hy);
	f[1+10][0+10]=1;
	for(int i = 1+10;i<=n+1+10;i++)
	{
		for(int j = 1+10;j<=m+1+10;j++)
		{
			f[i][j] = f[i-1][j]+f[i][j-1];
			if(Map[i-1][j-1])
				f[i][j] = 0;
		}
	}
	std::cout<<f[n+1+10][m+1+10];
	return 0;
}
