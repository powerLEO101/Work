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
	while ((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if (ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[500001];
int w[500001];

void CASE1(int n)
{
	int Ans = 0;
	for(int i = 0;i<n;i++)
	{
		if(w[i]==0)continue;
		if(w[i]!=w[i+1]&&w[i+1]!=0)
		{
			std::cout<<-1;
			return;
		}
	}
	for(int i = 0;i<n;i++)
	{
		if(w[i]==w[i+1])continue;
		if(w[i+1]!=0)
		{
			std::cout<<-1<<" "<<w[i]<<" "<<w[i+1]<<" "<<Ans;
			return;
		}
		int j = i+1;
		while(w[j]==0&&j<n)j++;
		i = j;
		Ans++;
	}
	std::cout<<Ans;
}

int main()
{
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	int n = gi;
	for(int i = 1;i<n;i++)
	{
		int u = gi,v = gi;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	for(int i = 0;i<n;i++)w[i] = gi;
	CASE1(n);
	return 0;
}
