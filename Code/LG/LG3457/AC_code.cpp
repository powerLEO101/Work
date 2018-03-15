#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using std::sort;
int m,a[1010][1010],cnt;
int f[1000010];
struct gjh{
	int x,y,w;
	bool operator<(gjh b){
		return w<b.w;
	}
	bool operator>(gjh b){
		return w>b.w;
	}
}h[1000010];
int number(int i,int j){return (i-1)*m+j;}
int find(int x){if(f[x]!=x)f[x]=find(f[x]);return f[x];}
int vis[1010][1010],b[1000010];
int wa[5]={0,1,0,-1,0},
    lk[5]={0,0,1,0,-1};
void join(int x,int y){
	for(int i=1;i<=4;i++){
		int tx=x+wa[i],ty=y+lk[i];
		if(!vis[tx][ty])continue;
		b[number(x,y)]|=b[find(number(tx,ty))];
		f[find(number(tx,ty))]=number(x,y);
	}
}
int main(){
	freopen("AC_code.in","r",stdin);
	freopen("AC_code.out","w",stdout);
	int i,j,k,n;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			f[number(i,j)]=number(i,j);
			h[++cnt]=(gjh){i,j,abs(a[i][j])};
		}
	sort(h+1,h+cnt+1);
	int last=1,ans=0;
	for(i=1;i<=cnt;i++){
		join(h[i].x,h[i].y);
		vis[h[i].x][h[i].y]=1;
		if(h[i].w!=h[i+1].w){
			for(j=last;j<=i;j++)
				if(a[h[j].x][h[j].y]>0 && !b[find(number(h[j].x,h[j].y))]){
					b[find(number(h[j].x,h[j].y))]=1;
					ans++;
					std::cout<<i<<" "<<j<<std::endl;
				}
			last=i+1;
		}
	}
	for(int i = 1;i<=cnt;i++)
		std::cout<<h[i].x<<" "<<h[i].y<<" "<<h[i].w<<std::endl;
	if(last<n+1)
		for(i=last;i<=n;i++)
			if(a[h[j].x][h[j].y]>0 && !b[find(number(h[j].x,h[j].y))]){
				b[find(number(h[j].x,h[j].y))]=1;
				ans++;
			}
	printf("%d\n",ans);
	return 0;
}
