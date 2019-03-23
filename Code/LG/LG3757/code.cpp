/**************************
  * Writer : Leo101
  * Problem : Luogu P3757 [CQOI2017]老C的键盘
  * Tags : 树型dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define MOD 1000000007
const int MAXN = 205;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n;
char type[MAXN];
int size[MAXN], dp[MAXN][MAXN], sum[MAXN][MAXN][2], num[MAXN][MAXN];
void dfs(int now = 1)
{
	int son1 = now << 1, son2 = (now << 1) + 1;
	if (son1 > n && son2 > n) {
		size[now] = 1;
		dp[now][1] = sum[now][1][0] = sum[now][1][1] = 1;
		return ;
	}
	if (son2 > n) {
		dfs(son1);
		size[now] = size[son1] + 1;
		for (int i = 1; i <= size[now]; i++) {
			if (type[son1] == '<') 
				dp[now][i] += (dp[now][i] + sum[son1][i][1]) % MOD;
			else 
				dp[now][i] += (dp[now][i] + sum[son1][i - 1][0]) % MOD;
		}
		for (int i = 1; i <= size[now]; i++)
			sum[now][i][0] = (sum[now][i - 1][0] + dp[now][i]) % MOD;
		for (int i = size[now]; i > 0; i--)
			sum[now][i][1] = (sum[now][i + 1][1] + dp[now][i]) % MOD;
		return ;
	}
	dfs(son1); dfs(son2);
	size[now] = size[son1] + size[son2] + 1;
	for (int i = 1; i <= size[now]; i++) {
		for (int j = 0; j < i && j <= size[son1]; j++) {
			int k = i - 1 - j, s1, s2;
			if (k > size[son2]) continue;
			if (type[son1] == '<') s1 = sum[son1][j + 1][1];
			else s1 = sum[son1][j][0];
			if (type[son2] == '<') s2 = sum[son2][k + 1][1];
			else s2 = sum[son2][k][0];
			dp[now][i] = (1ll * dp[now][i] + (((((1ll * s1 * s2) % MOD) * num[i - 1][j]) % MOD) * num[size[now] - i][size[son1] - j]) % MOD) % MOD;
		}
	}
	for (int i = 1; i <= size[now]; i++)
		sum[now][i][0] = (sum[now][i - 1][0] + dp[now][i]) % MOD;
	for (int i = size[now]; i > 0; i--)
		sum[now][i][1] = (sum[now][i + 1][1] + dp[now][i]) % MOD;
}

int main()
{
	_FILE(code);

	n = gi;
	scanf("%s", type + 2);

	num[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		num[i][0] = 1;
		for (int j = 1; j < i; j++)
			num[i][j] = (num[i - 1][j] + num[i - 1][j - 1]) % MOD;
		num[i][i] = 1;
	}
	dfs();

	printf("%d", sum[1][size[1]][0]);

	return 0;
}
