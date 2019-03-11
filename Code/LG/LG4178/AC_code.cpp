#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0;char ch=' ';int f=1;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct edge{
	int to,next,w;
}e[80001];
int n,tot,root;
ll k;
int head[40001];
inline void addedge(int x,int y,int l){
	e[++tot].to=y;e[tot].next=head[x];e[tot].w=l;head[x]=tot;
}
int size[40001],vis[40001],mx,sz;
ll dis[40001],q[40001],l,r;
void getroot(int x,int fa){
	size[x]=1;int num=0;
	for(int i=head[x];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa||vis[u])continue;
		getroot(u,x);
		size[x]+=size[u];
		num=max(num,size[u]);
	}
	num=max(num,sz-size[x]);
	if(num<mx){
		mx=num;root=x;
	}
}
void getdis(int x,int fa){
	q[++r]=dis[x];
	for(int i=head[x];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa||vis[u])continue;
		dis[u]=dis[x]+e[i].w;
		getdis(u,x);
	}
}
ll calc(int x,int v){
	r=0;
	dis[x]=v;
	getdis(x,0);
	ll sum=0;
	l=1;
	sort(q+1,q+r+1);
	for (int i = 1; i <= r; i++)
		printf("%lld ", q[i]);
	printf("\n");
	while(l<r){
		if(q[l]+q[r]<=k)sum+=r-l,l++;
		else r--;
	}
	return sum;
}
ll ans;
void dfs(int x){
	ans+=calc(x,0);
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int u=e[i].to;
		if(vis[u])continue;
		ans-=calc(u,e[i].w);
		sz=size[u];
		mx=0x3f3f3f3f;
		getroot(u,0);
		dfs(root);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read(),l=read();
		addedge(x,y,l);addedge(y,x,l);
	}
	k=read();
	sz=n;
	mx=0x3f3f3f3f;
	getroot(1,0);
	dfs(root);
	printf("%lld",ans);
	return 0;
}
