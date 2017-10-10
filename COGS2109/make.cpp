#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>

int main()
{
	freopen("transport.in","w",stdout);
	srand(time(0));
	int n = rand()%7+1,m = rand()%7+1;
	std::cout<<n<<" "<<m<<std::endl;
	for(int i = 1;i<n;i++)
		std::cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%30+1<<std::endl;
	for(int i = 0;i<m;i++)
		std::cout<<rand()%n+1<<" "<<rand()%n+1<<std::endl;
	return 0;
}
