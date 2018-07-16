#include<iostream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Q[100],p[100],s[100],n;
int Temp[100];

bool Judge()
{
	for(int i = 0;i<n;i++)Temp[i] = s[i];
	for(int i = 0;i<n-1;i++)
		std::swap(Temp[Q[i]],Temp[Q[i]+1]);
	for(int i = 0;i<n;i++)if(Temp[i]!=p[i])return false;
	return true;
}

int main()
{
	File(swap);
	n = gi;
	for(int i = 0;i<n;i++)
		p[i] = gi,
		s[i] = i;
	for(int j = 0;j<n-1;j++)
		Q[j] = j;
	int Ans = 0;
	do
	{
		if(Judge()==true)Ans++;
	}
	while(std::next_permutation(Q,Q+n-1));
	std::cout<<Ans;
	return 0;
}
