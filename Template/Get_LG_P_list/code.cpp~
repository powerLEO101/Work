#include<iostream>
#include<iomanip>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>

std::string str;

int main()
{
	freopen("test.txt","r",stdin);
	freopen("list.out","w",stdout);
	system("echo \"Update time : \";net time");
	int Index = 0,flag = 0;
	while(getline(std::cin,str))
	{
		if(str=="All rights reserved 陕ICP备17005722号-1.")continue;
		if(str=="Master: TrySail / DB: Index / CGI: Toyama_Kasumi")continue;
		if(str=="USACO 各省省选 WC/CTSC/集训队 POI 福建省历届夏令营 NOI系列 洛谷原创 NOIp普及组 NOIp提高组 NOIp初赛 APIO NOI导刊 IOI")continue;
		if(flag==1)
		{
			flag = 0;
			std::cout<<str<<std::endl;
			continue;
		}
		for(int i = 0;i<str.size();i++)
		{
			if(str[i]=='P')
			{
				flag = 1;
				break;
			}
		}
		if(flag==1)
		{
			std::cout<<str<<" --> Tag :";
			continue;
		}
	}
	return 0;
}
