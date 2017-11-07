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
	while ((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if (ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int main()
{
	freopen("km.in","r",stdin);
	freopen("km.out","w",stdout);
	int T = gi;
	std::string str;
	while(T--)
	{
		bool Flag = false;
		int n = gi,k = gi,m = gi;
		if(n<=2)
		{
			std::cout<<"KM"<<std::endl;
			return 0;
		}
		if(k>m)std::swap(k,m);
		int Count = 0,Limit = n/2,Count1 = 0;
		std::cin>>str;
		for(int i = 1;i<=n;i++)
		{
			int Num = str[i-1]-'0';
			if(i<k&&Num==0)Count++;
			if(Num==1)Count1++;
			if(i>k&&i<=m&&Num==0)
			{
				Flag = true;
				break;
			}
		}
		if(Flag==true)std::cout<<"gg"<<std::endl;
		else std::cout<<"KM"<<std::endl;
	}
	return 0;
}

