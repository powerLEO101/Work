/**************************
  * Writer : Leo101
  * Problem : LOJ #10173. 「一本通 5.4 练习 2」炮兵阵地
  * Tags : State Compress Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MaxVal = 70, MaxN = 101;
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

int Len = 0, Num[MaxVal], Sum[MaxVal], Status[MaxN], Dp[MaxN][MaxVal][MaxVal];
int Get_Sum(int Val)
{
	int Ret = 0;
	while (Val != 0) {
		Ret += Val % 2;
		Val /= 2;
	}
	return Ret;
}

int main()
{
	File(code);

	int n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		int Tmp = 0;
		for (int j = 0; j < m; j++) {
			char Ch;
			std::cin >> Ch;
			if (Ch == 'H') Tmp = (Tmp << 1) + 1;
			else Tmp <<= 1;
		}
		Status[i] = Tmp;
	}

	for (int i = 0; i < (1 << m); i++) {
		if ((i & (i << 1)) || (i & (i << 2))) continue;
		Sum[Len] = Get_Sum(i);
		Num[Len++] = i;
	}

	for (int i = 0; i < Len; i++) {
		if (Status[0] & Num[i]) continue;
		Dp[0][i][0] = Sum[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < Len; j++) {
			int x = Num[j];
			if (x & Status[i]) continue;
			for (int k = 0; k < Len; k++) {
				int y = Num[k];
				if (x & y) continue;
				for (int l = 0; l < Len; l++) {
					int z = Num[l];
					if (x & z) continue;
					Dp[i][j][k] = std::max(Dp[i][j][k], Dp[i - 1][k][l] + Sum[j]);
				}
			}
		}
	}

	int Ans = 0;
	for (int i = 0; i < Len; i++)
		for (int j = 0; j < Len; j++)
			Ans = std::max(Ans, Dp[n - 1][i][j]);
	printf("%d", Ans);

	return 0;
}
