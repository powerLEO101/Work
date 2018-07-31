#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
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

int Map[1001][1001],Dist[1001][1001],Pre[1001][1001];
int Path[1001],Length;

void Get_path(int From,int To)
{
	if(Pre[From][To]==-1)return;
	Get_path(From,Pre[From][To]);
	Path[Length++] = Pre[From][To];
	Get_path(Pre[From][To],To);
}

int main()
{
	File(code);
	int n = gi,m = gi;
	memset(Map,0x3f,sizeof(Map));
	memset(Pre,-1,sizeof(Pre));
	for(int i=0;i<n;++i)Map[i][i]=0;
	for(int i = 0;i<m;i++)
	{
		int u = gi-1,v = gi-1,w = gi;
		Map[u][v] = Map[v][u] = std::min(Map[u][v],w);
	}
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			Dist[i][j] = Map[i][j];
	long long Ans = INF;
	for(int k = 0;k<n;k++)
	{
		for(int i = 0;i<k;i++)
			for(int j = i+1;j<k;j++)
			{
				if(Ans<=(long long)Dist[i][j]+Map[i][k]+Map[k][j])continue;
				Length = 0;
				Ans = Dist[i][j]+Map[i][k]+Map[k][j];
				Path[Length++] = i;
				Get_path(i,j);
				Path[Length++] = j;
				Path[Length++] = k;
			}
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
			{
				if(Dist[i][j]<=(Dist[i][k]+Dist[k][j]))continue;
				Dist[i][j] = Dist[i][k]+Dist[k][j];
				Pre[i][j] = k;
			}
	}
	if(Ans==INF)std::cout<<"No solution.";
	else 
		for(int i = 0;i<Length;i++)std::cout<<Path[i]+1<<" ";
	return 0;
}
