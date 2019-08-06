/**************************
 * Author : Leo101
 * Problem : Luogu3974 [TJOI2015]组合数学
 * Tags : dp, dilworth
 **************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 2000;
int get_int()
{
  int x = 0, y = 1; char ch = getchar();
  while (!isdigit(ch) && ch != '-')
    ch = getchar();
  if (ch == '-') y = -1, ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * y;
}

int dp[MAXN][MAXN], num[MAXN][MAXN];

int main()
{
  _FILE(code);

  int T = gi;
  while (T--) {
    int n = gi, m = gi;
    for (int i = 1; i <= n; i++)
      for (int j = m; j > 0; j--)
        num[i][j] = gi;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = std :: max(dp[i - 1][j - 1] + num[i][j], std :: max(dp[i - 1][j], dp[i][j - 1]));
      }
    }
    std :: cout << dp[n][m] << std :: endl;
  }

  return 0;
}
