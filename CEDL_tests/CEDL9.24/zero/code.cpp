#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

namespace file
{
	std::ifstream cin("zero.in");
	std::ofstream cout("zero.out");
}

int main()
{
	int T;
	file::cin>>T;
	while(T--)
	{
		int m,n,Two = 0,Five = 0;
		file::cin>>m>>n;
		for(int i = 1;i<=m;i++)
		{
			int Num = i;
			while(Num%2==0)
			{
				Two++;
				Num/=2;
			}
			while(Num%5==0)
			{
				Five ++;
				Num/=5;
			}
		}
		for(int i = 1;i<=n;i++)
		{
			int Num = i;
			while(Num%2==0)
			{
				Two--;
				Num/=2;
			}
			while(Num%5==0)
			{
				Five--;
				Num/=5;
			}
		}
		for(int i = 1;i<=(m-n);i++)
		{
			int Num = i;
			while(Num%2==0)
			{
				Two--;
				Num/=2;
			}
			while(Num%5==0)
			{
				Five--;
				Num/=5;
			}
		}
		file::cout<<std::min(Five,Two)<<std::endl;
	}
	return 0;
}
