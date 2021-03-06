/**************************
  * Writer : Leo101
  * Problem : LOJ #10174. 「一本通 5.4 练习 3」动物园
  * Tags : State Compress Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MaxN = 10001, MaxVal = 101;
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

int Ha[MaxN][MaxVal], Dp[MaxN][MaxVal];

int main()
{
	File(code);

	int n = gi, c = gi;
	for (int I = 0; I < c; I++) {
		int e = gi, F_Num = gi, L_Num = gi;
		int Fear = 0, Like = 0;
		for (int i = 0; i < F_Num; i++) {
			int x = gi;
			x = (x - e + n) % n;
			Fear |= (1 << x);
		}
		for (int i = 0; i < L_Num; i++) {
			int x = gi;
			x = (x - e + n) % n;
			Like |= (1 << x);
		}
		for (int i = 0; i < (1 << 5); i++)
			if ((~i & Fear) || (i & Like))
				Ha[e][i]++;
	}

	int Ans = -1;
	for (int T = 0; T < (1 << 5); T++) {
		memset(Dp[0], -63, sizeof(Dp[0]));
		Dp[0][T] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (1 << 5); j++) {
				Dp[i][j] = std::max(Dp[i - 1][(j & 15) << 1], Dp[i - 1][(j & 15) << 1 | 1]) + Ha[i][j];
			}
		}
		Ans = std::max(Ans, Dp[n][T]);
	}
	printf("%d", Ans);

	return 0;
}
