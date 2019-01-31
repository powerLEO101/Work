#include <iostream>
#include <cstdio>
#include <algorithm>

const int MAXN = 2e5;

int n, m;
int p[MAXN | 1];

struct Num {
	int num, o, v;
} a[MAXN | 1];

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

bool comp1(Num a, Num b) {
	return a.num < b.num;
}

bool comp2(Num a, Num b) {
	return a.o < b.o;
}

namespace persistentSegmentTree {
	struct Segtree {
		int sumv;
		Segtree *ch[2];
		Segtree() {
			sumv = 0;
			ch[0] = ch[1] = NULL;
		}
	} *root[MAXN | 1];
	void build(Segtree *&o, int l, int r) {
		o = new Segtree;
		if(l == r) return;
		int mid = (l + r) >> 1;
		build(o -> ch[0], l, mid);
		build(o -> ch[1], mid + 1, r);
	}
	void insert(Segtree *&now, Segtree *lst, int l, int r, int pos) {
		now = new Segtree;
		if(l == r) {
			++(now -> sumv);
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) {
			now -> ch[1] = lst -> ch[1];
			insert(now -> ch[0], lst -> ch[0], l, mid, pos);
		} else {
			now -> ch[0] = lst -> ch[0];
			insert(now -> ch[1], lst -> ch[1], mid + 1, r, pos);
		}
		now -> sumv = now -> ch[0] -> sumv + now -> ch[1] -> sumv;
	}
	int query(Segtree *lst, Segtree *now, int k, int l, int r) {
		if(l == r) return l;
		int delta = now -> ch[0] -> sumv - lst -> ch[0] -> sumv;
		int mid = (l + r) >> 1;
		if(delta < k) return query(lst -> ch[1], now -> ch[1], k - delta, mid + 1, r);
		else return query(lst -> ch[0], now -> ch[0], k, l, mid);
	}
}

using namespace persistentSegmentTree;

int main() {
	freopen("code.in", "r", stdin);
	freopen("AC_code.out", "w", stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; ++i) {
		a[i].o = i;
		a[i].num = read();
	}
	std::sort(a + 1, a + 1 + n, comp1);
	for(int i = 1; i <= n; ++i) {
		a[i].v = i;
		p[i] = a[i].num;
	}
	std::sort(a + 1, a + 1 + n, comp2);
	build(root[0], 1, n);
	for(int i = 1; i <= n; ++i) insert(root[i], root[i - 1], 1, n, a[i].v);
	while(m--) {
		int a = read(), b = read(), c = read();
		printf("%d\n", p[query(root[a - 1], root[b], c, 1, n)]);
	}
	return 0;
}
