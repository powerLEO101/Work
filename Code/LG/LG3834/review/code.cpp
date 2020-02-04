/**************************
  * Author : Leo101
  * Problem : Luogu P3834 【模板】可持久化线段树 1（主席树）
  * Tags : persistent segment tree
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
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

int num[MAXN], n;
int SegTree[MAXN], tree[MAXN], lSon[MAXN], rSon[MAXN], count = 2;

void build(int root = 1, int l = 0, int r = n, int *value = SegTree)
{
	if (l == r - 1) return ;
	lSon[root] = count++;
	rSon[root] = count++;
	build(lSon[root], l, (l + r) / 2);
	build(rSon[root], (l + r) / 2, r);
}
int update(int pos, int root, int l = 0, int r = n, int *value = SegTree)
{
	int now = count++;
	if (l == r - 1) {
		value[now] = value[root] + 1;
		return now;
	}
	if (pos < (l + r) / 2) {
		lSon[now] = update(pos, lSon[root], l, (l + r) / 2);
		rSon[now] = rSon[root];
	} else {
		lSon[now] = lSon[root];
		rSon[now] = update(pos, rSon[root], (l + r) / 2, r);
	}
	value[now] = value[lSon[now]] + value[rSon[now]];
	return now;
}
int query(int rootL, int rootR, int k, int l = 0, int r = n, int *value = SegTree)
{
	if (l == r - 1) return l;
	if ((value[lSon[rootR]] - value[lSon[rootL]]) >= k) 
		return query(lSon[rootL], lSon[rootR], k, l, (l + r) / 2);
	else 
		return query(rSon[rootL], rSon[rootR], k - value[lSon[rootR]] + value[lSon[rootL]], (l + r) / 2, r);
}

class Data
{
public:
	int id, value;
} tmp[MAXN];
int cmp1(const Data& a, const Data& b)
{ return a.value < b.value; }
int cmp2(const Data& a, const Data& b)
{ return a.id < b.id; }

int main()
{
	_FILE(code);

	n = gi;
	int m = gi;

	build();

	for (int i = 0; i < n; i++) {
		tmp[i].value = gi;
		tmp[i].id = i;
	}
	std :: sort(tmp, tmp + n, cmp1);
	int val = 0;
	tree[0] = 1;
	for (int i = 0; i < n; i++) {
		val += i == 0 ? 0 : tmp[i - 1].value != tmp[i].value;
		num[val] = tmp[i].value;
		tmp[i].value = val;
	}
	std :: sort(tmp, tmp + n, cmp2);
	for (int i = 0; i < n; i++) {
		tree[i + 1] = update(tmp[i].value, tree[i]);
	}

	while (m--) {
		int l = gi, r = gi, k = gi;
		printf("%d\n", num[query(tree[l - 1], tree[r], k)]);
	}

	return 0;
}
