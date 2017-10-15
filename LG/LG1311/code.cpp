#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

int pre[200100],cnt[200100],c[200100];
int main()
{
	int n,k,p;
	std::cin>>n>>k>>p;
	int cost = 0,ans = 0;
	for(int i = 1;i<=n;i++)
	{
		int color,val;
		std::cin>>color>>val;
		int j = pre[color];
		if(val<=p)cost = i;
		if(j<=cost)c[i] = cnt[color];
		else c[i] = c[j];
		ans+=c[i];
		pre[color] = i;
		cnt[color]++;
	}
	std::cout<<ans;
	return 0;
}
