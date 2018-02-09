#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<string>
#define gi get_int()

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::string Word[10];
int w[1001][1001],Dp[1001][1001];

int Get(std::string str,int s)
{
	int Count = 0;
	for(int i = 0;i<s;i++)
	{
		bool Flag = false;
		for(int j = 0;j<Word[i].size();j++)
			if(str[j]!=Word[i][j])
			{
				Flag = true;
				break;
			}
		if(Flag==false)Count++;
	}
	if(Count!=0)return 1;
	return 0;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int p = gi,k = gi;
	std::string str;
	for(int i = 0;i<p;i++)
	{
		std::string Temp;
		std::cin>>Temp;
		str = str+Temp;
	}
	p*=20;
	int s = gi;
	for(int i = 0;i<s;i++)
		std::cin>>Word[i];
	for(int j = p-1;j>=0;j--)
	for(int i = j-1;i>=0;i--)
		w[i][j] = w[i+1][j]+Get(str.substr(i,j-i+1),s);
	for(int i = 1;i<k;i++)Dp[i][i] = Dp[i-1][i-1]+w[i][i];
	for(int i = 0;i<p;i++)Dp[i][1] = w[0][i];
	for(int i = 0;i<p;i++)
	for(int j = 2;j<=k&&j<i;j++)
	for(int x = j;x<i;x++)
		Dp[i][j] = std::max(Dp[i][j],Dp[x][j-1]+w[x+1][i]);
	std::cout<<Dp[p-1][k];
	return 0;
}
