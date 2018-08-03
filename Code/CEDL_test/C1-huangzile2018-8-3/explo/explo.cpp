#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 100005
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Mod[_],Num[_];

int main()
{
	File(explo);
	int n,w;
	double c,k;
	std::cin>>n>>k>>c>>w;
	for(int i = 0;i<n;i++)
		Mod[i] = gi,
		Num[i] = gi;
	double Ans = 0;
	k = 1-(0.01*k);
	c = 1+(0.01*c);
	for(int i = n-1;i>=0;i--)
	{
		if(Mod[i]==1)Ans = std::max(Ans,Ans*k+Num[i]);
		else Ans = std::max(Ans,Ans*c-Num[i]);
	}
	printf("%0.2lf",Ans*w);
	return 0;
}
