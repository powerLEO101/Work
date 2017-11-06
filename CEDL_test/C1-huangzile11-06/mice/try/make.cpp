#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while ( ( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar();
	if ( ch == '-' ) y = -1,ch = getchar();
	while ( ch <= '9' && ch >= '0') x = x * 10 + ch - '0',ch = getchar();
	return x * y;
}

int main()
{
	freopen("mice.in","w",stdout);
	srand(time(0));
	int n = rand()%100,m = rand()%100;
	for(int i = 0;i<n;i++)std::cout<<rand()%n+1<<" ";
	std::cout<<std::endl;
	for(int i = 0;i<m;i++)std::cout<<rand()%n+1<<" "<<n<<std::endl;
	return 0;
}

