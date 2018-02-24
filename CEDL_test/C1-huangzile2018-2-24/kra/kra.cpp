#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define INF 0x3f3f3f3f

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[300001],Dish[300001];

int main()
{
	freopen("kra.in","r",stdin);
	freopen("kra.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	for(int i = 0;i<m;i++)
		Dish[i] = gi;
	for(int i = 0;i<m-1;i++)
	{
		int Val = Dish[i];
		for(int j = 0;j<n;j++)
			if(Num[j]<Val)
				Num[j] = 0;
	}
	int Val = Dish[m-1];
	for(int i = 0;i<n;i++)
	{
		if(Num[i]<Val)
		{
			std::cout<<i;
			return 0;
		}
	}
	return 0;
}
