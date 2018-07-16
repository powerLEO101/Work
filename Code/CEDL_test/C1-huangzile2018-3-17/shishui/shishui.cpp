#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

int Tx,Ty,Tz;
long long f[300][300][300];

long long Get_ans(int x,int y,int z)
{
	if(f[x][y][z]!=0)return f[x][y][z];
	if(Tx==x&&Ty==y&&Tz==z)
		return 1;
	if(z>Tz)return 0;
	if(x>Tx)return 0;
	if(y>Ty)return 0;
	int Ans = 0;
	for(int i = x+1;i<=Tx;i++)
	for(int j = y+1;j<=Ty;j++)
	for(int k = z+1;k<=Tz;k++)
		Ans += Get_ans(i,j,k);
	if(z==0)
	{
		Ans += Get_ans(x+1,y,z);
		Ans += Get_ans(x,y+1,z);
	}
	Ans = Ans%MOD;
	return f[x][y][z] = Ans;
}

int main()
{
	freopen("shishui.in","r",stdin);
	freopen("shishui.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)
	{
		memset(f,0,sizeof(f));
		Tx = gi,Ty = gi,Tz = gi;
		std::cout<<Get_ans(0,0,0)<<std::endl;
	}
	return 0;
}
