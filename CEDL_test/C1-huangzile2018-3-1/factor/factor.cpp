#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Get(int Val)
{
	for(int i = 2;i<=sqrt(Val);i++)
		if(Val%i==0)return Val/i;
	return 0;
}

long long Get_ans(int l,int r)
{
	long long Ans = 0;
	if(l<=2)l = 3;
	for(int i = l;i<=r;i++)
	{
		if(i%2==0)
			Ans+=i/2;
		else
			Ans+=Get(i);
	}
	return Ans;
}

int main()
{
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	int l = gi,r = gi;
	std::cout<<Get_ans(l,r);
	return 0;
}
