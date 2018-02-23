#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}
int Day[100001];

int main()
{
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)
	{
		int Temp = gi;
		Day[i] = Temp/100;
	}
	std::cout<<0<<std::endl;
	for(int i = 0;i<n;i++)std::cout<<Day[i]<<" 0"<<std::endl;
	return 0;
}
