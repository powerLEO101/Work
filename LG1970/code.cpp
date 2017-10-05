#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

int main()
{
	int n,now,last,ans = 1,mode = -1;
	std::cin>>n>>last;
	for(int i = 1;i<n;i++)
	{
		std::cin>>now;
		if(now>last&&(mode==-1||mode==0))
		{
			ans++;
			mode = 1;
		}
		if(now<last&&(mode==-1||mode==1))
		{
			ans++;
			mode = 0;
		}
		last = now;
	}
	std::cout<<ans;
	return 0;
}
