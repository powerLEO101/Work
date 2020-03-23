/**************************
  * Writer : Leo101
  * Problem : CF258D Little Elephant and Broken Sorting
  * Tags : dp，概率
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 1001;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int num[MAXN];
double dp[MAXN][MAXN];

int main()
{
	_FILE(code);

	int n = gi, m = gi;
	for (int i = 0; i < n; i++) num[i] = gi;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = num[i] > num[j];
	for (int j = 0; j < m; j++) {
		int x = gi - 1, y = gi - 1;
		for (int i = 0; i < n; i++) {
			if (i == x || i == y) continue;
			dp[i][x] = dp[i][y] = (dp[i][x] + dp[i][y]) / 2.0;
			dp[x][i] = dp[y][i] = 1.0 - dp[i][x];
		}
		dp[x][y] = dp[y][x] = 0.5;
	}

	double ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans += dp[i][j];
	printf("%.8f", ans);

	return 0;
}
