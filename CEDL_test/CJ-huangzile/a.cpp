#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstring>

namespace file
{
	std::ifstream cin("a.in");
	std::ofstream cout("a.out");
}

int Num[1001],f[1001][1001];

int main()
{
	int n,k;
	file::cin>>n>>k;
	for(int i = 0;i<n;i++)file::cin>>Num[i];
	memset(f,-0x3f,sizeof(f));
	f[0][1] = Num[0];
	f[1][1] = std::max(Num[0],Num[1]);
	for(int i = 0;i<1001;i++)f[i][0] = 0;
	for(int i = 2;i<n;i++)
		for(int j = 1;j<=k;j++)
			f[i][j] = std::max(f[i-1][j],f[i-2][j-1]+Num[i]);
//	for(int i = 0;i<n;i++)
//	{
//		for(int j = 1;j<=k;j++)file::cout<<f[i][j]<<" ";
//		file::cout<<std::endl;
//	}
	file::cout<<f[n-1][k];
	return 0; 
}
