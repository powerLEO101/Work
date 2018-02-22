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

int Num[100001];

int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	int n = gi,X = gi,Y = gi,A = gi,B = gi;
	int S;
	if(B%X==0)S = B/X;
	else S = B/X+1;
	std::cout<<"Win"<<std::endl<<S;
	return 0;
}
