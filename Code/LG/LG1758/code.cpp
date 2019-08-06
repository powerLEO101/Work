/**************************
  * Author : Leo101
  * Problem : Luogu1758 [NOI2009]管道取珠
  * Tags : dp
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define MOD 1024523
const int MAXN = 520;
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

char str1[MAXN], str2[MAXN];
int dp[2][MAXN][MAXN];

int main()
{
	_FILE(code);

	int n = gi, m = gi;
	std :: cin >> str1 + 1 >> str2 + 1;

	int status = 0;
  dp[0][0][0] = 1;
	for (register int i = 0; i <= n; ++i) {
    memset(dp[status ^ 1], 0, sizeof(dp[status ^ 1]));
		for (register int j = 0; j <= m; ++j) {
			for (register int k = 0; k <= i + j; ++k) {
				int l = i + j - k;
				if (str1[i + 1] == str1[k + 1]) 
					dp[status ^ 1][j][k + 1] = (dp[status ^ 1][j][k + 1] + dp[status][j][k]) % MOD;
        if (str1[i + 1] == str2[l + 1])
          dp[status ^ 1][j][k] = (dp[status ^ 1][j][k] + dp[status][j][k]) % MOD;
        if (str2[j + 1] == str1[k + 1])
          dp[status][j + 1][k + 1] = (dp[status][j + 1][k + 1] + dp[status][j][k]) % MOD;
        if (str2[j + 1] == str2[l + 1])
          dp[status][j + 1][k] = (dp[status][j + 1][k] + dp[status][j][k]) % MOD;
			}
		}
    status ^= 1;
	}

  std :: cout << dp[status ^ 1][m][n];

	return 0;
}
