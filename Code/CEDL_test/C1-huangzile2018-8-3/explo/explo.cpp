#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
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
	File(explo);
	int n  = gi,k = gi,c = gi,w = gi;
	int Ans = -INF;
	for(int i = 0;i<n;i++)
	{
		int Type = gi,x = gi;
		if(Type==2)continue;
		Ans = std::max(Ans,x);
	}
	std::cout<<Ans*w<<".00";
	return 0;
}
