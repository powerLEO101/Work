#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

int fast_power(int a,int x,int MOD)
{
	int ans = 1;
	while(x!=0)
	{
		if(x&1==1)ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		x>>=1;
	}
	return ans;
}
int main()
{
	int n,m,k,x;
	std::cin>>n>>m>>k>>x;
	int temp3 = fast_power(10%n,k,n);
	int ans = (x+((((m%n)*temp3)%n)%n))%n;
	std::cout<<ans;
	return 0;
}
