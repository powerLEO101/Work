#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

int main()
{
	int a,b;
	std::cin>>a>>b;
	a^=b^=a^=b;
	std::cout<<a<<" "<<b<<std::endl;
	return 0;
}
