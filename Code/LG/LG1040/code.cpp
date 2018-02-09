#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define INF 0x3f3f3f3f

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[101],Dp[101][101],Root[101][101];

int Get_ans(int l,int r)
{
	if(l==r)return Num[l];
	if(l>r)return 1;
	if(Dp[l][r]!=0)return Dp[l][r];
	int Ans = -INF,root;
	for(int i = l;i<=r;i++)
	{
		int Temp = Get_ans(l,i-1)*Get_ans(i+1,r)+Num[i];
		if(Ans<Temp)root = i;
		Ans = std::max(Ans,Temp);
	}
	Root[l][r] = root;
	Dp[l][r] = Ans;
	return Ans;
}

void Dfs(int l,int r)
{
	if(l==r)std::cout<<l+1<<" ";
	if(l>=r)return;
	std::cout<<Root[l][r]+1<<" ";
	Dfs(l,Root[l][r]-1);
	Dfs(Root[l][r]+1,r);
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)Num[i] = gi;
	std::cout<<Get_ans(0,n-1)<<std::endl;
	Dfs(0,n-1);
	return 0;
}
