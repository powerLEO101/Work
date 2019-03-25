/**************************
  * Writer : Leo101
  * Problem : Luogu P4280 [AHOI2008]逆序对
  * Tags : dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define INF 0x3f3f3f3f
const int MAXN = 1e4 + 5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int sum1[MAXN][105], sum2[MAXN][105], rnk[MAXN], num[MAXN], minDp[MAXN][105], dp[MAXN][105];

int main()
{
	_FILE(code);

	int n = gi, k = gi, tot = 1;
	for (int i = 1; i <= n; i++) {
		num[i] = gi;
		if (num[i] == -1) rnk[tot++] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			sum1[i][j] = sum1[i - 1][j];
			if (num[i] > j) sum1[i][j]++;
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= k; j++) {
			sum2[i][j] = sum2[i + 1][j];
			if (num[i] != -1 && num[i] < j) sum2[i][j]++;
		}
	}

	for (int i = 1; i < tot; i++) {
		minDp[i][0] = INF;
		for (int j = 1; j <= k; j++) {
			dp[i][j] = minDp[i - 1][j] + sum1[rnk[i]][j] + sum2[rnk[i]][j];
			minDp[i][j] = std :: min(minDp[i][j - 1], dp[i][j]);
		}
	}

	int ans = minDp[tot - 1][k];
	for (int i = 1; i <= n; i++) {
		if (num[i] == -1) continue;
		ans += sum1[i][num[i]];
	}

	printf("%d", ans);

	return 0;
}
