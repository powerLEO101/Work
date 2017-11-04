#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int main()
{
	system("g++ code.cpp -o code");
	system("g++ AC_code.cpp -o AC_code");
	system("g++ make.cpp -o make");
	int T = 0;
	while(23333333)
	{
		std::cout<<"CASE"<<T++<<"#";
		system("./make");
		system("./AC_code");
		system("./code");
		if(system("diff code.out AC_code.out"))
		{
			std::cout<<"WA"<<std::endl;
			return 0;
		}
		std::cout<<"AC"<<std::endl;
	}
	return 0;
}

