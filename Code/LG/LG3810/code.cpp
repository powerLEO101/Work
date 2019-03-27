/**************************
  * Writer : Leo101
  * Problem : Luogu P3810 【模板】三维偏序（陌上花开）
  * Tags : CDQ
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)

typedef long long LL;
#define int LL

const int MAXN = 2e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int tot, n, m;
int bit[MAXN], ans[MAXN];

class Data
{
public:
	int a, b, c, val, size;
} num[MAXN], tmp[MAXN], p[MAXN];
bool operator< (const Data &a, const Data& b)
{
	if (a.a < b.a) return true;
	if (a.a == b.a && a.b < b.b) return true;
	if (a.a == b.a && a.b == b.b && a.c < b.c) return true;
	return false;
}

void modify(int index, int val)
{
	for (; index <= m; index = index + (index & (-index)))
		bit[index] += val;
}
int query(int index)
{
	int ret = 0;
	for(; index > 0; index = index - (index & (-index)))
		ret += bit[index];
	return ret;
}

void CDQ(int l, int r)
{
	if (l == r - 1) return ;
	int mid = (l + r) / 2;
	CDQ(l, mid); CDQ(mid, r);
	int p1 = l, p2 = mid, cnt = 0;
	while (p1 < mid && p2 < r) {
		if (num[p1].b <= num[p2].b) {
			modify(num[p1].c, num[p1].size);
			tmp[cnt++] = num[p1++];
		} else {
			num[p2].val += query(num[p2].c);
			tmp[cnt++] = num[p2++];
		}
	}
	while (p2 < r) {
		num[p2].val += query(num[p2].c);
		tmp[cnt++] = num[p2++];
	}
	for (int i = l; i < p1; i++) 
		modify(num[i].c, -num[i].size);
	while (p1 < mid)
		tmp[cnt++] = num[p1++];
	for (int i = 0; i < cnt; i++)
		num[i + l] = tmp[i];
}

signed main()
{
	_FILE(code);

	n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		p[i].a = gi;
		p[i].b = gi;
		p[i].c = gi;
	}

	std :: sort(p, p + n);
	int len = 1;
	for (int i = 0; i < n; i++) {
		if (p[i].a == p[i + 1].a && p[i].b == p[i + 1].b && p[i].c == p[i + 1].c) {
			len++;
		} else {
			num[tot++] = (Data) {p[i].a, p[i].b, p[i].c, 0, len};
			len = 1;
		}
	}

	CDQ(0, tot);
	for (int i = 0; i < tot; i++) ans[num[i].val + num[i].size - 1] += num[i].size;
	for (int i = 0; i < n; i++) 
		printf("%lld\n", ans[i]);

	return 0;
}
