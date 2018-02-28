#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define gi get_int()
long long get_int()
{
	long long x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long Num[50001];
long long f[1001];
bool flag = false;
long long n,g,r;

long long Get_ans(int Val)
{
	Val = Val%(g+r);
	if(flag==true)
		if(f[Val]!=-1)return f[Val];
	long long Count = (Num[0]+Val)%(g+r);
	long long Ans = Num[0];;
	for(int i = 1;i<=n;i++)
	{
		if(Count>=g)Ans+=(g+r)-Count,Count = 0;
		Count = (Count+Num[i])%(g+r);
		Ans+=Num[i];
	}
	if(flag==true)f[Val] = Ans;
	return Ans;
}

int main()
{
	memset(f,-1,sizeof(f));
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n = gi,g = gi,r = gi;
	for(int i = 0;i<=n;i++)
		Num[i] = gi;
	int q = gi;
	if(g+r<=1000)flag = true;
	for(int i = 0;i<q;i++)
	{
		int Val = gi;
		std::cout<<Val+Get_ans(Val)<<std::endl;
	}
	return 0;
}
