#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f

namespace file
{
	std::ifstream cin("sequence.in");
	std::ofstream cout("sequence.out");
}

int a[100001],b[100001],Ans[100001];

int main()
{
	//std::ios::sync_with_stdio(false);
	memset(Ans,0x3f,sizeof(Ans));
	int n;
	file::cin>>n;
	for(int i = 0;i<n;i++)
		file::cin>>a[i];
	for(int j = 0;j<n;j++)
		file::cin>>b[j];
	for(int i = 0;i<n;i++)
		Ans[i] = a[0]+b[i];
	for(int i = 1;i<n;i++)
		for(int j = 0;j<n;j++)
		{
			int Temp = a[i]+b[j];
			if(Temp>=Ans[n])break;
			int Pos = std::lower_bound(Ans,Ans+n,Temp)-Ans;
			for(int i = n-1;i>=Pos;i--)Ans[i] = Ans[i-1];
			Ans[Pos] = Temp;
		}
	for(int i = 0;i<n;i++)file::cout<<Ans[i]<<" ";
	return 0;
}
