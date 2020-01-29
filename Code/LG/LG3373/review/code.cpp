/**************************
  * Author : Leo101
  * Problem : Luogu P3373 【模板】线段树 2
  * Tags : SegTree
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define int long long
const int MAXN = 1000000;
int MOD = 571373;
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
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

int SegTree[MAXN], lazyP[MAXN], lazyM[MAXN];
void build(int root, int l, int r, int* value = SegTree)
{
	lazyM[root] = 1;
	if (l == r - 1) {
		value[root] = gi;
		return ;
	}
	build(root * 2, l, (l + r) / 2);
	build(root * 2 + 1, (l + r) / 2, r);
	value[root] = (value[root * 2] + value[root * 2 + 1]) % MOD;
}
void pushdown(int root, int l, int r, int* value = SegTree)
{
	int lSon = root * 2, rSon = root * 2 + 1, mid = (l + r) / 2;
	if (lazyM[root] != 1) {
		(lazyM[rSon] *= lazyM[root]) %= MOD;
		(lazyM[lSon] *= lazyM[root]) %= MOD;
		(lazyP[lSon] *= lazyM[root]) %= MOD;
		(lazyP[rSon] *= lazyM[root]) %= MOD;
		(value[lSon] *= lazyM[root]) %= MOD;
		(value[rSon] *= lazyM[root]) %= MOD;
		lazyM[root] = 1;
	}
	if (lazyP[root] != 0) {
		(lazyP[lSon] += lazyP[root]) %= MOD;
		(lazyP[rSon] += lazyP[root]) %= MOD;
		(value[lSon] += (mid - l) * lazyP[root]) %= MOD;
		(value[rSon] += (r - mid) * lazyP[root]) %= MOD;
		lazyP[root] = 0;
	}
}
void updateP(int root, int l, int r, int qL, int qR, int addValue, int* value = SegTree)
{
	if (l >= qR or qL >= r) return ;
	if (qL <= l and r <= qR) {
		(value[root] += (r - l) * addValue) %= MOD;
		(lazyP[root] += addValue) %= MOD;
		pushdown(root, l, r);
		// the necessity of pushdown?
		return ;
	}
	pushdown(root, l, r);
	// the necessity of pushdown?
	updateP(root * 2, l, (l + r) / 2, qL, qR, addValue);
	updateP(root * 2 + 1, (l + r) / 2, r, qL, qR, addValue);
	value[root] = (value[root * 2] + value[root * 2 + 1]) % MOD;
}
void updateM(int root, int l, int r, int qL, int qR, int multiplyValue, int* value = SegTree)
{
	if (l >= qR or qL >= r) return;
	if (qL <= l and r <= qR) {
		(value[root] *= multiplyValue) %= MOD;
		(lazyM[root] *= multiplyValue) %= MOD;
		(lazyP[root] *= multiplyValue) %= MOD;
		return ;
	}
	// the necessity of pushdown
	pushdown(root, l, r);
	updateM(root * 2, l, (l + r) / 2, qL, qR, multiplyValue);
	updateM(root * 2 + 1, (l + r) / 2, r, qL, qR, multiplyValue);
	value[root] = (value[root * 2] + value[root * 2 + 1]) % MOD; // pushup action is one of the factors of pushdown
}
int query(int root, int l, int r, int qL, int qR, int* value = SegTree)
{
	if (l >= qR or qL >= r) return 0;
	if (qL <= l and r <= qR) return value[root];
	pushdown(root, l, r);
	return (query(root * 2, l, (l + r) / 2, qL, qR) + \
	       query(root * 2 + 1, (l + r) / 2, r, qL, qR)) % MOD;
}

signed main()
{
	_FILE(code);

	int n = gi, m = gi;
	MOD = gi;
	build(1, 0, n);
	for (int i = 0; i < m; i++) {
		int mode = gi;
		if (mode == 1) {
			int l = gi - 1, r = gi, multiplyValue = gi % MOD;
			updateM(1, 0, n, l, r, multiplyValue);
		}
		if (mode == 2) {
			int l = gi - 1, r = gi, addValue = gi % MOD;
			updateP(1, 0, n, l, r, addValue);
		}
		if (mode == 3) {
			int l = gi - 1, r = gi;
			printf("%lld\n", query(1, 0, n, l, r));
		}
	}

	return 0;
}
