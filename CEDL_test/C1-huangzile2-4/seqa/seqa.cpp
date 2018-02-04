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

long long Num[100001];

bool check(int MID,int n,int k)
{
	long long Ans = Num[0];
	long long Count = 1;
	for(int i = 1;i<n;i++)
	{
		if(Ans+Num[i]<MID)Ans+=Num[i];
		else Ans = Num[i],Count++;
	}
	if(Count>k)return false;
	return true;
}

int main()
{
	freopen("seqa.in","r",stdin);
	freopen("seqa.out","w",stdout);
	int n = gi,k = gi;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	long long l = 0,r = 100000000000000;
	while(l<r)
	{
		int MID = (l+r)/2;
		if(check(MID,n,k)==true)r = MID-1;
		else l = MID+1;
	}
	std::cout<<l;
	return 0;
}
