#include<bits/stdc++.h>
#define RG register
#define clear(x, y) memset(x, y, sizeof(x));
using namespace std;

inline int read()
{
	int data=0, w=1;
	char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1, ch=getchar();
	while(ch>='0'&&ch<='9') data=(data<<3)+(data<<1)+(ch^48), ch=getchar();
	return data*w;
}

const int maxn(40), I(1061109567), x[4]={0, 1, 0, -1}, y[4]={1, 0, -1, 0};
struct node { int x, y, k; };
inline bool operator == (const node &a, const node &b)
{
	return !(a.x^b.x||a.y^b.y);
}

int g[maxn][maxn], dis[maxn][maxn][4], ex, ey, sx, sy,
	tx, ty, mov[maxn][maxn][4][4], n, m, deep[maxn][maxn];
bool inq[maxn][maxn][4], vis[maxn][maxn];
queue<node> q, p;
inline bool ing(const node &x) { return x.x>0 && x.x<=n && x.y>0 && x.y<=m; }
inline int tran(int k) { return (k<2) ? k+2 : k-2; }
inline node go(node a, int k) { return (node){a.x+x[k], a.y+y[k]}; }
inline int BFS(node s, node t) // The queue is q!
{
	if(!(g[s.x][s.y] && g[t.x][t.y])) return I;
	clear(vis, 0); clear(deep, 63);
	q.push(s); deep[s.x][s.y]=0; vis[s.x][s.y]=true;
	while((!q.empty()) && (!vis[t.x][t.y]))
	{
		node x=q.front(); q.pop();
		for(RG int i=0;i<4;i++)
		{
			node y=go(x, i); if(!ing(y)) continue;
			if((!vis[y.x][y.y]) && g[y.x][y.y])
				vis[y.x][y.y]=true, q.push(y), deep[y.x][y.y]=deep[x.x][x.y]+1;
		}
	}
	while(!q.empty()) q.pop();
	return deep[t.x][t.y];
}

inline void init()
{
	clear(mov, 63);
	for(RG int i=1;i<=n;i++)
		for(RG int j=1;j<=m;j++)
		{
			if(!g[i][j]) continue;
			g[i][j]=0;
			for(RG int k=0;k<4;k++)
				for(RG int l=0;l<4;l++)
				{
					if(l<k) { mov[i][j][k][l]=mov[i][j][l][k]; continue; }
					node a=go((node){i, j}, k), b=go((node){i, j}, l);
					if(!ing(a) || !ing(b) || !(g[a.x][a.y] && g[b.x][b.y]))
						continue;
					mov[i][j][k][l]=BFS(a, b)+1;
				}
			g[i][j]=1;
		}
}

inline int spfa(node s, node t) // The queue is p!
{
	if(s==t) return 0;
	if(!(g[s.x][s.y] && g[t.x][t.y])) return I;
	clear(dis, 63); clear(inq, 0);
	g[s.x][s.y]=0; static node x, y;
	for(RG int i=0;i<4;i++)
	{
		x=go(s, i);
		if(!ing(x) || !g[x.x][x.y]) continue;
		p.push((node){s.x, s.y, i}); inq[s.x][s.y][i]=true;
		dis[s.x][s.y][i]=BFS((node){ex, ey}, x);
	}
	g[s.x][s.y]=1;
#define POS(p) [p.x][p.y][p.k]
	while(!p.empty())
	{
		x=p.front(); p.pop();
		inq POS(x)=false;
		for(RG int i=0;i<4;i++)
		{
			y=go(x, i); y.k=tran(i);
			if(dis POS(x) + mov POS(x)[i] < dis POS(y))
			{
				dis POS(y) = dis POS(x) + mov POS(x)[i];
				if(!inq POS(y)) p.push(y), inq POS(y) = true;
			}
		}
	}
#undef POS(p)
	static int ans; ans=I;
	for(RG int i=0;i<4;i++) ans=min(ans, dis[t.x][t.y][i]);
	return ans;
}

int main()
{
	n=read(); m=read(); RG int q=read(), ans;
	for(RG int i=1;i<=n;i++) for(RG int j=1;j<=m;j++) g[i][j]=read();
	init();
	while(q--)
	{
		ex=read(); ey=read(); sx=read(); sy=read(); tx=read(); ty=read();
		ans=spfa((node){sx, sy}, (node){tx, ty});
		if(ans < I) printf("%d\n", ans);
		else puts("-1");
	}
	return 0;
}
