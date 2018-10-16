/**************************
  * Writer : Leo101
  * Problem : LOJ #10149. 「一本通 5.1 例 3」凸多边形的划分
  * Tags : Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1001
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

__int128 Dp[_][_];
__int128 Num[_];

void print(__int128 x)
{
	if (x < 10) {
		printf("%c", x + '0');
		return ;
	}
	print(x / 10);
	printf("%c", x % 10 + '0');
}

int main()
{
	File(code);

	memset(Dp, 0x3f, sizeof(Dp));
	int n = gi;
	for (int i = 0; i < n; i++) Num[i] = gi, Dp[i][i + 1] = 0;
	
	for (int l = 2; l < n; l++)
		for (int i = 0; i < n - l; i++) {
			int j = i + l;
			for (int k = i + 1; k < j; k++) 
				Dp[i][j] = std::min(Dp[i][j], Dp[i][k] + Dp[k][j] + Num[i] * Num[j] * Num[k]);
		}

	print(Dp[0][n - 1]);

	return 0;
}
