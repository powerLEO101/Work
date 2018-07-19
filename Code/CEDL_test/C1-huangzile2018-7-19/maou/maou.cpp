#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 10001
#define MOD 1000007
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long Num[_],Max[_],f[2][_];

int main()
{
	File(maou);
	int n = gi;
	for(int i = 0;i<n;i++)Num[i] = gi,f[0][i] = 1;
	for(int i = 1;i<n;i++)Max[i] = std::max(Max[i-1],Num[i-1]);
	int op = 0;
	long long Ans = 0;
	for(int i = n-1;i>=0;i--)
	{
		long long t = f[op][Max[i]]*(Num[i]-1)%MOD;
		Ans = (Ans+t)%MOD;
		for(int j = 0;j<i;j++)
			f[op^1][j] = (f[op][j]*j+f[op][j+1])%MOD;
		op = op^1;
	}
	std::cout<<Ans+1;
	return 0;
}
