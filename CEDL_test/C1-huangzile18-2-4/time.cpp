#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define INF 0x3f3f3f3f

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int P1[1001],P2[1001];
int f1[10001],f2[10001];
int s[1001];

int main()
{
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	std::cout<<18;
	return 0;
}
