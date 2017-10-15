#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#define MOD 10007

namespace file
{
	std::ifstream cin("linkb.in");
	std::ofstream cout("linkb.out");
}

std::vector<long long> Map[200001];
long long Weight[200001],Sum;

int main()
{
	long long n;
	file::cin>>n;
	for(long long i = 1;i<n;i++)
	{
		long long u,v;
		file::cin>>u>>v;
		u--;v--;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	for(long long i = 0;i<n;i++)file::cin>>Weight[i];	
	long long Ans = 0,Max = -INF,Now_Max = -INF,Sum = 0;
	for(long long x = 0;x<n;x++)
	{
		Now_Max = Weight[Map[x][0]];
		Sum = Now_Max%MOD;
		for(std::vector<long long>::iterator it = Map[x].begin()+1;it!=Map[x].end();it++)
		{
			Ans = (Ans+Sum*Weight[*it])%MOD;
			Max = std::max(Max,Now_Max*Weight[*it]);
			Now_Max = std::max(Weight[*it],Now_Max);
			Sum = (Sum+Weight[*it])%MOD;
		}
	}
	file::cout<<Max<<" "<<(Ans*2)%MOD;
	return 0;
}
