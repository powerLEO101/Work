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

int x[10001];
int n,a,b,c;

int Get()
{
	for(int i = 0;i<n;i++)
		if(((a*(i+2)*(x[i]*x[i]))+((b+1)*(i+1)*x[i])+(c+i+1))==0)return i+1;
	return -1;
}

int main()
{
	File(seq);
	n = gi;
	for(int i = 0;i<n;i++)
		x[i] = gi;
	int LastAns = 0;
	a = gi+LastAns,b = gi+LastAns,c = gi+LastAns;
	while(!(a==0&&b==0&&c==0))
	{
		LastAns = Get();
		std::cout<<LastAns<<std::endl;
		a = gi+LastAns,b = gi+LastAns,c = gi+LastAns;
	}
	return 0;
}
