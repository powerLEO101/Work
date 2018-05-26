#include<iostream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int main()
{
	File(binary);	
	return 0;
}
