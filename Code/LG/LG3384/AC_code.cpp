#include <iostream>
#include <cstdio>

typedef long long LL;

const int MAXN = 1e5;

int n, m, r, p, tim, edge;
int dfn[MAXN | 1], son[MAXN | 1], size[MAXN | 1], depth[MAXN | 1], father[MAXN | 1], topf[MAXN | 1];
LL wp[MAXN | 1], wt[MAXN | 1];

struct Segtree {
	LL sumv, lazy;
	Segtree *ch[2];
	Segtree(void) : sumv(0), lazy(0) {
		ch[0] = ch[1] = NULL;
	}
} *root = NULL;

struct Edge {
	int to;
	Edge *nxt;
	Edge(void) {}
	Edge(Edge *x, int y) : nxt(x), to(y) {}
} e[MAXN << 1], *firstEdge[MAXN | 1];

inline int read() {
	register int x = 0;
	register char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

inline void addEdge(int x, int y) {
	e[++edge] = Edge(firstEdge[x], y);
	firstEdge[x] = &e[edge];
}

inline void pushUp(Segtree *o) {
	o -> sumv = (o -> ch[0] -> sumv + o -> ch[1] -> sumv) % p;
}

inline void pushDown(Segtree *o, int l, int r) {
	if(o -> lazy) {
		int mid = (l + r) >> 1;
		o -> ch[0] -> sumv = (o -> ch[0] -> sumv + o -> lazy * (mid - l + 1) % p) % p;
		o -> ch[1] -> sumv = (o -> ch[1] -> sumv + o -> lazy * (r - mid) % p) % p;
		o -> ch[0] -> lazy = (o -> ch[0] -> lazy + o -> lazy) % p;  
		o -> ch[1] -> lazy = (o -> ch[1] -> lazy + o -> lazy) % p;
		o -> lazy = 0;
	}
}

void build(Segtree *&o, int l, int r) {
	o = new Segtree;
	if(l == r) {
		o -> sumv = wt[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(o -> ch[0], l, mid);
	build(o -> ch[1], mid + 1, r);
	pushUp(o);
}

void modify(Segtree *o, int l, int r, int ql, int qr, LL v) {
	if(ql <= l && r <= qr) {
		o -> sumv = (o -> sumv + v * (r - l + 1) % p) % p;
		o -> lazy = (o -> lazy + v) % p;
		return;
	}
	int mid = (l + r) >> 1;
	pushDown(o, l, r);
	if(ql <= mid) modify(o -> ch[0], l, mid, ql, qr, v);
	if(mid < qr) modify(o -> ch[1], mid + 1, r, ql, qr, v);
	pushUp(o);
}

LL query(Segtree *o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return o -> sumv;
	int mid = (l + r) >> 1;
	LL res = 0;
	pushDown(o, l, r);
	if(ql <= mid) res = query(o -> ch[0], l, mid, ql, qr);
	if(mid < qr) res = (res + query(o -> ch[1], mid + 1, r, ql, qr)) % p;
	return res;
}

void dfs1(int x, int fa) {
	father[x] = fa;
	depth[x] = depth[fa] + 1;
	size[x] = 1;
	for(Edge *k = firstEdge[x]; k; k = k -> nxt) {
		int to = k -> to;
		if(to == fa) continue;
		dfs1(to, x);
		size[x] += size[to];
		if(size[to] > size[son[x]]) son[x] = to;
	}
}

void dfs2(int x, int ftop) {
	topf[x] = ftop;
	dfn[x] = ++tim;
	wt[tim] = wp[x];
	if(!son[x]) return;
	dfs2(son[x], ftop);
	for(Edge *k = firstEdge[x]; k; k = k -> nxt) {
		int to = k -> to;
		if(to != son[x] && to != father[x]) dfs2(to, to);
	}
}

inline void updateRange(int x, int y, int z) {
	while(topf[x] != topf[y]) {
		if(depth[topf[x]] < depth[topf[y]]) std::swap(x, y);
		modify(root, 1, n, dfn[topf[x]], dfn[x], z);
		x = father[topf[x]];
	}
	if(depth[x] > depth[y]) std::swap(x, y);
	modify(root, 1, n, dfn[x], dfn[y], z);
}

inline LL queryRange(int x, int y) {
	LL res = 0;
	while(topf[x] != topf[y]) {
		if(depth[topf[x]] < depth[topf[y]]) std::swap(x, y);
		res = (res + query(root, 1, n, dfn[topf[x]], dfn[x])) % p;
		x = father[topf[x]];
	}
	if(depth[x] > depth[y]) std::swap(x, y);
	return (res + query(root, 1, n, dfn[x], dfn[y])) % p;
}

inline void updateTree(int x, int y) {
	modify(root, 1, n, dfn[x], dfn[x] + size[x] - 1, y);
}

inline int queryTree(int x) {
	return query(root, 1, n, dfn[x], dfn[x] + size[x] - 1);
}

int main() {
	scanf("%d %d %d %d", &n, &m, &r, &p);
	for(int i = 1; i <= n; ++i) scanf("%lld", wp + i);
	for(int i = 1; i < n; ++i) {
		int x = read(), y = read();
		addEdge(x, y);
		addEdge(y, x);
	}
	dfs1(r, 0);
	dfs2(r, r);
	build(root, 1, n);
	while(m--) {
		int opt = read(), a, b, c;
		if(opt == 1) {
			a = read();
			b = read();
			c = read();
			updateRange(a, b, c);
		} else if(opt == 2) {
			a = read();
			b = read();
			printf("%d\n", queryRange(a, b));
		}
		else if(opt == 3) {
			a = read();
			b = read();
			updateTree(a, b);
		} else {
			a = read();
			printf("%d\n", queryTree(a));
		}
	}
	return 0;
}
