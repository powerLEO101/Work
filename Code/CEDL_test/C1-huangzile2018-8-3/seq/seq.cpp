#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[1001];
int Sum(int l,int r){return Num[r]-Num[l-1];}
int Get_ans(int l,int r,int P)
{
	int Ans = INF;
	for(int i = l;i<=r;i++)
		for(int j = i;j<=r;j++)
			Ans = std::min(Ans,Sum(i,j)%P);
	return Ans;
}

int main()
{
	File(seq);
	int n = gi,m = gi;
	Num[0] = gi;
	for(int i = 1;i<n;i++)Num[i] = gi+Num[i-1];
	for(int i = 0;i<m;i++)
	{
		int l = gi-1,r = gi-1,P = gi;
		std::cout<<Get_ans(l,r,P)<<std::endl;
	}
	return 0;
}
