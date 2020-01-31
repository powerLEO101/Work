/**************************
  * Author : Leo101
  * Problem : Luogu P3379 【模板】最近公共祖先（LCA）
  * Tags : LCA, doubling
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

int n, m, s;

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

int up[MAXN][21], deep[MAXN];
void dfs(int now)
{
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == up[now][0]) continue;
		up[to][0] = now;
		deep[to] = deep[now] + 1;
		dfs(to);
	}
}
void move(int& u, int& v)
{
	if (deep[u] < deep[v]) std :: swap(u, v);
	for (int i = 20; i >= 0; i--) {
		if (deep[up[u][i]] < deep[v]) continue;
		u = up[u][i];
	}
}
int LCA(int u, int v)
{
	move(u, v);
	// printf("%d %d\n", u, v);
	// printf("!!!%d %d\n", deep[u], deep[v]);
	for (int i = 20; i >= 0; i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	if (u != v) return up[u][0];
	return u;
}

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));

	n = gi, m = gi, s = gi - 1;

	for (int i = 1; i < n; i++) {
		int from = gi - 1, to = gi - 1;
		addEdge(from, to);
		addEdge(to, from);
	}

	up[s][0] = s;
	dfs(s);
	for (int j = 1; j <= 20; j++)
		for (int i = 0; i < n; i++)
			up[i][j] = up[up[i][j - 1]][j - 1];
	
	while (m--) {
		int l = gi - 1, r = gi - 1;
		printf("%d\n", LCA(l, r) + 1);
	}

	return 0;
}
