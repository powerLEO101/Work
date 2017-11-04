#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

void kuoo(int a,int b,int&x,int&y)
{
	if(b==0)
	{
		x=1;y=0;
		return;
	}
	else
	{
		kuoo(b,a%b,y,x);
		y = y-(x*(a/b));
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int x,y,n,m;
	std::cin>>n>>m;
	kuoo(n,m,x,y);
	std::cout<<((x%m)+m)%m;
	return 0;
}
