/**************************
  * Writer : Leo101
  * Problem : Luogu UVA10559 方块消除 Blocks
  * Tags : 区间dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 201;
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

int dp[MAXN][MAXN][MAXN], num[MAXN], lenght[MAXN];

int main()
{
	_FILE(code);

	int T = gi;
	for (int x = 1; x <= T; x++) {
		memset(lenght, 0, sizeof(lenght));
		memset(dp, 0, sizeof(dp));

		int n = gi;
		for (int i = 1; i <= n; i++) num[i] = gi;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (num[i] == num[j]) lenght[i]++;
		for (int i = n; i >= 1; i--) 
			for (int j = i; j <= n; j++) {
				for (int k = i; k < j; k++) {
					if (num[k] != num[j]) continue;
					for (int l = 0; l <= lenght[j]; l++)
						dp[i][j][l] = std :: max(dp[i][j][l], dp[k + 1][j - 1][0] + dp[i][k][l + 1]);
				}
				for (int k = 0; k <= lenght[j]; k++)
					dp[i][j][k] = std :: max(dp[i][j][k], dp[i][j - 1][0] + (k + 1) * (k + 1));
			}

		printf("Case %d: %d\n" , x , dp[1][n][0]);
	}

	return 0;
}
