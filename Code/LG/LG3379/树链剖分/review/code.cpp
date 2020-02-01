/**************************
  * Author : Leo101
  * Problem : Luogu P3379 【模板】最近公共祖先（LCA）
  * Tags : LCA, heavy path decomposition
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 2e6;
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

int size[MAXN], hSon[MAXN], father[MAXN], depth[MAXN], top[MAXN];

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

void dfs1(int now)
{
	hSon[now] = -1;
	size[now] = 1;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == father[now]) continue;
		father[to] = now;
		depth[to] = depth[now] + 1;
		dfs1(to);
		size[now] += size[to];
		if (hSon[now] == -1) hSon[now] = to;
		else hSon[now] = size[hSon[now]] < size[to] ? to : hSon[now];
	}
}
void dfs2(int now, int pre)
{
	top[now] = pre;
	if (hSon[now] == -1) return ;
	dfs2(hSon[now], pre);
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == father[now] or to == hSon[now]) continue;
		dfs2(to, to);
	}
}

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));

	int n = gi, m = gi, s = gi;
	for (int i = 1; i < n; i++) {
		int from = gi, to = gi;
		addEdge(from, to);
		addEdge(to, from);
	}
	
	father[s] = s;
	dfs1(s);
	dfs2(s, s);

	while (m--) {
		int u = gi, v = gi;
		while (top[u] != top[v]) {
			if (depth[top[u]] < depth[top[v]]) std :: swap(u, v);
			u = father[top[u]];
		}
		if (depth[u] < depth[v]) printf("%d\n", u);
		else printf("%d\n", v);
	}

	return 0;
}
