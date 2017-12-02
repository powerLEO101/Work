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
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[999999];
bool Vis[999999];
int Kill[999999],ans[999999];

int Father[999999];
void init(){for(int i = 0;i<999999;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}

int Count(int n)
{
	int Count = 0;
	for(int i = 0;i<n;i++)
		if(Father[i]==i&&Vis[i]==false)Count++;
	return Count;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,k;
	for(int i = 0;i<m;i++)
	{
		int u = gi,v = gi;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	init();
	k = gi;
	for(int i = 0;i<k;i++)
	{
		int u = gi;
		Vis[u] = true;
		Kill[i] = u;
	}
	for(int i = 0;i<n;i++)
	{
		if(Vis[i]==true)continue;
		for(int j = 0;j<Map[i].size();j++)
			if(Vis[Map[i][j]]==false)
				Merge(i,Map[i][j]);
	}
	int Ans = Count(n);
	ans[0] = Ans;
	int Index = 1;
	for(int x = k-1;x>=0;x--)
	{
		int u = Kill[x];
		Ans++;
		for(int i = 0;i<Map[u].size();i++)
		{
			if(Vis[Map[u][i]]==true)continue;
			if(Get_father(u)==Get_father(Map[u][i]))continue;
			Ans--;
			Merge(u,Map[u][i]);
		}
		Vis[u] = false;
		ans[Index++] = Ans;
	}
	for(int i = Index-1;i>=0;i--)std::cout<<ans[i]<<std::endl;
	return 0;
}
