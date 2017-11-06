#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while ( ( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar();
	if( ch == '-' )y = -1,ch = getchar();
	while ( ch <= '9' && ch >= '0' )  x = x * 10 + ch - '0',ch = getchar();
	return x * y;
}

class Node
{
public:
	int p,c;
}D[1000001];
bool operator< (const Node& a,const Node& b)
{
	return a.p<b.p;
}
bool operator== (const Node& a,const Node& b)
{
	return a.p==b.p;
}
int Num[1000001];
int Dis[2002][2002],Ans[3003];
bool Vis[1001];

int abs(int a){return a<0?-a:a;}
long long CASE1(int n,int m)
{
	std::sort(Num,Num+n);
	std::sort(D,D+m);
	std::unique(D,D+m);
	long long Index = 0,Ans = 0;
	for ( int i = 0;i < n;i ++ )
	{
		while ( abs(Num[i] - D[Index].p) > abs(Num[i] - D[Index + 1].p) )Index++;
		Ans += abs(Num[i] - D[Index].p);
	}
	return Ans;
}
long long CASE2(int n,int m)
{
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
	return S;
}

int main()
{
	freopen("mice.in","r",stdin);
	freopen("mice.out","w",stdout);
	int n = gi,m = gi,Sum = 0;
	for ( int i = 0;i < n;i ++ ) Num[i] = gi;
	for ( int i = 0;i < m;i ++ ) D[i].p = gi,D[i].c = gi;
	for ( int i = 0;i < m;i ++ ) Sum += D[i].c;
	if ( Sum < n )
	{
		std::cout << -1;
		return 0;
	}
	bool Flag = false;
	for ( int i = 0;i < m;i ++ )
		if( D[i].c < n ) Flag = true;
	if ( Flag == false )
		std::cout << CASE1(n,m);
	else std::cout << CASE2(n,m);
	return 0;
}

