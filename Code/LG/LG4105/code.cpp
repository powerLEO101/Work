/**************************
  * Author : Leo101
  * Problem : Luogu P4105 [HEOI2014]南园满地堆轻絮
  * Tags : 贪心
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()

typedef __int128 LL;
#define int LL

int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, sA, sB, sC, sD, num[5100000], MOD;

int function(int u)
{ return (((((1ll * u * u) % MOD) * u) * sA) % MOD + (((1ll * u * u) % MOD) * sB) % MOD + 1ll * u * sC + sD) % MOD; }

void out(int x) {
	if (!x) return;
	out (x / 10);
	putchar(x % 10 + '0');
}

signed main()
{
	_FILE(code);

	n = gi, sA = gi, sB = gi, sC = gi, sD = gi;
	num[1] = gi;
	MOD = gi;
	for (int i = 2; i <= n; i++)
		num[i] = (1ll * function(num[i - 1]) + function(num[i - 2])) % MOD;

	int lastMax = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = std :: max(ans, lastMax - num[i]);
		lastMax = std :: max(lastMax, num[i]);
	}

	// printf("%lld", (ans + 1) / 2);
	out((ans + 1) / 2);

	return 0;
}
