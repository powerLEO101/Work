#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define MOD 1000000007
#define _ 60000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

long long Lcm[_][21], Gcd[_][21], Log[_];
int Type, n, m;

long long gcd(long long x, long long y) {return y == 0 ? x : gcd(y, x % y);}

long long Get_lcm(int l, int r)
{
	if (Type == 0) return 1;
	int log = Log[r - l + 1];
	return Lcm[l][log] * Lcm[r - (1 << log) + 1][log] / gcd(Lcm[l][log], Lcm[r - (1 << log) + 1][log]);
}
long long Get_gcd(int l, int r)
{
	int log = Log[r - l + 1];
	return gcd(Gcd[l][log], Gcd[r - (1 << log) + 1][log]);
}

int main()
{
	File(gcdlcm);
	Type = gi, n = gi, m = gi;
	Log[0] = -1;
	for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for (int i = 1; i <= n; i++) Lcm[i][0] = Gcd[i][0] = gi;
	for (int j = 1; j <= 20; j++) 
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			Gcd[i][j] = gcd(Gcd[i][j - 1], Gcd[i + (1 << (j - 1))][j - 1]);
			if (Type == 0) continue;
			Lcm[i][j] = Lcm[i][j - 1] * Lcm[i + (1 << (j - 1))][j - 1] / gcd(Lcm[i][j - 1], Lcm[i + (1 << (j - 1))][j - 1]);
		}
	for (int i = 0; i < m; i++) {
		int l = gi, r = gi;
		printf("%lld\n", Get_lcm(l, r) * Get_gcd(l, r) % MOD);
	}
	return 0;
}
