#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[100001];
bool vis[1000001];
int Ans = -INF;

void Get_ans(int Now,int Val)
{
	if(vis[Now]==true)return;
	vis[Now] = true;
	Ans = std::max(Ans,Val);
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
		Get_ans(*it,Val+1);
}

int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int u = gi-1,v = gi-1;
		Map[u].push_back(v);
	}	
	for(int i = 0;i<n;i++)Get_ans(i,1);
	std::cout<<Ans<<" "<<Ans;
	return 0;
}
