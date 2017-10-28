#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>

bool p[100000000];
int main()
{
	freopen("test.out","w",stdout);
	for(int i = 2;i<=500;i++)
		p[i*2] = p[i*3] = true;
	std::cout<<2<<" ";
	for(int i = 2;i<=500;i++)
		if(p[i]==false)std::cout<<i<<" ";
	return 0;
}
