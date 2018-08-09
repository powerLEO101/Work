#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

int Dist[1001][1001],n,l,Ans = -INF;
bool Vis[1001];

int Calc()
{
	int Count = 0;
	for(int i = 0;i<n;i++)
	{
		if(Vis[i]==false)continue;
		Count++;
		for(int j = i+1;j<n;j++)
		{
			if(Vis[j]==false)continue;
			if(Dist[i][j]<l)return -1;
		}
	}
	return Count;
}
void Get_ans(int Now = 0)
{
	if(Now==n)
	{
		Ans = std::max(Ans,Calc());
		return;
	}
	Vis[Now] = true;
	Get_ans(Now+1);
	Vis[Now] = false;
	Get_ans(Now+1);
}

int main()
{
	File(inspect);
	memset(Dist,0x3f,sizeof(Dist));
	n = gi,l = gi;
	for(int i = 1;i<n;i++)
	{
		int From = gi-1,To = gi-1,Value = gi;
		Dist[From][To] = Dist[To][From] = Value;
	}
	for(int i = 0;i<n;i++)Dist[i][i] = 0;
	for(int k = 0;k<n;k++)
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				if(Dist[i][j]>Dist[i][k]+Dist[k][j])
					Dist[i][j] = Dist[i][k]+Dist[k][j];
	Get_ans();
	std::cout<<Ans;
	return 0;
}
