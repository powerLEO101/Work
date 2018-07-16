#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define N 50003
using namespace std;
int n,m,a[N],belong[N],block,ans[N],pos[N];
struct data{
    int id,x,y,key;
}q[N];
struct node{
    int ls,rs,tr,len;
}tree[N*4];
int read()
{
    char c=getchar();  int x=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x;
}
inline bool operator <(const data &a,const data &b){
    return a.key<b.key||a.key==b.key&&((a.y<b.y)^(a.key&1));
}
inline void update(int now)
{
    node *T=tree+now,*L=tree+(now<<1),*R=tree+(now<<1|1);
    T->tr=max(L->tr,R->tr);
    T->tr=max(L->rs+R->ls,T->tr);
    T->ls=L->ls+(L->ls==L->len)*R->ls;
    T->rs=R->rs+(R->rs==R->len)*L->rs;
}
inline void pointchange(int x)
{
    int t=pos[x];
    tree[t].ls=tree[t].rs=(tree[t].tr^=1);
    while (t!=1) update(t=t>>1);
}
inline void build(int now,int l,int r)
{
    tree[now].len=r-l+1;
    if (l==r) {
     pos[l]=now;
     return;
    }
    int mid=(l+r)/2;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("my.out","w",stdout);
    n=read(); m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=m;i++)
     q[i].x=read(),q[i].y=read(),q[i].id=i,q[i].key=sqrt(q[i].x);
    sort(q+1,q+m+1);
    build(1,1,n);
    int l,r; l=r=1; pointchange(a[1]);
    for (int i=1;i<=m;++i) {
        while (l<q[i].x) pointchange(a[l++]);
        while (l>q[i].x) pointchange(a[--l]);
        while (r>q[i].y) 
         pointchange(a[r--]);
        while (r<q[i].y) 
         pointchange(a[++r]);
        ans[q[i].id]=tree[1].tr;
    }
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
