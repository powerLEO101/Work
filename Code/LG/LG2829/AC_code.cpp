#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=5002,M=100002,INF=1e9+7;
int n,m,k,cnt,u,v,w,mindist,secdist=INF;
int last[N],t[N],dist[2][N];
bool used[N],vis[N];
struct edg{
    int to,next,w;
}edge[2*M];
void insert(int u,int v,int w)
{
    edge[++cnt]=(edg){v,last[u],w};last[u]=cnt;
    edge[++cnt]=(edg){u,last[v],w};last[v]=cnt;
}
void SPFA(int S,int op)
{
    for(int i=1;i<=n;i++)dist[op][i]=INF,used[i]=0;
    queue<int> Q;
    Q.push(S);
    used[S]=1;
    dist[op][S]=0;
    while(!Q.empty())
    {
        int now=Q.front();Q.pop();
        used[now]=0;
        for(int i=last[now];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dist[op][now]+edge[i].w<dist[op][v]&&t[v]>=k)
            {
                dist[op][v]=dist[op][now]+edge[i].w;
                if(!used[v]){Q.push(v);used[v]=1;}
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        insert(u,v,w);
    }
    for(int i=2;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=last[i];j;j=edge[j].next)
        {
            int v=edge[j].to;
            if(!vis[v]){vis[v]=1;t[i]++;}
        }
    }
    t[1]=INF;t[n]=INF;
    SPFA(1,0);
    SPFA(n,1);
    mindist=dist[0][n];
    for(int i=1;i<=n;i++)
    {
        if(t[i]<k)continue;
        for(int j=last[i];j;j=edge[j].next)
        {
            int v=edge[j].to;
            int len=dist[0][i]+edge[j].w+dist[1][v];
            if(len>mindist&&t[v]>=k)secdist=min(secdist,len);
        }
    }
    printf("%d\n",secdist>=INF?-1:secdist);
    return 0;
}
