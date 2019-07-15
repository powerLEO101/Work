#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MOD = 1000000001, LIMIT = 30;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-')
		y = -1, ch = getchar(); 
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int status[LIMIT], dp[LIMIT][5000], N;

long long getAns(int x)
{
	int n = 0, m = 0, ret = 0;
	for (int i = x; i <= N; i *= 2) n++;
	for (int i = x; i <= N; i *= 3) m++;
	for (int i = 1, a = x; i <= n; i++, a *= 2) {
		status[i] = 1;
		for (int j = 2, b = a; j <= m; j++) {
			if (3ll * b > N) status[i] = status[i] << 1;
			else {
				status[i] = status[i] << 1 | 1;
				b *= 3;
			}
		}
	}
	int max = 1 << m;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < max; j++) {
			if (((j & (j >> 1)) != 0) || (j | status[i]) != status[i])
				continue;
			if (i == 1) {
				dp[1][j] = 1;
				if (n == 1) ret++;
				continue;
			}
			for (int k = 0; k < max; k++) {
				if ((j & k) != 0) continue;
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
			if (i == n) ret = (ret + dp[i][j]) % MOD;
		}
	}
	return ret;
}

int main()
{
	_FILE(code);

	long long ans = 1;
	N = gi;

	for (int i = 1; i <= N; i++) {
		if ((i % 2) == 0 || (i % 3) == 0) 
			continue;
		(ans *= getAns(i)) %= MOD;
	}

	std :: cout << ans;

	return 0;
}
