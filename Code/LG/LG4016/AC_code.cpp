#include<cstdio>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 2147483647
using namespace std;
queue<int> f;
    int n,m,len=0,st,ed;
    struct node{int x,y,c,d,next;} a[10000];
    int b[10000],last[10000],dis[10000],pre[10000],pos[10000],p[10000];
    bool bz[10000];
void ins(int x,int y,int c,int d)
{
    a[len].x=x;a[len].y=y;a[len].c=c;a[len].d=d;a[len].next=last[x];last[x]=len++;
}
bool spfa()
{
    memset(bz,true,sizeof(bz));
    bz[st]=false;
    memset(dis,63,sizeof(dis));
    dis[st]=0;
    p[st]=INF;
    f.push(st);
    while(!f.empty())
    {
        int x=f.front();
        bz[x]=true;
        for(int i=last[x];i!=-1;i=a[i].next)
        {
            int y=a[i].y;
            if(a[i].c>0&&dis[y]>dis[x]+a[i].d)
            {
                dis[y]=dis[x]+a[i].d;
                pos[y]=x;
                pre[y]=i;
                p[y]=min(p[x],a[i].c);
                if(bz[y])
                {
                    f.push(y);
                    bz[y]=false;
                }
            }
        }
        f.pop();
    }
    return dis[ed]<1061109567;
}
int flow()
{
    int ans=0;
    while(spfa())
    {
        ans+=p[ed]*dis[ed];
        for(int i=ed;i!=st;i=pos[i])
        {
            a[pre[i]].c-=p[ed];
            a[pre[i]^1].c+=p[ed];
        }
    }
    return ans;
}
int main()
{
	freopen("code.in", "r", stdin);
    int sum=0;
    scanf("%d",&n);
    st=0;ed=n+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        sum+=b[i];
    }
    sum/=n;
    memset(last,-1,sizeof(last));
    for(int i=1;i<=n;i++)
        if(b[i]>sum)
            ins(st,i,b[i]-sum,0),ins(i,st,0,0);
        else
            ins(i,ed,sum-b[i],0),ins(ed,i,0,0);
    for(int i=2;i<=n;i++)
    {
        ins(i-1,i,INF,1),ins(i,i-1,0,-1);
        ins(i,i-1,INF,1),ins(i-1,i,0,-1);
    }
    ins(1,n,INF,1),ins(n,1,0,-1);
    ins(n,1,INF,1),ins(1,n,0,-1);
    printf("%d",flow());
}
