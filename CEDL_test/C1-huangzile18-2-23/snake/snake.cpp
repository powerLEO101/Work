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

std::vector<int> Map[20001];
bool Vis[20001],Flag = false;
bool V[20001];

void Get_ans(int Now)
{
	if(Vis[Now]==true)
	{
		Flag = true;
		return;
	}
	Vis[Now] = true;
	V[Now] = true;
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
		Get_ans(*it);
	Vis[Now] = false;
}

int main()
{
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	int T = gi;
	while(T--)
	{
		int n = gi,m = gi;
		for(int i = 0;i<m;i++)
		{
			int u = gi-1,v = gi-1;
			Map[u].push_back(v);
		}
		for(int i = 0;i<n;i++)
			if(V[i]==false)
				Get_ans(i);
		if(Flag==true)std::cout<<"No";
		else std::cout<<"Yes";
		std::cout<<std::endl;
		Flag = false;
		for(int i = 0;i<=n;i++)Vis[i] = V[i] = false;
	}
	return 0;
}
