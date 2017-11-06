#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
#define gi get_int()
long long get_int()
{
	long long x = 0,y = 1;char ch = getchar();
	while ( ( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar();
	if ( ch == '-' ) y = -1,ch = getchar();
	while ( ch <= '9' && ch >= '0') x = x * 10 + ch - '0',ch = getchar();
	return x * y;
}

class Node
{
public:
	long long p,c;
}D[1001];
int Num[1001],Dis[2002][2002],Ans[3003];
bool Vis[1001];

long long abs(long long u){return u<0?-u:u;}

int main()
{
	freopen("mice.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,Sum = 0;
	for ( int i = 0;i < n;i ++ ) Num[i] = gi;
	for ( int i = 0;i < m;i ++ ) D[i].p = gi,D[i].c = gi;
	for ( int i = 0;i < m;i ++ ) Sum += D[i].c;
	if ( Sum < n )
	{
		std::cout << -1;
		return 0;
	}
	memset(Dis,0x3f,sizeof(Dis));
	memset(Ans,0x3f,sizeof(Ans));
	for ( int i = 0;i < n;i ++ )
	for ( int j = n;j < n+m;j ++ )
		Dis[i][j] = abs(Num[i]-D[j-n].p);
	for ( int k = 0;k < n;k ++ )
	for ( int i = 0;i < n;i ++ )
	for ( int j = 0;j < n;j ++ )
		if ( Dis[i][j] > Dis[i][k]+Dis[k][j] )
			Dis[i][j] = Dis[i][k]+Dis[k][j];
	for ( int i = n;i < n + m;i ++ )
	{
		memset(Vis,0,sizeof(Vis));
		for (int j = 0;j < D[i-n].c;j ++)
		{
			int Val = 0x7fffffff,Index;
			for ( int k = 0;k < n;k ++ )
			if(Val>Dis[k][i] && Vis[k] != true)
			{
				Val = Dis[k][i],
				Index = k;
			}
			Vis[Index] = true;
			Ans[Index] = std::min(Ans[Index],Val);
		}
	}
	long long S = 0;
	for ( int i = 0;i < n;i ++ ) S += Ans[i];
	std::cout << S;
	return 0;
}
