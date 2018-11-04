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
const int MaxN = 101, MaxVal = 61;
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

int Num[MaxVal], Dp[MaxN][MaxVal];

int main()
{
	File(code);

	int n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		int Temp = 0;
		for (int j = 0; j < m; j++) {
			char Ch;
			std::cin >> Ch;
			if (Ch == 'H') Temp = Temp << 1 + 1;
			else Temp = Temp << 1;
		}
		Status[i] = Temp;
	}

	for (int i = 0; i < (1 << m); i++) {
		if ((i & (i << 1)) || (i & (i << 2))) continue;
		Dp[0][Len] = 1;
		Num[Len++] = i;
	}

	for (int i = 0; i < Len; i++) {
		int x = Num[i];
		for (int j = 0; j < Len; j++) {
			int y = Num[j];
			if (x & y) continue;
			Dp[1][i] += Dp[0][j];
		}
	}
	for (int i = 2; i < n; i++)
		for (int j = 0; j < Len; j++) {
			int x = Num[j];
			if ((x & Status[i]) != 0) continue;
			for (int k = 0; k < Len; k++) {
				int y = Num[k];
				if ((y & Status[i - 1]) != 0) continue;
				for (int l = 0; l < Len; l++) {
					int z = Num[l];
					if ((z & Status[i - 2]) != 0) continue;
					if (
				}
			}
		}

	return 0;
}
