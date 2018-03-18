#include<iostream>
#include<cstdio>
#include<algorithm>

int n,m,x,y,tot;

int Max[100001],las[100001],to[100001],nxt[100001];

void add()
{
	 scanf("%d%d",&y,&x);
	 nxt[++tot]=las[x];
	 las[x]=tot;
	 to[tot]=y;
}
void dfs(int now,int st)
{
	 if(Max[now])
		  return;
	 Max[now] = st;
	 for(int e = las[now];e;e = nxt[e])
		  if(!Max[to[e]])dfs(to[e],st);
	 return;
}
int main()
{
	std::cin>>n>>m;
	for(int i = 1;i<=m;++i)
		add();
	for(int i = n;i;--i)
		dfs(i,i);
	for(int i = 1;i<=n;++i)
		std::cout<<Max[i]<<" ";
	return 0;
}
