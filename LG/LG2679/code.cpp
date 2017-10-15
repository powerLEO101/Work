#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#define MOD 1000000007

namespace file
{
	std::ifstream cin("2015substring.in");
	std::ofstream cout("2015substring.out");
}

long long f[2][205][205],s[2][205][205];
char a[1005],b[205];

int main()
{
	int n,m,l;
	file::cin>>n>>m>>l;
	file::cin>>a+1>>b+1;
	int Now = 1,Pre = 0;
	f[0][0][0] = 1;
	for(int i = 1;i<=n;i++)
	{
		f[Now][0][0] = 1;
		for(int j = 1;j<=m;j++)
			for(int k = 1;k<=l;k++)
			{
				if(a[i]==b[j]) s[Now][j][k] = (s[Pre][j-1][k]+f[Pre][j-1][k-1])%MOD;
				else s[Now][j][k] = 0;
				f[Now][j][k] = (f[Pre][j][k]+s[Now][j][k])%MOD;
			}
		std::swap(Now,Pre);
	}
	file::cout<<f[Pre][m][l];
	return 0;
}
