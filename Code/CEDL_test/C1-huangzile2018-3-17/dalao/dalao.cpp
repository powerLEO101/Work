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

int n,m,gx[4] = {1,-1,0,0},gy[4] = {0,0,1,-1};
long long Ans;

int Qpow(int a,int b)
{
	int Temp = a,Ans = 1;
	while(b!=0)
	{
		if(b&1==1)Ans = (Ans*Temp)%MOD;
		Temp = (Temp*Temp)%MOD;
		b>>=1;
	}
	return Ans;
}

void Get_ans(int x,int y,int t)
{
	if(t==0)
	{
		Ans = Ans+(Qpow(x,n)*Qpow(y,m))%MOD;
		return;
	}
	for(int i = 0;i<4;i++)
	{
		int Tx = x+gx[i],Ty = y+gy[i];
		Get_ans(Tx,Ty,t-1);
	}
}

int main()
{
	freopen("dalao.in","r",stdin);
	freopen("dalao.out","w",stdout);
	int x = gi,y = gi,t = gi;
	n = gi,m = gi;
	Get_ans(x,y,t);
	std::cout<<Ans;
	return 0;
}

