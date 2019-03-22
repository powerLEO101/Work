#include <iostream>
#include <cstdio>
#include <cmath>

typedef long long LL;

const int MAXN = 2e5;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL ans = INF;
int n, m, A, B, bug, test;
int w[MAXN | 1];

inline int read() {
	register int x = 0;
	register char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

namespace segmentTree {
	struct Node {
		LL minv, addv;
		Node *ch[2];
		Node() : minv(0), addv(0) {
			ch[0] = ch[1] = NULL;
		}
	} *root[2];
	inline void pushdown(Node *o, int l, int r, int de) {
		if (o -> addv) {
			o -> ch[0] -> minv += o -> addv;
			o -> ch[1] -> minv += o -> addv;
			o -> ch[0] -> addv += o -> addv;
			o -> ch[1] -> addv += o -> addv;
			o -> addv = 0;
		}
	}
	inline void pushup(Node *o) {
		o -> minv = std::min(o -> ch[0] -> minv , o -> ch[1] -> minv);
	}
	void build(Node *&o, int l, int r) {
		o = new Node;
		if (l == r) {
			o -> minv = INF;
			return;
		}
		int mid = (l + r) >> 1;
		build(o -> ch[0], l, mid);
		build(o -> ch[1], mid + 1, r);
		pushup(o);
	}
	void update(Node *o, int l, int r, int ql, int qr, int v) {
		if (ql <= l && r <= qr) {
			o -> minv += v;
			o -> addv += v;
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(o, l, r, 1);
		if (ql <= mid) update(o -> ch[0], l, mid, ql, qr, v);
		if (mid < qr) update(o -> ch[1], mid + 1, r, ql, qr, v);
		pushup(o);
	}
	void modify(Node *o, int l, int r, int pos, LL v) {
		if (l == r) {
			o -> minv = v;
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(o, l, r, 2);
		if (pos <= mid) modify(o -> ch[0], l, mid, pos, v);
		else modify(o -> ch[1], mid + 1, r, pos, v);
		pushup(o);
	}
	LL query(Node *o, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return o -> minv;
		int mid = (l + r) >> 1;
		LL res = 0x3f3f3f3f3f3f3f3f;
		pushdown(o, l, r, 3);
		if (ql <= mid) res = query(o -> ch[0], l, mid, ql, qr);
		if (mid < qr) res = std::min(res, query(o -> ch[1], mid + 1, r, ql, qr));
		return res;
	}
}

using namespace segmentTree;

int main() {
	freopen("code.in", "r", stdin);
	freopen("AC_code.out", "w", stdout);
	n = read();
	m = read();
	A = read();
	B = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	build(root[0], 1, n);
	build(root[1], 1, n);
	modify(root[1], 1, n, A, std::abs(w[1] - B) + A);
	modify(root[1], 1, n, B, std::abs(w[1] - A) + B);
	modify(root[0], 1, n, B, std::abs(w[1] - A) - B);
	modify(root[0], 1, n, A, std::abs(w[1] - B) - A);
	for (int i = 2; i <= m; ++i) {
		int foo = std::abs(w[i] - w[i - 1]);
		LL res = query(root[0], 1, n, 1, w[i]) + w[i];
		if (w[i] != n) res = std::min(res, query(root[1], 1, n, w[i] + 1, n) - w[i]);
		modify(root[0], 1, n, w[i - 1], res - w[i - 1]);
		modify(root[1], 1, n, w[i - 1], res + w[i - 1]);
		update(root[0], 1, n, 1, n, foo);	
		update(root[1], 1, n, 1, n, foo);
		update(root[0], 1, n, w[i - 1], w[i - 1], -foo);
		update(root[1], 1, n, w[i - 1], w[i - 1], -foo);
	}
	for (int i = 1; i <= n; ++i) ans = std::min(ans, query(root[0], 1, n, i, i) + i);
	printf("%lld", ans);
	return 0;
}
