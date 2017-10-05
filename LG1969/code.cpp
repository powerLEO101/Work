#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

int h[100000];

int main()
{
	int n;
	std::cin>>n;
	for(int i = 0;i<n;i++)
		std::cin>>h[i];
	int ans = h[0];
	for(int i = 1;i<n;i++)ans += h[i]>h[i-1]?h[i]-h[i-1]:0;
	std::cout<<ans;
	return 0;
}
