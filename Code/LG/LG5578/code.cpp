Recoli Master — Spray Training/**************************
  * Author : Leo101
  * Problem : LG5578 Fiolki
  * Tags : 并查集重构树
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 4e5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int deep[MAXN], up[MAXN][21], value[MAXN], vis[MAXN], nodeNum;
std::vector<std::pair<int, int> > action[MAXN];

int fa[MAXN];
int getFa(int u)
{ return fa[u] == u ? u : fa[u] = getFa(fa[u]); }

class Edge
{
public:
	int next, to;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to)
{
	edges[eNum] = (Edge) {head[from], to};
	head[from] = eNum++;
}

void dfs(int now)
{
	vis[now] = true;
	for (int i = 1; i <= 20; i++)
		up[now][i] = up[up[now][i - 1]][i - 1];
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		deep[to] = deep[now] + 1;
		up[to][0] = now;
		dfs(to);
	}
}
void jump(int &u, int &v)
{
	if (deep[u] < deep[v]) std::swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (deep[up[u][i]] > deep[v])
			u = up[u][i];
	if (deep[u] != deep[v]) u = up[u][0];
}
int LCA(int u, int v)
{
	jump(u, v);
	for (int i = 20; i >= 0; i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	if (u == v) return u;
	return up[u][0];
}

signed main()
{
	_FILE(code);
	memset(head, -1, sizeof(head));

	int n = gi, m = gi, k = gi;
	long long ans = 0;
	nodeNum = n;
	for (int i = 0; i < n; i++) fa[i] = i;
	for (int i = 0; i < n; i++) value[i] = gi;
	for (int i = 0; i < m; i++) {
		int a = getFa(gi - 1);
		int b = getFa(gi - 1);
		fa[a] = fa[b] = fa[nodeNum] = nodeNum;
		addEdge(nodeNum, a);
		addEdge(nodeNum++, b);
	}
	int count = 0;
	for (int i = 0; i < nodeNum; i++) {
		int tmp = getFa(i);
		if (vis[tmp] == false) {
			up[tmp][0] = tmp;
			dfs(tmp);
			count++;
		}
	}
	for (int i = 0; i < k; i++) {
		int c = gi - 1, d = gi - 1;
		if (getFa(c) == getFa(d)) {
			int lca = LCA(c, d);
			action[lca].push_back(std::make_pair(c, d));
		}
	}
	for (int i = n; i < nodeNum; i++) {
		for (int j = 0; j < action[i].size(); j++) {
			int x = action[i][j].first, y = action[i][j].second;
			int min = std::min(value[x], value[y]);
			value[x] -= min; value[y] -= min;
			ans += min * 2;
		}
	}
	std::cout << ans;

	return 0;
}
