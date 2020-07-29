/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define int long long
const int MAXN = 1e5 + 10, MOD = 1e9 + 7, LIM = 2000 + 10;
int get_int() 
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int qPow(long long a, long long b)
{
  long long ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= MOD;
    (a *= a) %= MOD;
    b >>= 1;
  }
  return ans;
}

int frac[MAXN + 1], iFrac[MAXN + 1], A[MAXN], B[MAXN], dp[LIM * 2][LIM * 2];

int C(int n, int m)
{
  return 1LL * frac[n] * iFrac[m] % MOD * iFrac[n - m] % MOD;
}

signed main() 
{
	_FILE(code);

  int n = gi, base = LIM;
  for (int i = 0; i < n; i++) {
    A[i] = gi;
    B[i] = gi;
    dp[base - A[i]][base - B[i]]++;
  }

  frac[0] = 1;
  for (int i = 1; i <= LIM * 2; i++) frac[i] = frac[i - 1] * i % MOD;
  iFrac[LIM * 2] = qPow(frac[LIM * 2],  MOD - 2);
  for (int i = LIM * 2 - 1; i >= 0; i--) iFrac[i] = 1ll * iFrac[i + 1] * (i + 1) % MOD;
  
  for (int i = 1; i <= LIM * 2; i++)
    for (int j = 1; j <= LIM * 2; j++)
      (dp[i][j] += (dp[i - 1][j] + dp[i][j - 1])) %= MOD;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    (ans += dp[A[i] + base][B[i] + base]) %= MOD;
    ans -= C(2 * A[i] + 2 * B[i], 2 * A[i]);
    (ans += MOD) %= MOD;
  }
  std::cout << (ans * iFrac[2]) % MOD;

	return 0;
}
