#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1005;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,a[N];
struct edge{
	int v,ne;
}e[N*N];
int h[N],cnt=0;
inline void ins(int u,int v){
	cnt++;
	e[cnt].v=v;e[cnt].ne=h[u];h[u]=cnt;
	cnt++;
	e[cnt].v=u;e[cnt].ne=h[v];h[v]=cnt;
}
int f[N];
void dp(){
	f[n]=a[n];
	for(int i=n-1;i>=1;i--) f[i]=min(f[i+1],a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]<a[j]&&f[j]<a[i]) ins(i,j);
}
int col[N];
bool color(int u,int c){
	col[u]=c;
	for(int i=h[u];i;i=e[i].ne){
		int v=e[i].v;
		if(col[v]==col[u]) return false;
		if(!col[v]&&!color(v,3-c)) return false;
	}
	return true;
}
int s1[N],t1=0,s2[N],t2=0;
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	dp();
	for(int i=1;i<=n;i++) if(!col[i]&&!color(i,1)) {putchar('0');return 0;}

	int cur=1;
	for(int i=1;i<=n;i++){
		if(col[i]==1) s1[++t1]=a[i],printf("a ");
		else s2[++t2]=a[i],printf("c ");
		while(s1[t1]==cur||s2[t2]==cur){
			if(s1[t1]==cur){printf("b ");t1--;}
			else {printf("d ");t2--;}
			cur++; 
		}
	}
}
