/**************************
  * Writer : Leo101
  * Problem : AGC013D Piling Up
  * Tags : Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const long long Max_N = 5001, Mod = 1e9 + 7;
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

long long Dp[Max_N][Max_N];

long long Get_ans(int n, int m)
{
	memset(Dp, 0, sizeof(Dp));
	for (int i = 0; i <= n; i++) Dp[0][i] = 1;
	for (int i = 1; i <= m; i++) 
		for (int j = 0; j <= n; j++) {
			if (j != 0)
				Dp[i][j] = (Dp[i][j] + Dp[i - 1][j] + Dp[i - 1][j - 1]) % Mod;
			if (j != n)
				Dp[i][j] = (Dp[i][j] + Dp[i - 1][j] + Dp[i - 1][j + 1]) % Mod;
		}
	long long Ans = 0;
	for (int i = 0; i <= n; i++) Ans = (Ans + Dp[m][i]) % Mod;
	return Ans;
}

int main()
{
	File(code);

	int n = gi, m = gi;

	printf("%lld", (Get_ans(n, m) -  Get_ans(n - 1, m) + Mod) % Mod);

	return 0;
}
