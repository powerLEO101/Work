/**************************
  * Author : Leo101
  * Problem :
  * Tags :
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

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		int n = gi, l = gi, r = gi;
		int nowL = 1, nowR = 1, count = n - 2;
		for (int i = 1; i <= n; i++) {
			nowL = nowR;
			nowR += 2 * count + 1;
			if (nowL <= l && l < nowR) {
				int tmp = (l - nowL) / 2 + 1;
			}
		}
	}

	return 0;
}

