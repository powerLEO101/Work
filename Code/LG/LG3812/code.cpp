#include<iostream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
long long get_int()
{
	long long x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long Base[51];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long n = gi;
	for(int i = 0;i<n;i++)
	{
		long long x = gi;
		for(int i = 50;i!=-1;i--)
		{
			if(x&(1ll<<i))
			{
				if(!Base[i]){Base[i] = x;break;}
				else x^=Base[i];
			}
		}
	}
	long long Ans = 0;
	for(int i = 50;i!=-1;i--)
		if(Ans<(Ans^Base[i]))Ans = Ans^Base[i];
	std::cout<<Ans;
	return 0;
}
