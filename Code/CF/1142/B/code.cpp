/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 3e5;
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

int n, m, q;
int tmp[MAXN], st[MAXN][25], p[MAXN], num[MAXN], myindex[MAXN], last[MAXN];

int get(int myindex)
{
	int now = 0;
	for (int i = 23; i >= 0; i--) {
		if ((now + (1 << i)) < n) {
			myindex = st[myindex][i];
			now += 1 << i;
		}
	}
	if (now != (n - 1)) return -1;
	return myindex;
}

int main()
{
	_FILE(code);

	n = gi, m = gi, q = gi;
	for (int i = 1; i <= n; i++) {
		p[i] = gi;
		myindex[p[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		num[i] = gi;
		if (myindex[num[i]] == 1) {
			st[i][0] = last[p[n]];
		} else {
			st[i][0] = last[p[myindex[num[i]] - 1]];
		}
		last[num[i]] = i;
	}
	for (int j = 1; j <= 23; j++)
		for (int i = 1; i <= m; i++)
			st[i][j] = st[st[i][j - 1]][j - 1];
	for (int i = 1; i <= m; i++)
		tmp[i] = get(i);
	for (int i = 1; i <= m; i++)
		st[i][0] = tmp[i];
	for (int j = 1; j <= (int)log2(m); j++)
		for (int i = 1; i <= m - (1 << j) + 1; i++)
			st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= (int)log2(m); j++)
			std::cout << st[i][j] << ' ';
		std::cout << std::endl;
	}
	*/
	while (q--) {
		int l = gi, r = gi;
		int fuck = (int)log2(r - l + 1);
		fuck = std::max(st[l][fuck], st[r - (1 << fuck) + 1][fuck]);
		if (fuck >= l) {
			std::cout << 1;
		} else {
			std::cout << 0;
		}
	}

	return 0;
}
