//检查质数个数，所有的质数都存在p里，isp表示这个数是不是质数，size表示质数的个数，最后的输出其实是可以直接输出size的，但是我一时sb了，所以就又数了一遍
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>

bool isp[100000001];
int p[100000001],size = 0;
int main()
{
	memset(isp,1,sizeof(isp));
	isp[1] = false;
	for(int i = 2;i<=100000000;i++)
	{
		if(isp[i])p[++size] = i;
		for(int j = 1;j<=size&&i*p[j]<=100000000;j++)
		{
			isp[i*p[j]] = false;
			if(i%p[j]==0)break;//这句话用于优化常数，一定不能省,cann't delete!!!!!
		}
	}
	int Count = 0;
	for(int i = 2;i<=100000000;i++)
		if(isp[i]==true)Count++;
	std::cout<<Count<<std::endl;
	return 0;
}

