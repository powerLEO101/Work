#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 2002
#define MOD 1000000007
#define INF 0x3f3f3f3f
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

int v[_], Dp[2][_], n, m, Ans;
bool Vis[_];

void Judge()
{
	int Now = m;
	for (int i = 0; i < n; i++)
		if (Vis[i] == 1) Now -= v[i];
	for (int i = 0; i < n; i++)
		if ((Now - v[i]) > 0) return;
	if (Now >= 0) {
		Ans++;
	}
}
void Get_ans(int Now)
{
	if (Now == n) {
		Judge();
		return;
	}
	Get_ans(Now + 1);
	Vis[Now] = true;
	Get_ans(Now + 1);
	Vis[Now] = false;
}

int main()
{
	File(gift);
	n = gi, m = gi;
	if(n==0) {
		printf("1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		v[i] = gi;
	}
	if (n <= 25) {
		Get_ans(0);
		printf("%d", Ans);
		return 0;
	}
	for (int i = 0; i < n; i++)
		Dp[0][i] = 1;
	int Type = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if ((j-v[i]) < 0) Dp[Type^1][j] = Dp[Type][j];
			else Dp[Type^1][j] = (Dp[Type][j]+Dp[Type][j-v[i]]) % MOD;
		}
		Type ^= 1;
	}
	printf("%d", Dp[0][m] % MOD);
	return 0;
}
