/**************************
  * Author : Leo101
  * Problem : Luogu P3372 【模板】线段树 1
  * Tags : SegmentTree
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
const int MAXN = 5e6;
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

int SegTree[MAXN], lazy[MAXN];
void pushdown(int root, int l, int r, int *value = SegTree)
{
	int lSon = root * 2, rSon = root * 2 + 1;
	lazy[lSon] += lazy[root];
	lazy[rSon] += lazy[root];
	value[lSon] += ((l + r) / 2 - l) * lazy[root];
	value[rSon] += (r - (l + r) / 2) * lazy[root];
	lazy[root] = 0;
}
void build(int root, int l, int r, int *value = SegTree)
{
	if (l + 1 == r) {
		value[root] = gi;
		return ;
	}
	build(root * 2, l, (l + r) / 2);
	build(root * 2 + 1, (l + r) / 2, r);
	value[root] = value[root * 2] + value[root * 2 + 1];
}
void update(int root, int l, int r, int qL, int qR, int addValue, int *value = SegTree)
{
	if (l >= qR or qL >= r) return ;
	if (qL <= l and r <= qR) {
		lazy[root] += addValue;
		value[root] += addValue * (r - l);
		pushdown(root, l, r);
		return ;
	}
	pushdown(root, l, r);
	update(root * 2, l, (l + r) / 2, qL, qR, addValue);
	update(root * 2 + 1, (l + r) / 2, r, qL, qR, addValue);
	value[root] = value[root * 2] + value[root * 2 + 1];
}
int query(int root, int l, int r, int qL, int qR, int *value = SegTree)
{
	//std :: cout << root << ' ' << l << ' ' << r << std :: endl;
	if (l >= qR or qL >= r) return 0;
	if (qL <= l and r <= qR) return value[root];
	pushdown(root, l, r);
	return query(root * 2, l, (l + r) / 2, qL, qR) + \
	       query(root * 2 + 1, (l + r ) / 2, r, qL, qR);
}

signed main()
{
	_FILE(code);

	int n = gi, m = gi;
	build(1, 0, n);

	for (int i = 0; i < m; i++) {
		int mod = gi;
		if (mod == 1) {
			int l = gi - 1, r = gi, k = gi;
			update(1, 0, n, l, r, k);
		} else {
			int l = gi - 1, r = gi;
			printf("%lld\n", query(1, 0, n, l, r));
		}
	}

	return 0;
}
