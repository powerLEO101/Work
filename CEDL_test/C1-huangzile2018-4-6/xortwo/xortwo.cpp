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

long long Num[10001],Ans[10001],Num1[10001],n,k,T;

void CASE1()
{
	for(int i = 0;i<n;i++)Num[i] = gi;
	while(T--)
	{
		for(int i = 0;i<n;i++)
			for(int j = 0;j<k;j++)Ans[i]^=Num[(i+j)%n];
		for(int i = 0;i<n;i++)
			Num[i] = Ans[i],
			Ans[i] = 0;
	}
}
void CASE2()
{
	int Count = 0;
	bool flag = false;
	bool F = false;
	for(int i = 0;i<n;i++)Num[i] = gi;
	while(T--)
	{
		for(int i = 0;i<n;i++)
			for(int j = 0;j<k;j++)Ans[i]^=Num[(i+j)%n];
		for(int i = 0;i<n;i++)
			Num[i] = Ans[i],
			Ans[i] = 0;
		if(F==false)
		{
			bool Flag = true;
			for(int i = 0;i<n;i++)
				if(Num[i]!=Num1[i])
				{
					Flag = false;
					break;
				}
			if(Flag==true)
			{
				T = T%(Count),
				F = true;
				std::cout<<Count<<std::endl;
				std::cout<<T<<std::endl;
			}
			Count++;
		}
		if(flag==false)
		{
			flag = true;
			for(int i = 0;i<n;i++)
				Num1[i] = Num[i];
		}
	}
	
}

int main()
{
	freopen("xortwo.in","r",stdin);
	freopen("xortwo.out","w",stdout);
	n = gi,k = gi,T = gi;
	if(n<100&&T<100)CASE1();
	else CASE2();
	for(int i = 0;i<n;i++)std::cout<<Num[i]<<" ";
	return 0;
}
