#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while( ch<='9' && ch>='0' )x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[100001];

int Get(int Index,int Sum)
{
	int Ans = 0;
	for(int i = 0;i<Index;i++)
	for(int j = i+1;j<Index;j++)
		if(Num[i]+Num[j]==Sum)Ans++;
	return Ans;
}

int main()
{
	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);
	long long n = gi,Ans = 0;
	for(int i = 0;i<n;i++)Num[i] = gi;
	std::sort(Num,Num+n);
	for(int i = 2;i<n-1;i++)
	{
		if(Num[i]!=Num[i+1])continue;
		int j = 0;
		while(Num[i]==Num[i+j])j++;
		int Temp = 0;
		for(int x = 0;x<j;x++)
		for(int y = x+1;y<j;y++)
			Temp++;
		Ans = (Ans+(Get(i,Num[i])*Temp))%MOD;
		i+=(j-1);
	}
	std::cout<<Ans;
	return 0;
}
