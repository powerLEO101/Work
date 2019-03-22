/**************************
  * Writer : Leo101
  * Problem : ARC071D Infinite Sequence
  * Tags : Dp，递推
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 2e6, Mod = 1e9 + 7;
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

long long Dp[Max_N];

int main()
{
	File(code);

	int n = gi;
	long long Sum = 0;
	Dp[n] = n; Dp[n - 1] = 1ll * n * n % Mod;
	for (int i = n - 2; i > 0; i--) 
		Sum = (Sum + Dp[i + 3]) % Mod,
		Dp[i] = (Sum + i + 1 + Dp[i + 1] + 1ll * (n - 1) * (n - 1)) % Mod;
	printf("%lld", Dp[1]);

	return 0;
}
