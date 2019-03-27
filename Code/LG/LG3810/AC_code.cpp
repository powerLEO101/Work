#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
#define int LL

const int MAXN = 1e5;
const int MAXM = 2e5;

struct Num {
	int a, b, c, res, size;
	Num() : res(0), size(0) {}
	Num(int _a, int _b, int _c, int _size) : a(_a), b(_b), c(_c), size(_size) {}
	friend bool operator < (const Num &lhs, const Num &rhs) {
		return lhs.a < rhs.a || (lhs.a == rhs.a && lhs.b < rhs.b) || (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c < rhs.c);
	}
} p[MAXN | 1], a[MAXN | 1], tmp[MAXN | 1];

int n, m, tot;
int ans[MAXN | 1], bit[MAXM | 1];

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

inline void modify(int x, int y) {
	for (x; x <= m; x += x & (-x)) bit[x] += y;
}

inline int query(int x) {
	int res = 0;
	for (x; x; x -= x & (-x)) res += bit[x];
	return res;
}

void CDQ(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ(l, mid);
	CDQ(mid + 1, r);
	int p = l, q = mid + 1, cnt = 0;
	while (p <= mid && q <= r) {
		if (a[p].b <= a[q].b) {
			modify(a[p].c, a[p].size);
			tmp[++cnt] = a[p++];
		} else {
			a[q].res += query(a[q].c);
			tmp[++cnt] = a[q++];
		}
	}
	while (q <= r) {
		a[q].res += query(a[q].c);
		tmp[++cnt] = a[q++];
	}
	for (int i = l; i < p; ++i) modify(a[i].c, -a[i].size);
	// memset(bit, 0, sizeof(bit));
	while (p <= mid) {
		tmp[++cnt] = a[p++];
	}
	for (int i = 1; i <= cnt; ++i) a[l + i - 1] = tmp[i];
	/*
	   while (q <= r) {
	   while (a[p].b <= a[q].b && p <= mid) {
	   modify(a[p].c, a[p].size);
	   tmp[++cnt] = a[p++];
	   }
	   a[q].res += query(a[q].c);
	   tmp[++cnt] = a[q++];
	   }
	   for (int i = 1; i <= cnt; ++i) a[l + i - 1] = tmp[i];
	   memset(bit, 0, sizeof(bit));
	 */
}

signed main() {
	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; ++i) {
		p[i].a = read();
		p[i].b = read();
		p[i].c = read();
	}
	std::sort(p + 1, p + 1 + n);
	for (int i = 1, size = 1; i <= n; ++i) {
		if (p[i].a != p[i + 1].a || p[i].b != p[i + 1].b || p[i].c != p[i + 1].c) {
			a[++tot] = Num(p[i].a, p[i].b, p[i].c, size);
			size = 1;
		} else ++size;
	}
	CDQ(1, tot);
	for (int i = 1; i <= tot; ++i) ans[a[i].res + a[i].size - 1] += a[i].size;
	for (int i = 0; i < n; ++i) printf("%lld\n", ans[i]);
	return 0;
}
