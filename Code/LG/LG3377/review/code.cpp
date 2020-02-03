/**************************
  * Author : Leo101
  * Problem : Luogu P3377 【模板】左偏树（可并堆）
  * Tags : leftist tree
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

int fa[MAXN], used[MAXN], lSon[MAXN], rSon[MAXN], depth[MAXN];

class Data
{
public:
	int id, value;
} value[MAXN];
int operator< (const Data& a, const Data& b)
{ return a.value == b.value ? a.id < b.id : a.value < b.value; }

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

int merge(int u, int v)
{
	if (u == 0 or v == 0) return u + v;
	if (value[v] < value[u]) std :: swap(u, v);
	rSon[u] = merge(rSon[u], v);
	if (depth[lSon[u]] < depth[rSon[u]]) std :: swap(lSon[u], rSon[u]);
	depth[u] = depth[rSon[u]] + 1;
	return u;
}

int main()
{
	_FILE(code);

	depth[0] = -1;

	int n = gi, m = gi;
	for (int i = 1; i <= n; i++) {
		value[i].id = i;
		value[i].value = gi;
		fa[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int mode = gi;
		if (mode == 1) {
			int x = gi, y = gi;
			if (used[x] == true or used[y] == true) continue;
			x = find(x); y = find(y);
			if (x == y) continue;
			fa[x] = fa[y] = merge(x, y);
		} else {
			int x = gi;
			if (used[x] == true) {
				printf("-1\n");
				continue;
			}
			x = find(x);
			printf("%d\n", value[x].value);
			used[x] = true;
			fa[x] = fa[lSon[x]] = fa[rSon[x]] = merge(lSon[x], rSon[x]);
			lSon[x] = rSon[x] = depth[x] = 0;
		}
	}

	return 0;
}
