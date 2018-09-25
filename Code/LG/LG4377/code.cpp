/**************************
  * Writer : Leo101
  * Problem : Luogu P4377 [USACO18OPEN]Talent Show
  * Tags : 零一分数规划, 二分答案, Dp, 背包
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1010
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int w[_], v[_];
double s[_], Dp[_][_];

int main()
{
	File(code);
	int n = gi, m = gi;
	for (int i = 1; i <= n; i++) 
		w[i] = gi, v[i] = gi;
	double l = 0, r = 10000;
	while (r - l  > 1e-5) {
		double Mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) s[i] = v[i] - Mid * w[i];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) 
				Dp[i][j] = -1e18;
		Dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				Dp[i][j] = std::max(Dp[i][j], Dp[i - 1][j]);
				Dp[i][std::min(m, j + w[i])] = std::max(Dp[i][std::min(m, j + w[i])], Dp[i - 1][j] + s[i]);
			}
		if (Dp[n][m] >= 0) l = Mid;
		else r = Mid;
	}
	int Ans = l * 1000;
	printf("%d", Ans);
	return 0;
}
