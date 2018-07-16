#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>

int num[1000001];

int main()
{
	freopen("treap.in","r",stdin);
	freopen("treap.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	for(int i = 0;i<n;i++)std::cin>>num[i];
	for(int i = 0;i<m;i++)
	{
		int l,r;
		std::cin>>l>>r;
		std::cout<<(r-l)+1<<std::endl;
	}
	return 0;
}
