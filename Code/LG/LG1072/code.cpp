/**************************
  * Author : Leo101
  * Problem : Luogu P1072 Hankson 的趣味题
  * Tags : 数论
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		int a0 = gi, a1 = gi, b0 = gi, b1 = gi, ans = 0;
		for (int x = 1; x * x <= b1; x++) {
			if (b1 % x != 0) continue;
			if (x % a1 == 0 && gcd(b1 / x, b1 / b0) == 1 && gcd(a0 / a1, x / a1) == 1)
				ans++;
			if (b1 / x == x) continue;
			x = b1 / x;
			if (x % a1 == 0 && gcd(b1 / x, b1 / b0) == 1 && gcd(a0 / a1, x / a1) == 1)
				ans++;
			x = b1 / x;
		}
		printf("%d\n", ans);
	}

	return 0;
}
