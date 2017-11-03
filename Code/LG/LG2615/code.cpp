#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

namespace file
{
	std::ifstream cin("2015magic.in");
	std::ofstream cout("2015magic.out");
}

int a[40][40],n;
int main()
{
	file::cin>>n;
	int y=n/2+1,x=1;
	for(int i=1; i<=n*n; i++)
	{
		a[x][y]=i;
		if(x==1&&y!=n) x=n,y++;
		else if(x!=1&&y==n) x--,y=1;
		else if(x==1&&y==n) x++;
		else if(x!=1&&y!=n)
		{
			if(!a[x-1][y+1]) x--,y++;
			else x++;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<n; j++)
			file::cout<<a[i][j]<<' ';
		file::cout<<a[i][n]<<std::endl;
	}
}
