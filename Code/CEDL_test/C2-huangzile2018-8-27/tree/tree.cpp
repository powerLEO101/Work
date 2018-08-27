#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define MOD 998244353
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

long long ksm(long long x, long long y)
{
	long long Ans = 1, a = x;
	while (y != 0) {
		if (y & 1 == 1)
			Ans = (Ans * a) % MOD;
		a = (a * a) % MOD;
		y >>= 1;
	}
	return Ans;
}

int main()
{
	File(tree);
	long long n = 1ll * gi, m = 1ll * gi;
	long long Ans = ((m * ksm(m, n - 2)) % MOD) + \
			((((m * (m - 1)) % MOD) * ksm(m, n - 2)) % MOD) - \
			((m * ksm(m - 1, n - 1)) % MOD);
	Ans %= MOD;
	std::cout<<Ans;
	return 0;
}
