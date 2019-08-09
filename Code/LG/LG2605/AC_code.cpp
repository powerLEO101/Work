/*Code by 520 -- 9.25*/
#include<bits/stdc++.h>
#define il inline
#define ll long long
#define RE register
#define For(i,a,b) for(RE int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(RE int (i)=(b);(i)>=(a);(i)--)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=100005;
int n,k,ans,st[N],ed[N];
int d[N],c[N],s[N],w[N],f[N];
int to[N],net[N],h[N],cnt;
int minn[N<<2],lazy[N<<2];
int gi(){
  int a=0;char x=getchar();
  while(x<'0'||x>'9') x=getchar();
  while(x>='0'&&x<='9') a=(a<<3)+(a<<1)+(x^48),x=getchar();
  return a;
}
il void add(int u,int v){to[++cnt]=v,net[cnt]=h[u],h[u]=cnt;}
il void pushup(int rt){minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);}
il void pushdown(int rt){
  if(lazy[rt]){
    minn[rt<<1]+=lazy[rt],minn[rt<<1|1]+=lazy[rt];
    lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
    lazy[rt]=0;
  }
}
void build(int l,int r,int rt){
  lazy[rt]=0;
  if(l==r) {minn[rt]=f[l];return;}
  int m=l+r>>1;
  build(lson),build(rson);
  pushup(rt);
}
void update(int x,int L,int R,int l,int r,int rt){
  if(L<=l&&R>=r) {minn[rt]+=x,lazy[rt]+=x;return;}
  pushdown(rt);
  int m=l+r>>1;
  if(L<=m) update(x,L,R,lson);
  if(R>m) update(x,L,R,rson);
  pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
  if(L<=l&&R>=r) return minn[rt];
  pushdown(rt);
  int m=l+r>>1,res=0x3f3f3f3f;
  if(L<=m) res=min(res,query(L,R,lson));
  if(R>m) res=min(res,query(L,R,rson));
  return res;
}
int main(){
  freopen("code.in", "r", stdin);
  freopen("AC_code.out", "w", stdout);
  n=gi(),k=gi()+1;
  For(i,2,n) d[i]=gi();
  For(i,1,n) c[i]=gi();
  For(i,1,n) s[i]=gi();
  For(i,1,n) w[i]=gi();
  ++n,d[n]=w[n]=0x3f3f3f3f;
  For(i,1,n) {
    st[i]=lower_bound(d+1,d+n+1,d[i]-s[i])-d,
      ed[i]=lower_bound(d+1,d+n+1,d[i]+s[i])-d;
    if(d[ed[i]]>d[i]+s[i]) ed[i]--;
    printf("%d %d\n", st[i], ed[i] - 1);
    add(ed[i],i);
  }
  int tot=0;
  For(i,1,n) {
    f[i]=tot+c[i];
    for(RE int p=h[i];p;p=net[p]) {
      tot+=w[to[p]];
    }
  }

  ans=f[n];
  For(i,2,k) {
    build(1,n,1);
    For(j,1,n) {
      f[j]=(j>i-1?query(i-1,j-1,1,n,1) : 0x3f3f3f3f)+c[j];
      for(RE int p=h[j];p;p=net[p]) 
        if(st[to[p]]>1) {
          update(w[to[p]],1,st[to[p]]-1,1,n,1);
        }
    }
    ans=min(ans,f[n]);
  }
  cout<<ans;
  return 0;
}
