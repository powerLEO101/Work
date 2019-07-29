#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define in inline
#define get getchar()
in int read()
{
    int t=0; char ch=get;
    while(ch<'0' || ch>'9') ch=get;
    while(ch<='9' && ch>='0') t=t*10+ch-'0',ch=get;
    return t;
}
const int _=1e5+5;
struct qu{
    int l,r,t,id;
}a[_];  // 询问操作
struct mo{
    int x,now,last;
}modify[_]; //修改操作, now是修改前的数字,last是修改后的,x记录修改位置
int n,m,sum[_*10],c1[_],c[_],qtot,rtot,block,ans,s[_];
in void add(int x) //加入
{
    sum[c[x]]++;
    if(sum[c[x]]==1)ans++;
}
in void del(int x) //删除
{
    sum[c[x]]--;
    if(sum[c[x]]==0)ans--;
}
in int cmp(qu a,qu b) //排序顺序 
{
    if((a.l-1)/block==(b.l-1)/block)
    {
        if((a.r-1)/block==(b.r-1)/block)return a.t<b.t;
        return a.r<b.r;
    }
    else return a.l<b.l;
}
in void change(int i,int l,int r,bool flag) //修改
{
    int x=modify[i].x;
    if(x>=l&&x<=r)
        del(x);
    c[x]=flag?modify[i].now:modify[i].last;
    if(x>=l&&x<=r)
        add(x);
}
int main()
{
    n=read(),m=read();
    block=sqrt(n);
    for(re int i=1;i<=n;i++)
        c1[i]=c[i]=read(); //需要 c1 数组记录序列初始状态
    for(re int i=1;i<=m;i++)
    {
        char ch=get;
        while(ch!='Q'&&ch!='R')ch=get;
        int x=read(),y=read();
        if(ch=='Q') a[++qtot].l=x,a[qtot].r=y,a[qtot].t=rtot,a[qtot].id=qtot;
        else modify[++rtot].x=x,modify[rtot].now=c[x],modify[rtot].last=y,c[x]=y;
    }
    for(re int i=1;i<=n;i++) c[i]=c1[i];
    sort(a+1,a+qtot+1,cmp);
    int l,r,tnow;
    l=a[1].l,r=a[1].r,tnow=a[1].t;
    for(re int i=l;i<=r;i++)
        add(i);
    for(re int i=1;i<=tnow;i++)
        change(i,l,r,0);
    s[a[1].id]=ans;
    for(re int i=2;i<=qtot;i++)
    {
        while (l<a[i].l) del(l++);
        while (l>a[i].l) add(--l);
        while (r<a[i].r) add(++r);
        while (r>a[i].r) del(r--);
        while (tnow<a[i].t) change(++tnow,l,r,0);
        while (tnow>a[i].t) change(tnow--,l,r,1);
        s[a[i].id]=ans;
    }
    for(re int i=1;i<=qtot;i++)
        cout<<s[i]<<endl;
}
