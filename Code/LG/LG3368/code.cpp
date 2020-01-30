/**************************
  * Author : Leo101
  * Problem : Luogu P3368 【模板】树状数组 2
  * Tags : fenwick tree
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

int fenwick[MAXN], num[MAXN], n;
int lowbit(int x) { return x & (-x); }
void add(int pos, int addValue)
{
	while (pos <= n) {
		fenwick[pos] += addValue;
		pos += lowbit(pos);
	}
}
int query(int pos)
{
	int answer = 0;
	while (pos >= 1) {
		answer += fenwick[pos];
		pos -= lowbit(pos);
	}
	return answer;
}

int main()
{
	_FILE(code);

	n = gi;
	int m = gi;
	for (int i = 1; i <= n; i++) num[i] = gi;
	for (int i = 1; i <= n; i++)
		add(i, num[i] - num[i - 1]);
	for (int i = 0; i < m; i++) {
		int mode = gi;
		if (mode == 1) {
			int l = gi, r = gi, k = gi;
			add(l, k); add(r + 1, -k);
		} else {
			int x = gi;
			printf("%d\n", query(x));
		}
	}

	return 0;
}
