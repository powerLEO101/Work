#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<string>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0';
	return x*y;
}

int main()
{
	freopen("str.in","r",stdin);
	freopen("str.out","w",stdout);
	std::string str;
	std::cin>>str;
	for(int j = 0;j<26;j++)
	{
		bool flag = false;
		for(int i = 0;i<str.size()&&flag!=true;i++)
			if(str[i]=='a'+j)flag = true;
		if(flag==false)
		{
			std::cout<<char('a'+j);
			return 0;
		}
	}
	std::cout<<"aa";
	return 0;
}
