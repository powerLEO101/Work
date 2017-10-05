#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#define ll long long
#define MOD 10000

namespace file
{
	std::ifstream cin("sum.in");
	std::ofstream cout("sum.out");
}

ll power(ll a,ll b)
{
	ll Ans = 1;
	while(b!=0)
	{
		if(b&1)Ans = (Ans*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return Ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll a,b,t;
	file::cin>>t;
	while(t--)
	{
		file::cin>>a>>b;
		ll Ans = 0;
		for(int i = 1;i<=a;i++)
			Ans = (Ans+(power(i,b)%MOD))%MOD;
		file::cout<<Ans<<std::endl;
	}
	return 0;
}
