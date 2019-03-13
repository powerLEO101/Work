/**************************
  * Writer : Leo101
  * Problem : Luogu P2622 关灯问题II
  * Tags : dp, 装压
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 11, MAXM = 101;
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

int num[MAXM][MAXM], dp[1 << MAXN], n, m;

int changeStatus(int now, int index)
{
	for (int i = 0; i < n; i++) {
		if (num[index][i] == -1 && !(now & (1 << i))) now ^= (1 << i);
		if (num[index][i] == 1 && (now & (1 << i))) now ^= (1 << i);
	}
	return now;
}

int main()
{
	_FILE(code);

	n = gi, m = gi;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			num[i][j] = gi;

	memset(dp, 0x3f, sizeof(dp));	
	dp[(1 << n) - 1] = 0;
	for (int i = (1 << n) - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			int now = changeStatus(i, j);
			dp[now] = std :: min(dp[now], dp[i] + 1);
		}
	}

	if (dp[0] == 0x3f3f3f3f) printf("-1");
	else printf("%d", dp[0]);

	return 0;
}
