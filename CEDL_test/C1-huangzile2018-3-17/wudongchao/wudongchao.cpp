#include<iostream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define MOD 1000000007
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Map[1001][1001],V[1001];
bool Use[1001];
long long Ans;
int n,k;

int Get()
{
	long long Temp = 1;
	for(int i = 1;i<=n;i++)
		Temp = (Temp*Map[i][V[i]])%MOD;
	return Temp;
}

void Get_ans(int Now)
{
	if(Now==0)
	{
		Ans = (Ans+Get())%MOD;
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(Use[i]==true)continue;
		Use[i] = true;
		V[Now] = i;
		Get_ans(Now-1);
		Use[i] = false;
	}
}

int main()
{
	freopen("wudongchao.in","r",stdin);
	freopen("wudongchao.out","w",stdout);
	n = gi,k = gi;
	for(int i = 0;i<1001;i++)
	for(int j = 0;j<1001;j++)
		Map[i][j] = 1;
	for(int i = 0;i<k;i++)
	{
		int x = gi,y = gi,Val = gi;
		Map[x][y] = Val;
	}
	Get_ans(n);
	std::cout<<Ans;
	return 0;
}
