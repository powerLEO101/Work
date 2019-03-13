/**************************
  * Writer : Leo101
  * Problem : Luogu P2979 [USACO10JAN]奶酪塔Cheese Towers
  * Tags : Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 3000;
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

int dp[MAXN], v[MAXN], h[MAXN];

int main()
{
	_FILE(code);

	int n = gi, t = gi, k = gi;
	for (int i = 1; i <= n; i++) 
		h[i] = gi, v[i] = gi;

	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= t * 5 / 4; j++)
			dp[j] = std :: max(dp[j], dp[j - v[i]] + h[i]);
	int ans = dp[t];
	for (int i = 1; i <= n; i++) {
		if (v[i] < k) continue;
		ans = std :: max(ans, dp[(t - v[i]) * 5 / 4] + h[i]);
	}

	printf("%d", ans);

	return 0;
}
