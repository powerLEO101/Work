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
	while((ch<'0'||ch>'0')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

bool Check(int Num[],int b,int len)
{
	int Temp = 0,Index = 0;
	while(Temp<b&&Index<len)Temp = Temp*10+Num[Index++];
	for(;Index<len;Index++)
		Temp = (Temp%b)*10+Num[Index];
	return (Temp%b)==0;
}

int Num[2000001];
int main()
{
	freopen("nznd.in","r",stdin);
	freopen("nznd.out","w",stdout);
	int a,Index = 0;
	while(std::cin>>a)
	{
		if(a==0)break;
		if(a%16==0)
		{
			std::cout<<"Case "<<++Index<<": 0"<<std::endl;
			continue;
		}
		int i;
		for(i = 1;i<1000;i++)
		{
			Num[i-1] = 8;
			if(Check(Num,a,i)==true)
			{
				std::cout<<"Case "<<++Index<<": "<<i<<std::endl;
				break;
			}
		}
		if(i==1000)std::cout<<"Case "<<++Index<<": "<<0<<std::endl;
	}
	return 0;
}
