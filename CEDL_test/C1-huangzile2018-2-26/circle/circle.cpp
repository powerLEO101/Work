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
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int n,m,cnt;
int state[100];

long long calc()
{
	cnt++;
	bool flag = false;
	long long Count = 1,Ans = 1,Count1 = 1;
	for(int i = 1;i<n;i++)
	{
		if(flag==false&&state[i]==state[i-1])
		{
			Count1++;
			if(i==n-1)Count = 0;
			continue;
		}
		if(flag==false&&state[i]!=state[i-1])flag = true;
		if(state[i]==state[i-1])Count++;
		else Ans*=Count,Count = 1;
	}
	if(state[0]==state[n-1])Ans*=(Count+Count1);
	else Ans*=(Count*Count1);
	return Ans;
}
long long Get_ans(int Now)
{
	if(Now==n)return calc();
	long long Ans = 0;
	for(int i = 0;i<m;i++)
	{
		state[Now] = i;
		Ans+=Get_ans(Now+1);
	}
	return Ans;
}

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	n = gi,m = gi;
	printf("%0.8f",Get_ans(0)/(cnt*1.0));
	return 0;
}
