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
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int P1[1001],P2[1001];
int f[101][101];

void init()
{
	for(int i = 0;i<101;i++)
	for(int j = 0;j<101;j++)
		f[i][j] = -1;
}

bool check(int MID,int n,int m)
{
	init();
	f[0][0] = 0;
	for(int i = 1;i<=n;i++)
	for(int j = 0;j<=m;j++)
	for(int k = 0;k<=j;k++)
		if(MID-P1[i]*k>=0&&f[i-1][j-k]!=-1)
			f[i][j] = std::max(f[i][j],f[i-1][j-k]+(MID-P1[i]*k)/P2[i]);
	if(f[n][m]>=m)return true;
	return false;
}

int main()
{
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 1;i<=n;i++)
		P1[i] = gi,
		P2[i] = gi;
	int l = 1,r = 10000;
	while(l+1<r)
	{
		int MID = (l+r)/2;
		if(check(MID,n,m)==true)r = MID;
		else l = MID;
	}
	std::cout<<r;
	return 0;
}
