#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 10000005
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

int Num[_], Dp[_][20], Log[_];
int main()
{
	File(code);
	int n = gi, m = gi;
	for (int i = 0; i < n; i++)
		Num[i] = gi;
	Log[0] = -1;
	Dp[0][0] = Num[0];
	for (int i = 1; i <= n; i++) {
		Dp[i][0] = Num[i];
		Log[i] = Log[i >> 1] + 1;
	}
	for (int j = 1; j <= 20; j++)
		for (int i = 0; i + (1 << (j - 1)) < n; i++)
			Dp[i][j] = std::max(Dp[i][j - 1],\
					Dp[i + (1 << (j - 1))][j - 1]);
	while (m--) {
		int l = gi - 1, r = gi - 1;
		int Temp = Log[r - l + 1];
		printf("%d\n", std::max(Dp[l][Temp], Dp[r - (1 << Temp) + 1][Temp]));
	}
	return 0;
}
