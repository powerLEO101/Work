/**************************
  * Author : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 1e6 + 10;
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

int vis[MAXN];

class Edge
{
public:
	int next, to;
} edges[MAXN << 1];
int head[MAXN], edgesNum;
void addEdge(int from, int to)
{
	edges[edgesNum] = (Edge) {head[from], to}; 
	head[from] = edgesNum++;
}

class Node
{
public:
	int depth, index;
} nodes[MAXN];
bool operator< (const Node& a, const Node& b)
{
	return a.depth > b.depth;
}
int up[MAXN][20], depth[MAXN];
void dfs(int now, int dist = 0, int pre = -1)
{
	nodes[now] = (Node) {dist, now};
	depth[now] = dist;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == pre) continue;
		up[to][0] = now;
		dfs(to, dist + 1, now);
	}
}
int get(int now, int dist)
{
	for (int i = 19; i >= 0; i--) {
		if (dist - (1 << i) >= 0) {
			now = up[now][i];
			dist -= (1 << i);
		}
	}
	return now;
}

void getAns(int now, int limit, int dist, int pre = -1)
{
	if (vis[now] >= dist || depth[now] > limit) return ;
	vis[now] = dist;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == pre) continue;
		getAns(to, limit, dist - 1, now);
	}
}

int main()
{
	_FILE(coffee);

	memset(head, -1, sizeof(head));

	int n = gi, K = gi;
	for (int i = 1; i < n; i++) {
		int from = gi - 1, to = gi - 1;
		addEdge(from, to);
		addEdge(to, from);
	}

	dfs(0);
	std :: sort(nodes, nodes + n);
	for (int j = 1; j < 20; j++)
		for (int i = 0; i < n; i++)
			up[i][j] = up[up[i][j - 1]][j - 1];

	memset(vis, -1, sizeof(vis));

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[nodes[i].index] != -1) continue;
		int now = get(nodes[i].index, K);
		getAns(now, nodes[i].depth, K);
		ans++;
	}

	std :: cout << ans;

	return 0;
}
