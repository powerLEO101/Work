/**************************
  * Author : Zile Huang
  * Problem : 20191215Problem 1. Cow Gymnastics
  * Tags : 模拟
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
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

int n, m, rank[100][100];

int check(int x, int y)
{
	for (int i = 0; i < n; i++) {
		if (rank[i][x] <= rank[i][y])
			return 0;
	}
	return 1;
}

int main()
{
	_FILE(gymnastics);

	n = gi, m = gi;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rank[i][gi - 1] = j;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			ans += check(i, j);
		}
	}

	std :: cout << ans;

	return 0;
}
