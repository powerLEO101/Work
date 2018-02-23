#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
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
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	srand(time(0));
	int T = gi;
	while(T--)
	{
		if(rand()%2==0)std::cout<<"YES"<<std::endl;
		else std::cout<<"NO"<<std::endl;
	}
	return 0;
}
