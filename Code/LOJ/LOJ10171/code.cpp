/**************************
  * Writer : Leo101
  * Problem : LOJ #10171. 「一本通 5.4 例 2」牧场的安排
  * Tags : State Compress Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define Mod 100000000
const int MaxN = 13, MaxVal = 8192;
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

int Num[MaxVal], Status[MaxN], Len;
long long Dp[MaxN][MaxVal];
char Temp[MaxN][MaxN];

int main()
{
	File(code);

	int n = gi, m = gi;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Temp[i][j] = gi;
	for (int i = 0; i < n; i++) {
		int Digit = 0;
		for (int j = 0; j < m; j++)
			Digit = (Digit << 1) + (Temp[i][j] ^ 1);
		Status[i] = Digit;
	}

	for (int i = 0; i < (1 << m); i++) {
		if ((i & (i << 1)) != 0) continue;
		if ((i & Status[0]) == 0) Dp[0][Len] = 1;
		Num[Len++] = i;
	}

	for (int i = 1; i < n; i++)
		for (int j = 0; j < Len; j++) {
			int x = Num[j];
			if ((x & Status[i]) != 0) continue;
			for (int k = 0; k < Len; k++) {
				int y = Num[k];
				if (x & y) continue;
				Dp[i][j] = (Dp[i][j] + Dp[i - 1][k]) % Mod;
			}
		}

	long long Ans = 0;
	for (int i = 0; i < Len; i++) Ans = (Ans + Dp[n - 1][i]) % Mod;
	printf("%lld", Ans);

	return 0;
}
