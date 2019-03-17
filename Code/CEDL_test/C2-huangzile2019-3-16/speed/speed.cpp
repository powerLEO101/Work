/**************************
  * Writer : Leo101
  * Problem : Test2019-3-16T2 speed
  * Tags : LCA，贪心，基环树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 1e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int ABS(int u)
{ return u < 0 ? -u : u; }

class edge
{
public:
	int next, to, value;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to, int value)
{
	edges[eNum] = (edge) {head[from], to, value};
	head[from] = eNum++;
}

int father[MAXN];
int getFather(int u) { return father[u] == u ? u : father[u] = getFather(father[u]); }

int depth[MAXN], up[MAXN][21], pos[MAXN], tail[MAXN];
bool vis[MAXN];

void dfs(int now, int pre = -1)
{
	if (vis[now] == true) return ;
	vis[now] = true;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (value == 1) continue;
		up[to][0] = now; depth[to] = depth[now] + 1;
		dfs(to, now);
	}
}
void move(int &u, int &v)
{
	if (depth[u] < depth[v]) std :: swap(u, v);
	for (int i = 20; i >= 0; i--) 
		if (depth[up[u][i]] >= depth[v]) u = up[u][i];
}
int getLCA(int u, int v)
{
	move(u, v);
	for (int i = 20; i >= 0; i--)
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	return u == v ? u : up[u][0];
}
int getDist(int u, int v)
{ return ABS(depth[u] - depth[v]); }

void getRing(int now, int target)
{
	int cnt = 0;
	pos[now] = cnt++;
	tail[now] = target;
	while (now != target) {
		int to = edges[head[now]].to;
		now = to;
		pos[now] = cnt++;
		tail[now] = target;
	}
}

int getRingNode(int &now)
{
	int nowBackup = now;
	for (int i = 20; i >= 0; i--) {
		if (pos[up[now][i]] == -1) {
			now = up[now][i];
		}
	}
	now = pos[now] == -1 ? up[now][0] : now;
	return depth[nowBackup] - depth[now];
}
int getDistOnRing(int from, int to)
{
	if (depth[from] > depth[to]) return depth[from] - depth[to];
	return pos[from] + (depth[tail[from]] - depth[to]);
}

void updateAns(int &ansx, int &ansy, int x, int y)
{
	int min = std :: min(x, y), max = std :: max(x, y);
	int ansMin = std :: min(ansx, ansy), ansMax = std :: max(ansx, ansy);
	if (max >= ansMax) return ;
	if (min >= ansMin) return ;
	if (x < y) return ;
	ansx = x; ansy = y;
}
int main()
{
	_FILE(speed);

	memset(head, -1, sizeof(head));
	memset(pos, -1, sizeof(pos));

	int n = gi, m = gi;
	for (int i = 0; i < n; i++) father[i] = i;
	for (int i = 0; i < n; i++) {
		int from = i, to = gi - 1;
		int fatherFrom = getFather(from), fatherTo = getFather(to);
		if (fatherFrom != fatherTo) {
			addEdge(to, from, 0);
			father[fatherFrom] = fatherTo;
		} else {
			addEdge(from, to, 1);
			getRing(from, to);
		}
	}

	for (int i = 0; i < n; i++) {
		if (vis[i] == true) continue;
		int root = getFather(i);
		up[root][0] = root;
		dfs(root);
	}
	for (int j = 1; j < 21; j++)
		for (int i = 0; i < n; i++)
			up[i][j] = up[up[i][j - 1]][j - 1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 21; j++)
			printf("%d ", up[i][j]);
		printf("\n");
	}

	while (m--) {
		int from = gi - 1, to = gi - 1;
		int fatherFrom = getFather(from), fatherTo = getFather(to);
		if (fatherFrom != fatherTo) {
			printf("-1 -1\n");
			continue;
		}
		if (from == to) {
			printf("0 0\n");
			continue;
		}
		int lca = getLCA(from, to);
		int x = getDist(from, lca), y = getDist(to, lca);
		int cost1 = getRingNode(from), cost2 = getRingNode(to);
		int dist1 = getDistOnRing(from, to), dist2 = getDistOnRing(to, from);
		updateAns(x, y, cost1, cost2 + dist2);
		updateAns(x, y, cost1 + dist1, cost2);
		printf("%d %d\n", x, y);
	}
	
	return 0;
}
