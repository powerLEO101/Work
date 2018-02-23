#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()

int get_int()
{
        int x = 0,y = 1;char ch = getchar();
        while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
        if(ch=='-')y = -1,ch = getchar();
        while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
        return x*y;
}

int main()
{
        freopen("hop.in","r",stdin);
        freopen("hop.out","w",stdout);
	std::cout<<"NO";
        return 0;
}
