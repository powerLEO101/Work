#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define re register
using namespace std;
typedef long long ll;

inline int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=100000+10,V=400000+10,E=2000000+10;

int n,m,s,t;
struct sedge { int v,w,id; };
bool operator <(sedge a,sedge b) { return a.w<b.w; }
vector<sedge> G[N];

struct edge { int v,w,nxt; } e[E];
int head[V];
inline void addEdge(int u,int v,int w) {
	static int cnt=0;
	e[++cnt]=(edge){v,w,head[u]},head[u]=cnt;
}

struct node { int u; ll d; };
bool operator <(node a,node b) { return a.d>b.d; }
ll dis[V];
inline void dijkstra() {
	memset(dis,0x3f,sizeof(dis)),dis[s]=0;
	priority_queue<node> Q; Q.push((node){s,0});
	while (!Q.empty()) {
		int u=Q.top().u; ll d=Q.top().d; Q.pop();
		if (dis[u]!=d) continue;
		for (re int i=head[u];i;i=e[i].nxt) {
			int v=e[i].v,w=e[i].w;
			if (dis[u]+w<dis[v])
				dis[v]=dis[u]+w,Q.push((node){v,dis[v]});
		}
	}
}

int main() {
	n=read(),m=read(),s=0,t=1;
	for (re int i=1;i<=m;++i) {
		int u=read(),v=read(),w=read();
		G[u].push_back((sedge){v,w,i<<1});
		G[v].push_back((sedge){u,w,i<<1|1});
	}
	for (re int i=1;i<=n;++i) {
		sort(G[i].begin(),G[i].end());
		for (re int j=0;j<G[i].size();++j) {
			addEdge(G[i][j].id^1,G[i][j].id,G[i][j].w);
			if (i==1) addEdge(s,G[i][j].id,G[i][j].w);
			if (G[i][j].v==n) addEdge(G[i][j].id,t,G[i][j].w);
		}
		for (re int j=1;j<G[i].size();++j) {
			addEdge(G[i][j-1].id,G[i][j].id,G[i][j].w-G[i][j-1].w);
			addEdge(G[i][j].id,G[i][j-1].id,0);

		}
	}
	dijkstra(); printf("%lld\n",dis[t]);
	return 0;
}
