#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

namespace file
{
	std::ifstream cin("c.in");
	std::ofstream cout("c.out");
}

int Num[100001],n;

int Judge(int k)
{
	int x = 1,y = 1;
	while(x<=n)
	{
		x*=k;
		if(x<=n)
			y*=Num[x-1];
	}
	return y;
}

int main()
{
	file::cin>>n;
	for(int i = 0;i<n;i++)
	{
		file::cin>>Num[i];
	}
	int Ans = -0x3f3f3f3f;
	for(int i = 2;i<=n;i++)
	{
		int temp = Judge(i);
		if(Ans<temp)
			Ans = temp;
	}
	file::cout<<Ans;
	return 0;
}
