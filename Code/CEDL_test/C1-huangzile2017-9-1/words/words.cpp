#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<string>

namespace file
{
	std::ifstream cin("words.in");
	std::ofstream cout("words.out");
}

std::string string[10001],t;

bool Judge(int Index)
{
	for(int i = 0;i<t.size();i++)
		if(string[Index][i]!=t[i])return false;
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	file::cin>>n;
	for(int i = 0;i<n;i++)file::cin>>string[i];
	file::cin>>t;
	std::sort(string,string+n);
	for(int i = 0;i<n;i++)
	{
		if(Judge(i)==false)continue;
		file::cout<<string[i]<<std::endl;
	}
	return 0;
}
