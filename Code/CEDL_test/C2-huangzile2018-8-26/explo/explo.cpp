#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100010
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

int Mod[_], Num[_];
double Dp[_];

int main()
{
	File(explo);
	int n = gi, t1 = gi, t2 = gi, w = gi;
	double k = 1 - t1 * 0.01, c = 1 + t2 * 0.01, Ans = -1;
	for (int i = 0; i < n; i++) Mod[i] = gi, Num[i] = gi;
	for (int i = 0; i <= n; i++) Dp[i] = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (Mod[i] == 1) {
			Dp[i] = std::max(Dp[i + 1], Dp[i + 1] * k + Num[i]);
		} else {
			Dp[i] = std::max(Dp[i + 1], Dp[i + 1] * c - Num[i]);
		}
		Ans = std::max(Ans, Dp[i]);
	}
	printf("%.2f", Ans * w);
	return 0;
}
