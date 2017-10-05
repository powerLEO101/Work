#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#define gi read()

inline int read()
{
	int w = 1,x = 0;char ch = ' ';
	while(ch<'0'||ch>'9'){if(ch=='-')w = -1;ch = getchar();}
	while(ch<='9'&&ch>='0'){x = x*10+ch-'0';ch = getchar();}
	return w*x;
}

int main()
{
	return 0;
}
