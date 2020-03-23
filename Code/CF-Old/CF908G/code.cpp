/**************************
  * Writer : Leo101
  * Problem : CF908G New Year and Original Order
  * Tags : dp，数位dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define MOD 1000000007
const int MAXN = 800;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

char str[MAXN];
int f[MAXN][MAXN][10][2];

void add(int &a, int b)
{ a += b; if (a >= MOD) a-= MOD; }
int main()
{
	_FILE(code);

	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 0; i < 10; i++) f[0][0][i][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= i; j++)
	for (int k = 0; k < 10; k++)
	for (int l = 0; l < 2; l++) {
		int lim = l == 1 ? 9 : str[i] - '0';
		for (int p = 0; p <= lim; p++)
			add(f[i][j + (k <= p)][k][l | (p < lim)], f[i - 1][j][k][l]);
	}

	int ans = 0;
	for (int i = 1; i < 10; i++)
		for (int j = 1, v = 1; j <= n; j++, v = ((v * 10ll) + 1) % MOD)
			add(ans, (1ll * (f[n][j][i][0] + f[n][j][i][1]) * v) % MOD);

	printf("%d", ans);

	return 0;
}
