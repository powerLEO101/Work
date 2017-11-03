#include<iostream>
#include<iomanip>
#include<fstream>
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

int Num[100001],f[100001][2];

int Get_ans(int n)
{
	f[0][1] = -0x3f3f3f3f;
	for(int i = 1;i<=n;i++)
	{
		f[i][0] = std::max(f[i-1][0],f[i-1][1]+Num[i]);
		f[i][1] = std::max(f[i-1][1],f[i-1][0]-Num[i]);
	}
	return std::max(f[n][1],f[n][0]);
}

int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int T = gi;
	while(T--)
	{
		int n = gi,Q = gi;
		for(int i = 1;i<=n;i++)Num[i] = gi;
		for(int i = 0;i<Q;i++)
		{
			int Mode = gi;
			if(Mode==1)std::cout<<Get_ans(n)<<" "<<654<<std::endl;
			if(Mode==0)
			{
				int l = gi,r = gi,val = gi;
				for(int j = l;j<=r;j++)
					Num[j]+=val;
			}
		}
	}
	return 0;
}
