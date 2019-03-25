#include <bits/stdc++.h>
#define il inline
#define RG register
#define ll long long
#define inf (1<<29)

using namespace std;

struct data{ int x,y,bin; }p[15];

const int d1[4]={0,0,-1,1};
const int d2[4]={-1,1,0,0};

int f[15][15][1<<12],vis[15][15][1<<12],g[15][15],val[15],S,n,m,all,ans;

queue<data> Q;

il int gi(){
	RG int x=0,q=1; RG char ch=getchar();
	while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if (ch=='-') q=-1,ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
	return q*x;
}

il char gc(){
	RG char ch=getchar();
	while ((ch<'0' || ch>'9') && ch!='#') ch=getchar();
	return ch;
}

il void spfa(RG int sx,RG int sy){
	for (RG int i=1;i<=n;++i)
		for (RG int j=1;j<=m;++j)
			for (RG int k=0;k<all;++k) f[i][j][k]=-inf;
	Q.push((data){sx,sy,0}),f[sx][sy][0]=0,vis[sx][sy][0]=1;
	while (!Q.empty()){
		RG data now=Q.front(); Q.pop();
		if (now.x==sx && now.y==sy)
			ans=max(ans,f[now.x][now.y][now.bin]);
		for (RG int k=0,x,y,yy,bin,del;k<4;++k){
			x=now.x+d1[k],y=now.y+d2[k];
			if (x<=0 || x>n || y<=0 || y>m || g[x][y]) continue;
			bin=now.bin,yy=max(y,now.y),del=0;
			if (k<=1){
				for (RG int i=1;i<=S;++i)
					if (p[i].y==yy && p[i].x<x){
						bin^=1<<(i-1);
						if (bin>>(i-1)&1) del+=val[i]; else del-=val[i];
					}
			}
			if (f[x][y][bin]<f[now.x][now.y][now.bin]+del-1){
				f[x][y][bin]=f[now.x][now.y][now.bin]+del-1;
				if (!vis[x][y][bin]) vis[x][y][bin]=1,Q.push((data){x,y,bin});
			}
		}
		vis[now.x][now.y][now.bin]=0;
	}
	return;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("bean.in","r",stdin);
	freopen("bean.out","w",stdout);
#endif
	n=gi(),m=gi(),S=gi(),all=1<<S;
	for (RG int i=1;i<=S;++i) val[i]=gi();
	for (RG int i=1;i<=n;++i)
		for (RG int j=1;j<=m;++j){
			RG char ch=gc();
			if (ch=='#') g[i][j]=-1; else g[i][j]=ch-'0';
			if (g[i][j]>=1 && g[i][j]<=9) p[g[i][j]]=(data){i,j};
		}
	for (RG int i=1;i<=n;++i)
		for (RG int j=1;j<=m;++j) if (!g[i][j]) spfa(i,j);
	cout<<ans; return 0;
}
