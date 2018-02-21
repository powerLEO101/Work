#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[2002];
int Dp[2002][2];
bool Vis[2002];

void Get_ans(int Now)
{
	if(Vis[Now]==true)return;
	Vis[Now] = true;
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
	{
		Get_ans(*it);
		Dp[Now][0]+=Dp[*it][1];
		Dp[Now][1]+=std::min(Dp[*it][1],Dp[*it][0]);
	}
	Dp[Now][1]++;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)
	{
		int u = gi,k = gi;
		for(int j = 0;j<k;j++)
		{
			int v = gi;
			Map[u].push_back(v);
			Map[v].push_back(u);
		}
	}
	Get_ans(0);
	std::cout<<std::min(Dp[0][0],Dp[0][1]);
	return 0;
}
