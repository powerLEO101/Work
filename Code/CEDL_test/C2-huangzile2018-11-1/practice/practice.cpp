/***************************
  * Writer : Leo101
  * Problem : T1 practice
  * Tags : 
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
#define _ 1001
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

long long a, b, k;
int Dp[_];

int Dfs(int Now)
{
	if (Now <= a) return Now == a ? 0 : INF;
	if (Dp[Now] != -1) return Dp[Now];
	Dp[Now] = INF;
	for (int i = 2; i <= k; i++)
		Dp[Now] = std::min(Dp[Now], Dfs(Now - (Now % i)));
	Dp[Now] = std::min(Dp[Now], Dfs(Now - 1)) + 1;
	return Dp[Now];
}

int main()
{
	File(practice);

	int T = gi;
	while (T--) {
		memset(Dp, -1, sizeof(Dp));
		b = gi, a = gi, k = gi;
		if (k == 2) std::cout << b - a;
		else printf("%d\n", Dfs(b));
	}

	return 0;
}

