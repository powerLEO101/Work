/**************************
  * Author : Leo101
  * Problem : Luogu P3384 【模板】重链剖分
  * Tags : heavy path decomposition
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
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

int num[MAXN], label[MAXN], vLabel[MAXN], depth[MAXN], size[MAXN], hSon[MAXN], top[MAXN], Fa[MAXN];
int n, m, r, MOD, count;

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
	size[now] = 1;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (Fa[now] == to) continue;
		depth[to] = depth[now] + 1;
		Fa[to] = now;
		dfs1(to);
		size[now] += size[to];
		if (hSon[now] == -1) hSon[now] = to;
		else hSon[now] = size[hSon[now]] < size[to] ? to : hSon[now];
	}
}
void dfs2(int now, int topF) 
{
	top[now] = topF;
	label[now] = count++;
	vLabel[label[now]] = num[now];
	if (hSon[now] == -1) return ;
	dfs2(hSon[now], topF);
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == Fa[now] or to == hSon[now]) continue;
		dfs2(to, to);
	}
}

// below is seg tree

int SegTree[MAXN], lazy[MAXN];
void build(int root = 1, int l = 0, int r = n, int* value = SegTree)
{
	if (l == r - 1) {
		value[root] = vLabel[l];
		return ;
	}
	build(root * 2, l, (l + r) / 2);
	build(root * 2 + 1, (l + r) / 2, r);
	value[root] = (value[root * 2] + value[root * 2 + 1]) % MOD;
}
void pushdown(int root, int l, int r, int* value = SegTree)
{
	if (lazy[root] == 0) return ;
	int lSon = root * 2, rSon = root * 2 + 1, mid = (l + r) / 2;
	(lazy[lSon] += lazy[root]) %= MOD;
	(lazy[rSon] += lazy[root]) %= MOD;
	(value[lSon] += (lazy[root] * (mid - l)) % MOD) %= MOD;
	(value[rSon] += (lazy[root] * (r - mid)) % MOD) %= MOD;
	lazy[root] = 0;
}
void update(int qL, int qR, int addValue, int root = 1, int l = 0, int r = n, int* value = SegTree)
{
	if (l >= qR or qL >= r) return ;
	if (qL <= l and r <= qR) {
		(value[root] += ((r - l) * addValue) % MOD) %= MOD;
		(lazy[root] += addValue) %= MOD;
		pushdown(root, l, r);
		return ;
	}
	pushdown(root, l, r);
	update(qL, qR, addValue, root * 2, l, (l + r) / 2);
	update(qL, qR, addValue, root * 2 + 1, (l + r) / 2, r);
	value[root] = (value[root * 2] + value[root * 2 + 1]) % MOD;
}
int query(int qL, int qR, int root = 1, int l = 0, int r = n, int* value = SegTree)
{
	if (l >= qR or qL >= r) return 0;
	if (qL <= l and r <= qR) return value[root];
	pushdown(root, l, r);
	return (query(qL, qR, root * 2, l, (l + r) / 2) +\
	       query(qL, qR, root * 2 + 1, (l + r) / 2, r)) % MOD;
}

// above is seg tree

signed main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));
	memset(hSon, -1, sizeof(hSon));

	n = gi, m = gi, r = gi - 1, MOD = gi;
	for (int i = 0; i < n; i++) 
		num[i] = gi % MOD; // one slight but unsignificant diff
	for (int i = 1; i < n; i++) {
		int from = gi - 1, to = gi - 1;
		addEdge(from, to);
		addEdge(to, from);
	}

	Fa[r] = r;
	dfs1(r);
	dfs2(r, r);
	build();

	for (int i = 0; i < m; i++) {
		int mode = gi;
		if (mode == 1) {
			int from = gi - 1, to = gi - 1, addValue = gi % MOD;
			while (top[from] != top[to]) {
				if (depth[top[from]] < depth[top[to]]) std :: swap(from, to);
				update(label[top[from]], label[from] + 1, addValue);
				from = Fa[top[from]];
			}
			if (depth[from] < depth[to]) std :: swap(from, to);
			update(label[to], label[from] + 1, addValue);
		}
		if (mode == 2) {
			int from = gi - 1, to = gi - 1, answer = 0;
			while (top[from] != top[to]) {
				if (depth[top[from]] < depth[top[to]]) std :: swap(from, to);
				//std :: cout << from + 1 << ' ' << to + 1 << std :: endl;
				//std :: cout << top[from] + 1 << std :: endl;
				(answer += query(label[top[from]], label[from] + 1)) %= MOD;
				from = Fa[top[from]];
			}
			if (depth[from] < depth[to]) std :: swap(from, to);
			(answer += query(label[to], label[from] + 1)) %= MOD;
			printf("%lld\n", answer);
		}
		if (mode == 3) {
			int root = gi - 1, addValue = gi % MOD;
			update(label[root], label[root] + size[root], addValue);
		}
		if (mode == 4) {
			int root = gi - 1;
			//std :: cout << "!!!" << size[root] << std :: endl;
			printf("%lld\n", query(label[root], label[root] + size[root]));
		}
	}

	return 0;
}
