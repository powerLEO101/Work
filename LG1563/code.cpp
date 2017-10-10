#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<string>

std::string a[100001];
int b[100001],c[100001],d[100001];

int main()
{
	int n,m;
	std::cin>>n>>m;
	for(int i = 0;i<n;i++)
		std::cin>>b[i]>>a[i];
	for(int i = 0;i<m;i++)
		std::cin>>c[i]>>d[i];
	int Now = 0;
	for(int i = 0;i<m;i++)
	{
		if(c[i]==0&&b[Now]==0)
		{
			Now-=d[i];
			if(Now<0)Now+=n;
		}
		else if(c[i]==0&&b[Now]==1)
		{
			Now+=d[i];
			if(Now>=n)Now-=n;
		}
		else if(c[i]==1&&b[Now]==1)
		{
			Now-=d[i];
			if(Now<0)Now+=n;
		}
		else if(c[i]==1&&b[Now]==0)
		{
			Now+=d[i];
			if(Now>=n)Now-=n;
		}
	}
	std::cout<<a[Now];
	return 0;
}
