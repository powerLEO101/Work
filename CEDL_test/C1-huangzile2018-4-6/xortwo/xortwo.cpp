#include<iostream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[10001],Ans[10001];

int main()
{
	freopen("xortwo.in","r",stdin);
	freopen("xortwo.out","w",stdout);
	int n = gi,k = gi,T = gi;
	for(int i = 0;i<n;i++)Num[i] = gi;
	while(T--)
	{
		for(int i = 0;i<n;i++)
			for(int j = 0;j<k;j++)Ans[i]^=Num[(i+j)%n];
		for(int i = 0;i<n;i++)
			Num[i] = Ans[i],
			Ans[i] = 0;
	}
	for(int i = 0;i<n;i++)std::cout<<Num[i]<<" ";
	return 0;
}
